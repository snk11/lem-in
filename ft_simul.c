/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:54:58 by syusof            #+#    #+#             */
/*   Updated: 2016/10/09 13:44:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_simul(t_node *nodebest,char *strbegi,char *strend,int nbant)
{
	int	i;
	int	cnt;
	int	cnt2;
	int nbelem;
	int n;
	t_node *nodetmp;
	t_room	*rooms;

	rooms = NULL;
	n = 0;
	nbelem = 0;
	i = 0;
	cnt = 0;
	cnt2 = 0;
	nodetmp = NULL;
	nodetmp = nodebest;
	/*
	while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
	{
		cnt++;
		nodetmp = nodetmp->nextr;
	}
	cnt2 = cnt;
	nbelem = ft_countelem_lv1(nodebest);
	n = nbelem;
	while(nbant)
	{
		cnt = cnt2;
		n = nbelem;
		while(cnt > 0)
		{
			print
		}

	}
	*/
	rooms = ft_createroom(&rooms,nodebest,strend);
	ft_printfpath_room(rooms);

}
