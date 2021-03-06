/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:07:44 by syusof            #+#    #+#             */
/*   Updated: 2017/01/07 12:04:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_swapr(t_node **nodetmp, char *s1, char *s2)
{
	t_swap		swap1;

	ft_init8(&swap1);
	ft_swapr_p1(&swap1, *nodetmp, s1, s2);
	if (swap1.cnt1 < swap1.cnt2)
		ft_swapr_p2(&swap1, &nodetmp, s1);
	else if (swap1.cnt1 > swap1.cnt2)
		ft_swapr_p3(&swap1, &nodetmp, s1);
}

void		ft_swapr_p1(t_swap *swap1, t_node *nodetmp, char *s1, char *s2)
{
	swap1->nodetmp3 = nodetmp;
	while (ft_strcmp((swap1->nodetmp3)->name, s1) != 0)
	{
		swap1->nodetmp3 = (swap1->nodetmp3)->nextr;
		swap1->cnt1++;
	}
	swap1->nodetmp4 = NULL;
	swap1->nodetmp4 = nodetmp;
	while (ft_strcmp((swap1->nodetmp4)->name, s2) != 0)
	{
		swap1->nodetmp4 = (swap1->nodetmp4)->nextr;
		swap1->cnt2++;
	}
	swap1->nodetmp5 = nodetmp;
}

void		ft_swapr_p2(t_swap *swap1, t_node ***nodetmp, char *s1)
{
	while (swap1->cnt1 - 1 > 0)
	{
		swap1->nodetmp5 = swap1->nodetmp5->nextr;
		swap1->cnt1--;
	}
	swap1->w = lst_add_downl(&(swap1->w), (swap1->nodetmp4)->name);
	swap1->w->nextr = swap1->nodetmp3->nextr;
	if (ft_strcmp((**nodetmp)->name, s1) != 0)
		swap1->nodetmp5->nextr = swap1->w;
	else
		**nodetmp = swap1->w;
	swap1->nodetmp5 = **nodetmp;
	while (swap1->cnt2 - 1 > 0)
	{
		swap1->nodetmp5 = (swap1->nodetmp5)->nextr;
		swap1->cnt2--;
	}
	swap1->z = lst_add_downl(&(swap1->z), (swap1->nodetmp3)->name);
	(swap1->z)->nextr = (swap1->nodetmp4)->nextr;
	(swap1->nodetmp5)->nextr = swap1->z;
}

void		ft_swapr_p3(t_swap *swap1, t_node ***nodetmp, char *s2)
{
	while (swap1->cnt2 - 1 > 0)
	{
		swap1->nodetmp5 = (swap1->nodetmp5)->nextr;
		swap1->cnt2--;
	}
	swap1->w = lst_add_downl(&(swap1->w), (swap1->nodetmp3)->name);
	(swap1->w)->nextr = swap1->nodetmp4->nextr;
	if (ft_strcmp((**nodetmp)->name, s2) != 0)
		(swap1->nodetmp5)->nextr = swap1->w;
	else
		**nodetmp = swap1->w;
	swap1->nodetmp5 = **nodetmp;
	while (swap1->cnt1 - 1 > 0)
	{
		swap1->nodetmp5 = (swap1->nodetmp5)->nextr;
		swap1->cnt1--;
	}
	swap1->z = lst_add_downl(&(swap1->z), (swap1->nodetmp4)->name);
	(swap1->z)->nextr = (swap1->nodetmp3)->nextr;
	(swap1->nodetmp5)->nextr = swap1->z;
}
