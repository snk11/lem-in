/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addseries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:55 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 14:51:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_addseries(t_node **node2, t_node *node1)
{
	if (node1)
	{
		*node2 = lst_add_downl(node2, node1->name);
		node1 = node1->nextr;
	}
	while (node1)
	{
		*node2 = lst_add_down_downr(node2, node1->name);
		node1 = node1->nextr;
	}
}
