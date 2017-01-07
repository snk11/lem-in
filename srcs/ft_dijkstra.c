/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 05:42:09 by syusof            #+#    #+#             */
/*   Updated: 2017/01/07 16:04:54 by syusof           ###   ########.fr       */
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

	nodetmp5 = NULL;
	nodetmp3 = ft_cursref_first(nodeprime, strbegi);
	nodetmp3 = nodetmp3->nextr;
	while (nodetmp3)
	{
		nodetmp5 = lst_add_downl(&nodetmp5, nodetmp3->name);
		nodetmp3 = nodetmp3->nextr;
	}
	ft_sortpath(&nodetmp5);
	ft_printsol(nodetmp5);
	printf("--------\n");
	/*
	if (gene1->lv < gene1->nbelem)
		gene1->nodedata = lst_add_downl(&(gene1->nodedata), nodetmp3->name);
	nodetmp3 = nodetmp3->nextr;
*/
//	while (nodetmp5)
//	while(nodetmp5 && gene1->lv < gene1->nbelem)
	{
		ft_sortpath(&nodetmp5);
		nodetmp7 = nodetmp5;
		while (nodetmp5->nextr)
			nodetmp5 = nodetmp5->nextr;
		nodetmp3 = ft_cursref_first(nodeprime, nodetmp5->name);
		nodetmp3 = nodetmp3->nextr;
		nodetmp5 = nodetmp7;
		if (nodetmp3)
		{
			nodetmp5 = lst_add_downr(&nodetmp5, nodetmp5,nodetmp3->name);
		}
		while (nodetmp3->nextr)
		{
			nodetmp6 = nodetmp7;
			nodetmp3 = nodetmp3->nextr;
			nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
			while (nodetmp6->nextr->nextr)
			{
				nodetmp6 = nodetmp6->nextr;
				nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
			}
			nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
		}
		(gene1->lv)++;

	}
	ft_sortpath(&nodetmp5);
	ft_printsol(nodetmp5);
	printf("--------\n");
	{
		ft_sortpath(&nodetmp5);
		nodetmp7 = nodetmp5;
		while (nodetmp5->nextr)
			nodetmp5 = nodetmp5->nextr;
		nodetmp3 = ft_cursref_first(nodeprime, nodetmp5->name);
		nodetmp3 = nodetmp3->nextr;
		nodetmp5 = nodetmp7;
		if (nodetmp3)
		{
			nodetmp5 = lst_add_downr(&nodetmp5, nodetmp5,nodetmp3->name);
		}
		while (nodetmp3->nextr)
		{
			nodetmp6 = nodetmp7;
			nodetmp3 = nodetmp3->nextr;
			nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
			while (nodetmp6->nextr->nextr)
			{
				nodetmp6 = nodetmp6->nextr;
				nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
			}
			nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
		}
		(gene1->lv)++;

	}
	ft_sortpath(&nodetmp5);
	ft_printsol(nodetmp5);
	printf("--------\n");
	{
		ft_sortpath(&nodetmp5);
		nodetmp7 = nodetmp5;
		while (nodetmp5->nextr)
			nodetmp5 = nodetmp5->nextr;
		nodetmp3 = ft_cursref_first(nodeprime, nodetmp5->name);
		nodetmp3 = nodetmp3->nextr;
		nodetmp5 = nodetmp7;
		if (nodetmp3)
		{
			nodetmp5 = lst_add_downr(&nodetmp5, nodetmp5,nodetmp3->name);
		}
		while (nodetmp3->nextr)
		{
			nodetmp6 = nodetmp7;
			nodetmp3 = nodetmp3->nextr;
			nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
			while (nodetmp6->nextr->nextr)
			{
				nodetmp6 = nodetmp6->nextr;
				nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
			}
			nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
		}
		(gene1->lv)++;

	}
	ft_sortpath(&nodetmp5);
	ft_printsol(nodetmp5);
	printf("--------\n");
	{
		ft_sortpath(&nodetmp5);
		nodetmp7 = nodetmp5;
		while (nodetmp5->nextr)
			nodetmp5 = nodetmp5->nextr;
		nodetmp3 = ft_cursref_first(nodeprime, nodetmp5->name);
		nodetmp3 = nodetmp3->nextr;
		nodetmp5 = nodetmp7;
		if (nodetmp3)
		{
			nodetmp5 = lst_add_downr(&nodetmp5, nodetmp5,nodetmp3->name);
		}
		while (nodetmp3->nextr)
		{
			nodetmp6 = nodetmp7;
			nodetmp3 = nodetmp3->nextr;
			nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
			while (nodetmp6->nextr->nextr)
			{
				nodetmp6 = nodetmp6->nextr;
				nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
			}
			nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
		}
		(gene1->lv)++;

	}
	ft_sortpath(&nodetmp5);
	ft_printsol(nodetmp5);
	printf("--------\n");
//	ft_printsol(nodetmp5);

}