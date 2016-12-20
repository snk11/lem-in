/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simul2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:47:44 by syusof            #+#    #+#             */
/*   Updated: 2016/12/20 15:48:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_simul_p1_p1(t_simul *simul1, char *strend, int totant)
{
	if (simul1->nodetmp->client != 0)
	{
		simul1->s1 = ft_makestring(simul1->nodetmp->client,strend);
		simul1->node1 = lst_add_down_downr(&(simul1->node1),simul1->s1);
		simul1->nodetmp->client = 0;
	}
	if(simul1->nbtmp > 0 && simul1->nodetmp == simul1->nodetmp3 && (simul1->nodetmp)->client == 0 && ft_checknewant(simul1->rooms,simul1->nodetmp3,simul1->nbtmp))
	{
		simul1->s1 = ft_makestring(totant - simul1->nbtmp + 1,simul1->nodetmp->name);
		simul1->node1 = lst_add_down_downr(&(simul1->node1),simul1->s1);
		simul1->nodetmp->client = totant - simul1->nbtmp + 1;
		simul1->nbtmp--;
	}
	else if(simul1->nodetmp != simul1->nodetmp3)
		ft_simul_p1_p1_p1(simul1);
	simul1->nodetmp5 = simul1->nodetmp4;
}

void		ft_simul_p1_p1_p1(t_simul *simul1)
{
	if (simul1->nodetmp4->client != 0)
	{
		simul1->s1 = ft_makestring(simul1->nodetmp4->client,simul1->nodetmp->name);
		simul1->node1 = lst_add_down_downr(&(simul1->node1),simul1->s1);
	}
	simul1->nodetmp->client = simul1->nodetmp4->client;
	simul1->nodetmp4->client = 0;
	simul1->nodetmp5 = simul1->nodetmp;
}

void		ft_simul_p1_p2(t_simul *simul1)
{
	simul1->s1 = ft_makestring((simul1->nodetmp4)->client,simul1->nodetmp->name);
	simul1->node1 = lst_add_down_downr(&(simul1->node1),simul1->s1);
	simul1->nodetmp->client = (simul1->nodetmp4)->client;
	simul1->nodetmp4->client = 0;
	simul1->nodetmp5 = simul1->nodetmp;
}

void		ft_simul_p1_p3(t_simul *simul1, int totant)
{
	simul1->s1 = ft_makestring(totant - simul1->nbtmp + 1,simul1->nodetmp->name);
	simul1->node1 = lst_add_down_downr(&(simul1->node1),simul1->s1);
	simul1->nodetmp->client = totant - simul1->nbtmp + 1;
	simul1->nbtmp--;
}

