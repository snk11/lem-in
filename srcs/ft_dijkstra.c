/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 05:42:09 by syusof            #+#    #+#             */
/*   Updated: 2017/01/14 18:43:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_dijkstra(t_node *nodeprime, t_gene *gene1, char *strbegi,
		char *strend)
{
	t_dij		*dij1;

	ft_init13(dij1);
	ft_dijkstra_p1(dij1, nodeprime, gene1, strbegi, strend);
	while (dij1->nodetmp5 && dij1->cnt < NB_SOL)
	{
		dij1->indend = 0;
		ft_sortpath(&(dij1->nodetmp5));
		dij1->nodetmp7 = dij1->nodetmp5;
		while (dij1->nodetmp5->nextr)
			dij1->nodetmp5 = dij1->nodetmp5->nextr;
		dij1->nodetmp3 = ft_cursref_first(nodeprime, dij1->nodetmp5->name);
		dij1->nodetmp3 = dij1->nodetmp3->nextr;
		dij1->nodetmp5 = dij1->nodetmp7;
		while (dij1->nodetmp3)
			ft_dijkstra_p2(dij1, gene1, strbegi, strend);
		ft_del_first(&(dij1->nodetmp5));
	}
}

void		ft_dijkstra_p1(t_dij *dij1, t_node *nodeprime, t_gene *gene1,
		char *strbegi, char *strend)
{
	dij1->nodetmp3 = ft_cursref_first(nodeprime, strbegi);
	dij1->nodetmp3 = dij1->nodetmp3->nextr;
	while (dij1->nodetmp3)
	{
		if (ft_strcmp(dij1->nodetmp3->name, strend) == 0)
		{
			ft_node_add_wholer(&(gene1->nodescreen), dij1->nodetmp3, strbegi);
			(dij1->cnt)++;
		}
		else
			dij1->nodetmp5 = lst_add_downl(&(dij1->nodetmp5),
					dij1->nodetmp3->name);
		dij1->nodetmp3 = dij1->nodetmp3->nextr;
	}
}


void		ft_dijkstra_p2(t_dij *dij1, t_gene *gene1,
		char *strbegi, char *strend)
{
	dij1->nodetmp6 = dij1->nodetmp7;
	dij1->nodetmp5 = lst_add_downl(&(dij1->nodetmp5), dij1->nodetmp6->name);
	while (dij1->nodetmp6 && dij1->nodetmp6->nextr)
	{
		dij1->nodetmp6 = dij1->nodetmp6->nextr;
		dij1->nodetmp5 = lst_add_down_downr(&(dij1->nodetmp5),
				dij1->nodetmp6->name);
	}
	if (ft_checkdouble_r(dij1->nodetmp5, dij1->nodetmp3->name) == 0)
		ft_del_last(&(dij1->nodetmp5));
	else
	{
		dij1->nodetmp5 = lst_add_down_downr(&(dij1->nodetmp5),
				dij1->nodetmp3->name);
		if (ft_strcmp(dij1->nodetmp3->name, strend) == 0)
		{
			ft_node_add_wholer(&(gene1->nodescreen), dij1->nodetmp5, strbegi);
			dij1->indend = 1;
			ft_del_last(&(dij1->nodetmp5));
			dij1->cnt++;
		}
		else if (ft_strcmp(dij1->nodetmp3->name, strbegi) == 0)
			ft_del_last(&(dij1->nodetmp5));
	}
	dij1->nodetmp3 = dij1->nodetmp3->nextr;
}
