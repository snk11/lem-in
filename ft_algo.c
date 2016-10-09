/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:22:00 by syusof            #+#    #+#             */
/*   Updated: 2016/10/09 19:20:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

t_room	*ft_algo(t_room **rooms,int cnt1)
{
	t_room	*nodetmp;
	t_room	*nodetmp3;

	nodetmp = NULL;
	nodetmp3 = NULL;
		while(nodetmp && nodetmp->nextl)
		{
			nodetmp3 = nodetmp;
			while(nodetmp && nodetmp->nextr)
			{
				cnt1++;
				nodetmp = nodetmp->nextr;
			}
			if(nodetmp->client > 0)
//				printf("L%d - %s",nodetmp->client,nodetmp->name);
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}

		return (*rooms);
}
