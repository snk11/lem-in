/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:54:27 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 17:25:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*ft_screenbest(t_node **nodebest, t_node *nodedata, char *strend)
{
	t_scbest		scbest1;

	ft_init6(&scbest1);
	scbest1.nbelemnodedata = ft_countelem_lv1(nodedata);
	scbest1.nodetmp = nodedata;
	scbest1.nodetmp3 = scbest1.nodetmp;
	while (scbest1.iter < scbest1.nbelemnodedata)
	{
		scbest1.r = 0;
		scbest1.indirect = 0;
		scbest1.index = ft_getminpath(nodedata, scbest1.numberlist, strend);
		if (scbest1.index >= 0)
			ft_screenbest_p1(&scbest1, &nodebest, nodedata, strend);
		scbest1.iter++;
	}
	return (*nodebest);
}

void		ft_screenbest_p1(t_scbest *scbest1, t_node ***nodebest,
		t_node *nodedata, char *strend)
{
	ft_screenbest_p1_p1(scbest1, nodedata, strend);
	if (scbest1->indirect == 0 || (scbest1->indirect == 1
				&& scbest1->countdirect <= 1))
	{
		ft_screenbest_p1_p2(scbest1, nodebest, strend);
		scbest1->nodetmp = scbest1->nodetmp3;
		if (scbest1->r == 0)
		{
			**nodebest = lst_add_downlrnew(*nodebest, scbest1->nodetmp->name);
			scbest1->nodetmp = scbest1->nodetmp->nextr;
			while (scbest1->nodetmp)
			{
				**nodebest = lst_add_down_downr(*nodebest,
						scbest1->nodetmp->name);
				scbest1->nodetmp = scbest1->nodetmp->nextr;
			}
		}
	}
}

void		ft_screenbest_p1_p1(t_scbest *scbest1, t_node *nodedata,
		char *strend)
{
	if (scbest1->iter == 0)
		scbest1->numberlist = lst_add_downlrnew(&(scbest1->numberlist),
				ft_itoa(scbest1->index));
	else
		scbest1->numberlist = lst_add_downl(&(scbest1->numberlist),
				ft_itoa(scbest1->index));
	scbest1->i = scbest1->index;
	scbest1->nodetmp = nodedata;
	while (scbest1->nodetmp && scbest1->i > 0)
	{
		scbest1->nodetmp = scbest1->nodetmp->nextl;
		scbest1->i--;
	}
	scbest1->nodetmp3 = scbest1->nodetmp;
	if (ft_checkdirect(scbest1->nodetmp, strend))
	{
		scbest1->indirect = 1;
		scbest1->countdirect++;
	}
}

void		ft_screenbest_p1_p2(t_scbest *scbest1, t_node ***nodebest,
		char *strend)
{
	while (scbest1->nodetmp
			&& ft_strcmp((scbest1->nodetmp)->name, strend) != 0
			&& scbest1->r == 0)
	{
		if (*nodebest
				&& ft_checknode6(**nodebest, strend,
					scbest1->nodetmp->name) == 0)
			scbest1->r = 1;
		scbest1->nodetmp = scbest1->nodetmp->nextr;
	}
}
