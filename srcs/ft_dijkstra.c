/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 05:42:09 by syusof            #+#    #+#             */
/*   Updated: 2017/01/08 16:16:21 by syusof           ###   ########.fr       */
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
	int			inddelfirst;

	indend = 0;
	nodetmp2 = NULL;
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
	while(nodetmp5 && indend == 0)
	{
		ft_sortpath(&nodetmp5);
		nodetmp7 = nodetmp5;
		while (nodetmp5->nextr)
			nodetmp5 = nodetmp5->nextr;
		nodetmp3 = ft_cursref_first(nodeprime, nodetmp5->name);
		nodetmp3 = nodetmp3->nextr;
		nodetmp5 = nodetmp7;
		inddelfirst = 0;
		if (nodetmp3)
		{
			if (ft_countelem_lvr(nodetmp5) > gene1->nbelem - 1)
			{
				ft_del_first(&nodetmp5);
				inddelfirst = 1;
			}
			else
			{
				//				nodetmp5 = lst_add_downr(&nodetmp5, nodetmp5,nodetmp3->name);
				nodetmp6 = nodetmp5;
				nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
				while (nodetmp6 && nodetmp6->nextr)
				{
					nodetmp6 = nodetmp6->nextr;
					nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
				}
				if (ft_checkdouble_r(nodetmp5,nodetmp3->name) == 0)
					ft_del_last(&nodetmp5);
				else
					nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
				if (ft_strcmp(nodetmp3->name, strend) == 0)
					indend = 1;
				else if (ft_strcmp(nodetmp3->name, strbegi) == 0)
					ft_del_last(&nodetmp5);
			}
		}
		if (inddelfirst == 0)
		{
			while (nodetmp3->nextr && indend == 0)
			{
				nodetmp6 = nodetmp7;
				nodetmp3 = nodetmp3->nextr;
				nodetmp5 = lst_add_downl(&nodetmp5, nodetmp6->name);
				while (nodetmp6 && nodetmp6->nextr)
				{
					nodetmp6 = nodetmp6->nextr;
					nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp6->name);
				}
				if (ft_checkdouble_r(nodetmp5,nodetmp3->name) == 0)
					ft_del_last(&nodetmp5);
				else
					nodetmp5 = lst_add_down_downr(&nodetmp5, nodetmp3->name);
				if (ft_strcmp(nodetmp3->name, strend) == 0)
					indend = 1;
				else if (ft_strcmp(nodetmp3->name, strbegi) == 0)
					ft_del_last(&nodetmp5);
			}
			ft_del_first(&nodetmp5);
		}
		//			if(indend == 0)
		//				ft_sortpath(&nodetmp5);
		ft_printsol(nodetmp5);
		printf("--------\n");
	}
	nodetmp = nodetmp5;
	while (nodetmp && nodetmp->nextl)
		nodetmp = nodetmp->nextl;
	nodetmp2 = lst_add_downl(&nodetmp2, strbegi);
	while (nodetmp)
	{
		nodetmp2 = lst_add_down_downr(&nodetmp2, nodetmp->name);
		nodetmp = nodetmp->nextr;
	}
	gene1->nodescreen = nodetmp2;
	/*
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
*/

}
