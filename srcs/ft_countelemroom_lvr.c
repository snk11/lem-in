/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countelemroom_lvr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:11:35 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 19:15:04 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_countelemroom_lvr(t_room *room1)
{
	int		cnt;

	cnt = 0;
	while (room1)
	{
		room1 = room1->nextr;
		cnt++;
	}
	return (cnt);
}
