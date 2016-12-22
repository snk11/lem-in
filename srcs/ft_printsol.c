/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:13:50 by syusof            #+#    #+#             */
/*   Updated: 2016/12/15 16:28:30 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_printsol(t_node *node)
{
	t_node	*nodetmp;

	while (node)
	{
		nodetmp = node;
		ft_putstr(node->name);
		ft_putstr(" ");
		while (node)
		{
			node = node->nextr;
			if (node)
			{
				ft_putstr(node->name);
				ft_putstr(" ");
			}
		}
		ft_putstr("\n");
		node = nodetmp;
		node = node->nextl;
	}
}
