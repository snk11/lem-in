/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 20:22:43 by syusof            #+#    #+#             */
/*   Updated: 2016/10/10 20:28:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

int		ft_checkafter(t_room *rooms,t_room *nodetmp5)
{
	t_room *nodetmp;

	nodetmp = rooms;
	while(nodetmp && nodetmp != nodetmp5)
	{
		if(nodetmp->client > 0)
			return (0);
		nodetmp = nodetmp->nextl;
	}
	return (1);
}
