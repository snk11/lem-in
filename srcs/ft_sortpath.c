/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 06:05:39 by syusof            #+#    #+#             */
/*   Updated: 2017/01/07 14:00:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_sortpath(t_node **node1)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	t_node	*nodetmp3;
	int		r;
	int		pos;

	ft_sortpath_p1(&nodetmp3, &r);
	nodetmp = *node1;
//	while (r == 1)
	{
		r = 0;
		nodetmp2 = nodetmp;
		pos = 0;
		if (nodetmp2)
			nodetmp3 = nodetmp2->nextl;
		while (nodetmp3)
		{
			pos++;
			if (ft_countelem_lvr(nodetmp3) < ft_countelem_lvr(nodetmp2))
			{
				ft_swappath(&nodetmp, pos);
				r = 1;
			}
			nodetmp2 = nodetmp2->nextl;
			nodetmp3 = nodetmp3->nextl;
		}
	}
	*node1 = nodetmp;
}

void	ft_sortpath_p1(t_node **nodetmp3, int *r)
{
	*nodetmp3 = NULL;
	*r = 1;
}


void	ft_sortpath_decreas(t_node **node1)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	t_node	*nodetmp3;
	int		r;
	int		pos;

	ft_sortpath_decreas_p1(&nodetmp3, &r);
	nodetmp = *node1;
	while (r == 1)
	{
		r = 0;
		nodetmp2 = nodetmp;
		pos = 0;
		if (nodetmp2)
			nodetmp3 = nodetmp2->nextl;
		while (nodetmp3)
		{
			if (ft_countelem_lvr(nodetmp3) > ft_countelem_lvr(nodetmp2))
			{
				ft_swappath(&nodetmp, pos);
				r = 1;
			}
			nodetmp2 = nodetmp2->nextl;
			nodetmp3 = nodetmp3->nextl;
		}
	}
	*node1 = nodetmp;
}

void	ft_sortpath_decreas_p1(t_node **nodetmp3, int *r)
{
	*nodetmp3 = NULL;
	*r = 1;
}
