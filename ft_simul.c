/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:54:58 by syusof            #+#    #+#             */
/*   Updated: 2016/10/09 19:48:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include<stdio.h>
void	ft_simul(t_node *nodebest,char *strbegi,char *strend,int nbant)
{
	int	i;
	int	cnt;
	int	cnt2;
	int nbelem;
	int n;
	int nbtmp;
	t_room *nodetmp;
	t_room *nodetmp3;
	t_room *nodetmp4;
	t_room	*rooms;

	rooms = NULL;
	n = 0;
	nbtmp = 0;
	nbelem = 0;
	i = 0;
	cnt = 0;
	cnt2 = 0;
	nodetmp = NULL;
	nodetmp3 = NULL;
	nodetmp4 = NULL;
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
	int cnt1;
	cnt1 = 0;
	rooms = ft_createroom(&rooms,nodebest,strend);
	nbtmp = nbant;
	nodetmp = rooms;
	while(nbtmp > 0)
	{
		nodetmp = rooms;
		while(nodetmp && nbtmp > 0)
//		if(nodetmp && nodetmp->nextl && nbtmp > 0)
		{
			nodetmp3 = nodetmp;
			while(nodetmp && nodetmp->nextr && nodetmp->client != 0)
//			if(nodetmp && nodetmp->nextr && nodetmp->client != 0)
			{
				cnt1++;
				nodetmp4 = nodetmp;
				nodetmp = nodetmp->nextr;
			}
			if(!(nodetmp->nextr) && nodetmp->client > 0)
			{
				printf("L%d-%s\n",nodetmp->client,strend);
				nodetmp->client = 0;
			}
			else if(nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",nbant - nbtmp + 1,nodetmp->name);
				nodetmp->client = nbant - nbtmp + 1;
				nbtmp--;
			}
			else if(nodetmp->client == 0)
			{
				printf("L%d-%s\n",nodetmp4->client,nodetmp->name);
				nodetmp->client = nodetmp4->client;
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}
		printf("nbtmp = %d\n",nbtmp);
		ft_printfpath_room(rooms);
	}

}
