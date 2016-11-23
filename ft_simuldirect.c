/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simuldirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:13:07 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 18:09:49 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"




#include<stdio.h>
void	ft_simuldirect(t_node *nodebest,char *strbegi,char *strend,int totant)
{
	int	i;
	int	cnt;
	int	cnt2;
	int nbelem;
	int n;
	int nbtmp;
	int	r1;
	int	r2;
	t_room *nodetmp;
	t_room *nodetmp3;
	t_room *nodetmp4;
	t_room *nodetmp5;
	t_room	*rooms;
	t_lst	*lstop;

	lstop = NULL;
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
	nodetmp5 = NULL;

	int cnt1;
	cnt1 = 0;
	r1 = 0;
	r2 = 0;
	rooms = ft_createroom(&rooms,nodebest,strend);
	nbtmp = totant;
	nodetmp = rooms;
	r1 = 0;
	while(r1 == 0)
	{
		nodetmp = rooms;
		while(nodetmp)
		{
			nodetmp3 = nodetmp;
			while(nodetmp && nodetmp->nextr)
				nodetmp = nodetmp->nextr;
			nodetmp5 = nodetmp;
			nodetmp4 = nodetmp;
			while(nodetmp4 != NULL)
			{
				nodetmp = nodetmp3;
				nodetmp4 = NULL;
				while(nodetmp && nodetmp->nextr && nodetmp != nodetmp5)
				{
					nodetmp4 = nodetmp;
					nodetmp = nodetmp->nextr;
				}
				if(!(nodetmp->nextr))
				{
					if (nodetmp->client != 0)
					{
//						printf("RL%d-%s ",nodetmp->client,strend);
						nodetmp->client = 0;
					}
					if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
					{
						printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
						nodetmp->client = totant - nbtmp + 1;
						nbtmp--;
					}
					else if(nodetmp != nodetmp3)
					{
//						if (nodetmp4->client != 0)
//							printf("L%d-%s ",nodetmp4->client,nodetmp->name);
						nodetmp->client = nodetmp4->client;
						nodetmp4->client = 0;
						nodetmp5 = nodetmp;
					}
					nodetmp5 = nodetmp4;
				}
				else if(nodetmp != nodetmp3)
				{
					printf("L%d-%s ",nodetmp4->client,nodetmp->name);
					nodetmp->client = nodetmp4->client;
					nodetmp4->client = 0;
					nodetmp5 = nodetmp;
				}
				else if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
				{
					printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
					nodetmp->client = totant - nbtmp + 1;
					nbtmp--;
				}
				i++;
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}


		if (ft_checkzero(rooms) == 1)
			r1 = 1;
		printf("\n");
//		printf("nbtmp = %d\n",nbtmp);
	}
	ft_printfpath_room(rooms);
}
