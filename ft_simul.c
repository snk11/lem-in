/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:54:58 by syusof            #+#    #+#             */
/*   Updated: 2016/12/15 16:27:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



#include<stdio.h>
void	ft_simul(t_node *nodebest,char *strbegi,char *strend,int totant)
{
	int	i;
	int	cnt;
	int	cnt2;
	int nbelem;
	int n;
	int nbtmp;
	int	r1;
	int	r2;
	t_node *node1;
	t_node *node2;
	t_room *nodetmp;
	t_room *nodetmp3;
	t_room *nodetmp4;
	t_room *nodetmp5;
	t_room	*rooms;
	t_lst	*lstop;
	char	*s1;

	node1 = NULL;
	node2 = NULL;
	s1 = NULL;
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
		node1 = NULL;
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
				while(nodetmp && nodetmp->nextr && nodetmp != nodetmp5 && ft_strcmp((nodetmp->nextr)->name,strend) != 0)
				{
					nodetmp4 = nodetmp;
					nodetmp = nodetmp->nextr;
				}
				if(nodetmp->nextr && ft_strcmp((nodetmp->nextr)->name, strend) == 0)
				{
					if (nodetmp->client != 0)
					{
//						printf("%s ",ft_makestring(nodetmp->client,strend));
						s1 = ft_makestring(nodetmp->client,strend);
						node1 = lst_add_down_downr(&node1,s1);
//						printf("L%d-%s ",nodetmp->client,strend);
						nodetmp->client = 0;
					}
					if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
					{
//						printf("%s ",ft_makestring(totant - nbtmp + 1,nodetmp->name));
						s1 = ft_makestring(totant - nbtmp + 1,nodetmp->name);
						node1 = lst_add_down_downr(&node1,s1);
//						printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
						nodetmp->client = totant - nbtmp + 1;
						nbtmp--;
					}
					else if(nodetmp != nodetmp3)
					{
						if (nodetmp4->client != 0)
						{
//							printf("%s ",ft_makestring(nodetmp4->client,nodetmp->name));
							s1 = ft_makestring(nodetmp4->client,nodetmp->name);
							node1 = lst_add_down_downr(&node1,s1);
//							printf("L%d-%s ",nodetmp4->client,nodetmp->name);
						}
						nodetmp->client = nodetmp4->client;
						nodetmp4->client = 0;
						nodetmp5 = nodetmp;
					}
					nodetmp5 = nodetmp4;
				}
				else if(nodetmp != nodetmp3)
				{
//					printf("%s ",ft_makestring(nodetmp4->client,nodetmp->name));
					s1 = ft_makestring(nodetmp4->client,nodetmp->name);
					node1 = lst_add_down_downr(&node1,s1);
//					printf("L%d-%s ",nodetmp4->client,nodetmp->name);
					nodetmp->client = nodetmp4->client;
					nodetmp4->client = 0;
					nodetmp5 = nodetmp;
				}
				else if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
				{
//					printf("%s ",ft_makestring(totant - nbtmp + 1,nodetmp->name));
					s1 = ft_makestring(totant - nbtmp + 1,nodetmp->name);
					node1 = lst_add_down_downr(&node1,s1);
//					printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
					nodetmp->client = totant - nbtmp + 1;
					nbtmp--;
				}
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}

		if (ft_checkzero(rooms) == 1)
			r1 = 1;
		printf("\n");
//		printf("nbtmp = %d\n",nbtmp);
		ft_sort(&node1);
		ft_addseries(&node2,node1);
	}
	ft_printfpath_room(rooms);
	ft_printsol(node2);
}
