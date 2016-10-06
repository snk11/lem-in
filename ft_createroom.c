/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:53:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 17:19:57 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*ft_createroom(t_room **rooms,t_node *nodebest)
{
	t_node	*nodetmp;
	t_node	*nodetmp3;

	nodetmp = NULL;
	nodetmp = nodebest;
	while (nodetmp)
	{
		nodetmp3 = nodetmp;
		*rooms = lst_add_downlrnew_room(rooms,nodetmp->name);
		nodetmp = nodetmp->nextr;
		while(nodetmp)
		{
			*rooms = lst_add_down_downr_room(rooms,nodetmp->name);
			nodetmp = nodetmp->nextr;
		}
		nodetmp = nodetmp3;
		nodetmp = nodetmp->nextl;
	}
	return (*rooms);
}
