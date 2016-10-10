/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:09:19 by syusof            #+#    #+#             */
/*   Updated: 2016/10/10 12:30:04 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	ft_checkzero(t_room *rooms)
{
	t_room	*nodetmp;
	t_room	*nodetmp3;
	
	nodetmp = NULL;
	nodetmp3 = NULL;
	nodetmp = rooms;
	while(nodetmp)
	{
		nodetmp3 = nodetmp;
		while(nodetmp)
		{
			if(nodetmp->client != 0)
				return (0);
			nodetmp = nodetmp->nextr;
		}
		nodetmp = nodetmp3;
		nodetmp = nodetmp->nextl;
	}
	return (1);
}
