/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 05:42:09 by syusof            #+#    #+#             */
/*   Updated: 2017/01/09 13:57:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_dijkstra(t_node *nodeprime, t_gene *gene1, char *strbegi,
		char *strend)
{
	t_node		*nodetmp3;
	t_node		*nodetmp4;
	t_node		*nodetmp5;
	t_node		*nodetmp6;
	t_node		*nodetmp7;
	t_node		*nodetmp;
	t_node		*nodetmp2;
	int			indend;
	//	int			inddelfirst;
	int			cnt;

	cnt = 0;
	indend = 0;
	nodetmp2 = NULL;
	nodetmp5 = NULL;
	nodetmp3 = ft_cursref_first(nodeprime, strbegi);
	nodetmp3 = nodetmp3->nextr;
	while (nodetmp3)
	{
		if (ft_strcmp(nodetmp3->name, strend) == 0)
		{
			ft_node_add_wholer(&(gene1->nodescreen), nodetmp3, strbegi);
			cnt++;
		}
		else
			nodetmp5 = lst_add_downl(&nodetmp5, nodetmp3->name);
		nodetmp3 = nodetmp3->nextr;
	}
	ft_sortpath(&nodetmp5);
	ft_printsol(nodetmp5);
	printf("--------\n");

	//	while(nodetmp5 && indend == 0)
	while(nodetmp5 && cnt < 4)
	{
		indend = 0;
		ft_sortpath(&nodetmp5);
		nodetmp7 = nodetmp5;
		while (nodetmp5->nextr)
			nodetmp5 = nodetmp5->nextr;
		nodetmp3 = ft_cursref_first(nodeprime, nodetmp5->name);
		nodetmp3 = nodetmp3->nextr;
		nodetmp5 = nodetmp7;
		//		inddelfirst = 0;
		while (nodetmp3)
		{
			//				nodetmp5 = lst_add_downr(&nodetmp5, nodetmp5,nodetmp3->name);
			nodetmp6 = nodetmp7;
			//				nodetmp6 = nodetmp5;
			nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
			while (nodetmp6 && nodetmp6->nextr)
			{
				nodetmp6 = nodetmp6->nextr;
				nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
			}
			if (ft_checkdouble_r(nodetmp5,nodetmp3->name) == 0)
				ft_del_last(&nodetmp5);
			else
			{
				nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
				if (ft_strcmp(nodetmp3->name, strend) == 0)
				{
					ft_node_add_wholer(&(gene1->nodescreen), nodetmp5, strbegi);
					indend = 1;
					ft_del_last(&nodetmp5);
					cnt++;
				}
				else if (ft_strcmp(nodetmp3->name, strbegi) == 0)
					ft_del_last(&nodetmp5);
			}
			nodetmp3 = nodetmp3->nextr;
		}
		ft_del_first(&nodetmp5);
		ft_printsol(nodetmp5);
		printf("--------\n");
	}
}
