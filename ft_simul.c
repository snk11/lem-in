/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:54:58 by syusof            #+#    #+#             */
/*   Updated: 2016/10/10 20:29:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



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
	t_room *nodetmp;
	t_room *nodetmp3;
	t_room *nodetmp4;
	t_room *nodetmp5;
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
	nodetmp5 = NULL;

	int cnt1;
	cnt1 = 0;
	r1 = 0;
	r2 = 0;
	rooms = ft_createroom(&rooms,nodebest,strend);
	nbtmp = totant;
	nodetmp = rooms;

	//	nodetmp->client = 1;
	//	printf("L%d-%s\n",nodetmp->client,nodetmp->name);
//	while(ft_checkzero(rooms) == 0 || r1 == 0)
	{
		nodetmp = rooms;
		while(nodetmp)
		{
			nodetmp3 = nodetmp;
			if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("ggg\n");
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			else
			{
				//			while(nodetmp && nodetmp->nextr && nodetmp->client != 0)
				r2 = 0;
				while (r2 == 0)
				{
					nodetmp = nodetmp3;
					r2 = 1;
					while(nodetmp && nodetmp->nextr)
					{
						nodetmp = nodetmp->nextr;
					}
					nodetmp5 = nodetmp;
					nodetmp = nodetmp3;
					while(nodetmp && nodetmp->nextr && nodetmp->client != 0 && nodetmp != nodetmp5)
					{
						nodetmp4 = nodetmp;
						nodetmp = nodetmp->nextr;
					}
					if(!(nodetmp->nextr) && nodetmp->client > 0)
					{
						printf("L%d-%s\n",nodetmp->client,strend);
						nodetmp->client = 0;
						r2 = 0;
					}
					else if(nodetmp->client == 0 && nodetmp4 != nodetmp)
					{
						printf("L%d-%s\n",nodetmp4->client,nodetmp->name);
						nodetmp->client = nodetmp4->client;
						nodetmp4->client = 0;
						nodetmp5 = nodetmp4;
						r2 = 0;
					}
				}
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}


		nodetmp = rooms;
		while(nodetmp)
		{
			nodetmp3 = nodetmp;
			if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			else
			{
				//			while(nodetmp && nodetmp->nextr && nodetmp->client != 0)
				r2 = 0;
				while (r2 == 0)
				{
					nodetmp = nodetmp3;
					r2 = 1;
					while(nodetmp && nodetmp->nextr)
					{
						nodetmp = nodetmp->nextr;
					}
					nodetmp5 = nodetmp;
					nodetmp = nodetmp3;
					while(nodetmp && nodetmp->nextr && nodetmp->client != 0 && nodetmp != nodetmp5)
					{
						nodetmp4 = nodetmp;
						nodetmp = nodetmp->nextr;
					}
					if(!(nodetmp->nextr) && nodetmp->client > 0)
					{
						printf("L%d-%s\n",nodetmp->client,strend);
						nodetmp->client = 0;
						r2 = 0;
					}
					else if(nodetmp->client == 0 && nodetmp4 != nodetmp)
					{
						printf("L%d-%s\n",nodetmp4->client,nodetmp->name);
						nodetmp->client = nodetmp4->client;
						nodetmp4->client = 0;
						nodetmp5 = nodetmp4;
						r2 = 0;
					}
				}
			}
			if(totant > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}


		nodetmp = rooms;
		while(nodetmp)
		{
			nodetmp3 = nodetmp;
			if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			else
			{
				//			while(nodetmp && nodetmp->nextr && nodetmp->client != 0)
				r2 = 0;
				while (r2 == 0)
				{
					nodetmp = nodetmp3;
					r2 = 1;
					while(nodetmp && nodetmp->nextr)
					{
						nodetmp = nodetmp->nextr;
					}
					nodetmp5 = nodetmp;
					nodetmp = nodetmp3;
					while(nodetmp && nodetmp->nextr && nodetmp->client != 0 && nodetmp != nodetmp5)
					{
						nodetmp4 = nodetmp;
						nodetmp = nodetmp->nextr;
					}
					if(!(nodetmp->nextr) && nodetmp->client > 0)
					{
						printf("L%d-%s\n",nodetmp->client,strend);
						nodetmp->client = 0;
						r2 = 0;
					}
					else if(nodetmp->client == 0 && nodetmp4 != nodetmp)
					{
						printf("L%d-%s\n",nodetmp4->client,nodetmp->name);
						nodetmp->client = nodetmp4->client;
						nodetmp4->client = 0;
						nodetmp5 = nodetmp4;
						r2 = 0;
					}
				}
			}
			if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}



		nodetmp = rooms;
		while(nodetmp)
		{
			nodetmp3 = nodetmp;
			if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			else
			{
				//			while(nodetmp && nodetmp->nextr && nodetmp->client != 0)
				r2 = 0;
				int cnt = 0;
				while (r2 == 0)
				{
					printf("cnt = %d\n",cnt);
					nodetmp = nodetmp3;
					r2 = 1;
					while(nodetmp && nodetmp->nextr)
					{
						nodetmp = nodetmp->nextr;
					}
					nodetmp5 = nodetmp;
					nodetmp = nodetmp3;
					while(nodetmp && nodetmp->nextr && nodetmp->client != 0 && nodetmp != nodetmp5 && ft_checkafter(nodetmp,nodetmp5))
					{
						nodetmp4 = nodetmp;
						nodetmp = nodetmp->nextr;
					}
					printf("ROOM = %s\n",nodetmp->name);
					if(!(nodetmp->nextr) && nodetmp->client > 0)
					{
						printf("OL%d-%s\n",nodetmp->client,strend);
						nodetmp->client = 0;
						r2 = 0;
					}
					else if(nodetmp->client == 0 && nodetmp4 != nodetmp)
					{
						printf("PL%d-%s\n",nodetmp4->client,nodetmp->name);
						nodetmp->client = nodetmp4->client;
						nodetmp4->client = 0;
						nodetmp5 = nodetmp4;
						r2 = 0;
					}
					cnt++;
				}
			}
			if(nbtmp > 0 && nodetmp == nodetmp3 && nodetmp->client == 0 && ft_checknewant(rooms,nodetmp3,nbtmp))
//			if(nbant && nodetmp == nodetmp3 && nodetmp->client == 0)
			{
				printf("L%d-%s\n",totant - nbtmp + 1,nodetmp->name);
				nodetmp->client = totant - nbtmp + 1;
				nbtmp--;
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}




		if (ft_checkzero(rooms) == 1)
			r1 = 1;
		printf("nbtmp = %d\n",nbtmp);
	}
	/*
	   nodetmp = rooms;
	   while(ft_checkzero(rooms) == 0)
	   {
	   nodetmp = rooms;
	   while(nodetmp)
	   {
	   nodetmp3 = nodetmp;
	   while(nodetmp && nodetmp->nextr && (nodetmp->client != 0 || nodetmp->nextr))
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
	   }
	   else if(nodetmp->client == 0 && nodetmp4 && nodetmp4->client != 0)
	   {
	   printf("L%d-%s\n",nodetmp4->client,nodetmp->name);
	   nodetmp->client = nodetmp4->client;
	   nodetmp4->client = 0;
	   }
	   nodetmp = nodetmp3;
	   nodetmp = nodetmp->nextl;
	   }
	   printf("nbtmp = %d\n",nbtmp);
	   }
	   */
	ft_printfpath_room(rooms);
}
