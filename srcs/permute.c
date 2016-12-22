/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:31:33 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 21:15:56 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		permute1(t_gene *gene1, int r1, int r2, char *strbegi)
{
	int			r;
	t_node		*nodetmp2;
	t_node		*nodetmp3;

	nodetmp3 = gene1->nodetmp;
//	printf("%s\n",(gene1->nodetmp)->name);
	r = r1;
	if (r1 == r2 && ft_strcmp(nodetmp3->name, strbegi) == 0)
		permute_p1(&(gene1->nodedata), nodetmp3);
	else
	{
		permute_p2(&nodetmp3, &r, &r1);
		nodetmp2 = nodetmp3;
		while (r <= r2)
		{
			ft_swap2(&(gene1->nodetmp), nodetmp2->name, nodetmp3->name);
			permute2(gene1, r1 + 1, r2, strbegi);
			ft_swap2(&(gene1->nodetmp), nodetmp2->name, nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
			r++;
		}
	}
}
void		permute2(t_gene *gene1, int r1, int r2, char *strbegi)
{
	int			r;
	t_node		*nodetmp2;
	t_node		*nodetmp3;

	nodetmp3 = gene1->nodetmp;
//	printf("%s\n",(gene1->nodetmp)->name);
	r = r1;
	if (r1 == r2 && ft_strcmp(nodetmp3->name, strbegi) == 0)
		permute_p1(&(gene1->nodedata), nodetmp3);
	else
	{
		permute_p2(&nodetmp3, &r, &r1);
		nodetmp2 = nodetmp3;
		while (r <= r2)
		{
			ft_swap2(&(gene1->nodetmp), nodetmp2->name, nodetmp3->name);
			permute2(gene1, r1 + 1, r2, strbegi);
			ft_swap2(&(gene1->nodetmp), nodetmp2->name, nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
			r++;
		}
	}
}

void		permute_p1(t_node **nodedata, t_node *nodetmp3)
{
	*nodedata = lst_add_downlrnew(nodedata, nodetmp3->name);
	nodetmp3 = nodetmp3->nextl;
	while (nodetmp3)
	{
		*nodedata = lst_add_down_downr(nodedata, nodetmp3->name);
		nodetmp3 = nodetmp3->nextl;
	}
}

void		permute_p2(t_node **nodetmp3, int *r, int *r1)
{
	while (*r1 > 0)
	{
		*nodetmp3 = (*nodetmp3)->nextl;
		(*r1)--;
	}
	*r1 = *r;
}
