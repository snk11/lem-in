/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknewant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:25:32 by syusof            #+#    #+#             */
/*   Updated: 2016/12/21 15:14:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int		ft_checknewant(t_room *room,t_room *node,int nbant)
{
	t_room	*nodetmp;
	int	i1;
	int	j1;

	i1 = 0;
	j1 = 0;
	nodetmp = NULL;
	nodetmp = room;
	while (nodetmp)
	{
		i1++;
		nodetmp = nodetmp->nextr;
	}
	nodetmp = room;
	while(nodetmp != node)
		nodetmp = nodetmp->nextl;
	while (nodetmp)
	{
		j1++;
		nodetmp = nodetmp->nextr;
	}
	if(i1 == j1 || (i1 < j1 && nbant  > j1))
		return (1);
	return (0);
}
