/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simuldirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:13:07 by syusof            #+#    #+#             */
/*   Updated: 2016/12/20 16:50:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"




#include<stdio.h>
void	ft_simuldirect(t_node *nodebest,char *strbegi,char *strend,int totant)
{
	t_simul		simul1;

	ft_init7(&simul1);
	simul1.rooms = ft_createroom(&(simul1.rooms),nodebest,strend);
	simul1.nbtmp = totant;
	simul1.nodetmp = simul1.rooms;
	while(simul1.r1 == 0)
	{
		simul1.nodetmp = simul1.rooms;
		simul1.node1 = NULL;
		while(simul1.nodetmp)
		{
			if(simul1.nodetmp && ft_countelemroom_lvr(simul1.nodetmp) == 1)
			{
				simul1.nodetmp3 = simul1.nodetmp;
				while(simul1.nodetmp && (simul1.nodetmp)->nextr)
					simul1.nodetmp = simul1.nodetmp->nextr;
				simul1.nodetmp5 = simul1.nodetmp;
				simul1.nodetmp4 = simul1.nodetmp;
				while(simul1.nodetmp4 != NULL)
				{
					simul1.nodetmp = simul1.nodetmp3;
					simul1.nodetmp4 = NULL;
					if(!(simul1.nodetmp)->nextr)
					{
						if ((simul1.nodetmp)->client != 0)
						{
							//						printf("RL%d-%s ",nodetmp->client,strend);
							simul1.nodetmp->client = 0;
						}
						if(simul1.nbtmp > 0 && simul1.nodetmp == simul1.nodetmp3 && simul1.nodetmp->client == 0 && ft_checknewant(simul1.rooms,simul1.nodetmp3,simul1.nbtmp))
						{
//							printf("%s ",ft_makestring(totant - nbtmp + 1,nodetmp->name));
							simul1.s1 = ft_makestring(totant - simul1.nbtmp + 1,simul1.nodetmp->name);
							simul1.node1 = lst_add_down_downr(&(simul1.node1),simul1.s1);
//							printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
							(simul1.nodetmp)->client = totant - simul1.nbtmp + 1;
							(simul1.nbtmp)--;
						}
						simul1.nodetmp5 = simul1.nodetmp4;
					}
					else if(simul1.nbtmp > 0 && simul1.nodetmp == simul1.nodetmp3 && simul1.nodetmp->client == 0 && ft_checknewant(simul1.rooms,simul1.nodetmp3,simul1.nbtmp))
						//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
					{
//						printf("%s ",ft_makestring(totant - nbtmp + 1,nodetmp->name));
						simul1.s1 = ft_makestring(totant - simul1.nbtmp + 1,simul1.nodetmp->name);
						simul1.node1 = lst_add_down_downr(&(simul1.node1),simul1.s1);
//						printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
						simul1.nodetmp->client = totant - simul1.nbtmp + 1;
						simul1.nbtmp--;
					}
				}
			}
			else if (simul1.nodetmp && ft_countelemroom_lvr(simul1.nodetmp) >= 1)
			{
				simul1.nodetmp3 = simul1.nodetmp;
				while(simul1.nodetmp && simul1.nodetmp->nextr)
					simul1.nodetmp = simul1.nodetmp->nextr;
				simul1.nodetmp5 = simul1.nodetmp;
				simul1.nodetmp4 = simul1.nodetmp;
				while(simul1.nodetmp4 != NULL)
				{
					simul1.nodetmp = simul1.nodetmp3;
					simul1.nodetmp4 = NULL;
					while(simul1.nodetmp && simul1.nodetmp->nextr && simul1.nodetmp != simul1.nodetmp5 && ft_strcmp((simul1.nodetmp->nextr)->name,strend) != 0)
					{
						simul1.nodetmp4 = simul1.nodetmp;
						simul1.nodetmp = simul1.nodetmp->nextr;
					}
					if(simul1.nodetmp->nextr && ft_strcmp((simul1.nodetmp->nextr)->name, strend) == 0)
					{
						if (simul1.nodetmp->client != 0)
						{
//							printf("%s ",ft_makestring(nodetmp->client,strend));
							simul1.s1 = ft_makestring(simul1.nodetmp->client, strend);
							simul1.node1 = lst_add_down_downr(&(simul1.node1),simul1.s1);
							/*
							t_node *ntmp1 = node1;
							while (ntmp1 && ntmp1->nextr)
								ntmp1 = ntmp1->nextr;
							if(ntmp1)
								printf("ntmp1 = %s\n",ntmp1->name);
							*/
//							printf("L%d-%s ",nodetmp->client,strend);
							simul1.nodetmp->client = 0;
						}
						if(simul1.nbtmp > 0 && simul1.nodetmp == simul1.nodetmp3 && simul1.nodetmp->client == 0 && ft_checknewant(simul1.rooms,simul1.nodetmp3,simul1.nbtmp))
						{
//							printf("%s ",ft_makestring(totant - nbtmp + 1,nodetmp->name));
							simul1.s1 = ft_makestring(totant - simul1.nbtmp + 1,simul1.nodetmp->name);
							simul1.node1 = lst_add_down_downr(&(simul1.node1),simul1.s1);
//							printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
							simul1.nodetmp->client = totant - simul1.nbtmp + 1;
							simul1.nbtmp--;
						}
						else if(simul1.nodetmp != simul1.nodetmp3)
						{
							//						if (nodetmp4->client != 0)
							//							printf("L%d-%s ",nodetmp4->client,nodetmp->name);
							simul1.nodetmp->client = simul1.nodetmp4->client;
							simul1.nodetmp4->client = 0;
							simul1.nodetmp5 = simul1.nodetmp;
						}
						simul1.nodetmp5 = simul1.nodetmp4;
					}
					else if(simul1.nodetmp != simul1.nodetmp3)
					{
//						printf("%s ",ft_makestring(nodetmp4->client, nodetmp->name));
						simul1.s1 = ft_makestring(simul1.nodetmp4->client,simul1.nodetmp->name);
						simul1.node1 = lst_add_down_downr(&(simul1.node1),simul1.s1);
//						printf("L%d-%s ",nodetmp4->client,nodetmp->name);
						simul1.nodetmp->client = simul1.nodetmp4->client;
						simul1.nodetmp4->client = 0;
						simul1.nodetmp5 = simul1.nodetmp;
					}
					else if(simul1.nbtmp > 0 && simul1.nodetmp == simul1.nodetmp3 && simul1.nodetmp->client == 0 && ft_checknewant(simul1.rooms,simul1.nodetmp3,simul1.nbtmp))
						//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
					{
//						printf("%s ",ft_makestring(totant - nbtmp + 1,nodetmp->name));
						simul1.s1 = ft_makestring(totant - simul1.nbtmp + 1,simul1.nodetmp->name);
						simul1.node1 = lst_add_down_downr(&(simul1.node1),simul1.s1);
//						printf("L%d-%s ",totant - nbtmp + 1,nodetmp->name);
						simul1.nodetmp->client = totant - simul1.nbtmp + 1;
						simul1.nbtmp--;
					}
				}
			}
			simul1.nodetmp = simul1.nodetmp3;
			simul1.nodetmp = simul1.nodetmp->nextl;
		}


		if (ft_checkzero(simul1.rooms) == 1)
			simul1.r1 = 1;
//		printf("\n");
		//		printf("nbtmp = %d\n",nbtmp);
		ft_sort(&simul1.node1);
		ft_addseries(&(simul1.node2),simul1.node1);
	}
//	ft_printfpath_room(rooms);
	ft_printsol(simul1.node2);
}
