/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:04:58 by syusof            #+#    #+#             */
/*   Updated: 2017/01/03 19:07:56 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_printroom(t_room *nodedummie)
{
	t_room *nodetmp;
	t_room *nodetmp1;
	nodetmp = nodedummie;
	while(nodetmp)
	{
		nodetmp1 = nodetmp;
		while (nodetmp)
		{
			printf("%s ,client = %d\n",nodetmp->name, nodetmp->client);
			nodetmp = nodetmp->nextr;
		}
		printf("\n");
		nodetmp = nodetmp1;
		nodetmp = nodetmp->nextl;
	}
}
