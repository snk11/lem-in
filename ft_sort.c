/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:27:03 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 17:52:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_sort(t_node **node1)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	t_node	*nodetmp3;
	int		r;

	ft_sort_p1(&nodetmp3, &r);
	nodetmp = *node1;
	while (r == 1)
	{
		r = 0;
		nodetmp2 = nodetmp;
		if (nodetmp2)
			nodetmp3 = nodetmp2->nextr;
		while (nodetmp3)
		{
			if (ft_strcmp(nodetmp2->name, nodetmp3->name) > 0)
			{
				ft_swap2r(&nodetmp, nodetmp2->name, nodetmp3->name);
				r = 1;
			}
			nodetmp2 = nodetmp2->nextr;
			nodetmp3 = nodetmp3->nextr;
		}
	}
	*node1 = nodetmp;
}

void	ft_sort_p1(t_node **nodetmp3, int *r)
{
	*nodetmp3 = NULL;
	*r = 1;
}
