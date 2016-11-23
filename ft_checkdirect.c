/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:30:00 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 16:33:41 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkdirect(t_node *node1, char *strend)
{
	if (node1 && node1->nextr && ft_strcmp((node1->nextr)->name,strend) == 0)
		return (1);
	return (0);
}
