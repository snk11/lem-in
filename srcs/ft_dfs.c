/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:39:01 by syusof            #+#    #+#             */
/*   Updated: 2017/01/15 22:09:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_dfs(t_node *nodeprime, t_gene *gene1, char *strbegi,
		char *strend)
{
	t_node		*nodetmp3;
	t_node		*nodetmp4;

	nodetmp4 = NULL;
	nodetmp3 = ft_cursref_first(nodeprime, strbegi);
	if (gene1->lv < gene1->nbelem)
		gene1->nodedata = lst_add_downl(&(gene1->nodedata), nodetmp3->name);
	nodetmp3 = nodetmp3->nextr;
	while (nodetmp3)
	{
		if (gene1->lv < gene1->nbelem && ft_strcmp(nodetmp3->name, strend) != 0
				&& ft_checkdouble_l(gene1->nodedata, nodetmp3->name))
		{
			(gene1->lv)++;
			ft_dfs(nodeprime, gene1, nodetmp3->name, strend);
		}
		else
			ft_dfs_p1(&gene1, nodetmp3, nodetmp4);
		nodetmp3 = nodetmp3->nextr;
	}
	if (gene1->lv < gene1->nbelem)
		ft_dfs_p2(&gene1, nodetmp4);
	(gene1->lv)--;
}

void		ft_dfs_p1(t_gene **gene1, t_node *nodetmp3, t_node *nodetmp4)
{
	(*gene1)->nodedata = lst_add_downl(&((*gene1)->nodedata), nodetmp3->name);
	nodetmp4 = (*gene1)->nodedata;
	(*gene1)->nodescreen = lst_add_downl(&((*gene1)->nodescreen),
			nodetmp4->name);
	nodetmp4 = nodetmp4->nextl;
	while (nodetmp4)
	{
		(*gene1)->nodescreen = lst_add_down_downr(&((*gene1)->nodescreen),
				nodetmp4->name);
		nodetmp4 = nodetmp4->nextl;
	}
	nodetmp4 = (*gene1)->nodedata;
	while (nodetmp4 && nodetmp4->nextl && (nodetmp4->nextl)->nextl)
		nodetmp4 = nodetmp4->nextl;
	nodetmp4->nextl = NULL;
}

void		ft_dfs_p2(t_gene **gene1, t_node *nodetmp4)
{
	nodetmp4 = (*gene1)->nodedata;
	while (nodetmp4 && nodetmp4->nextl && (nodetmp4->nextl)->nextl)
		nodetmp4 = nodetmp4->nextl;
	nodetmp4->nextl = NULL;
}
