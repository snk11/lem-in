/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simuldirect2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:33:33 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 17:49:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_simuldirect_p2_p0(t_simul *simul1)
{
	while (simul1->nodetmp && simul1->nodetmp->nextr)
		simul1->nodetmp = simul1->nodetmp->nextr;
	simul1->nodetmp5 = simul1->nodetmp;
	simul1->nodetmp4 = simul1->nodetmp;
}

void		ft_simuldirect_p2_p1(t_simul *simul1, char *strend)
{
	while (simul1->nodetmp && simul1->nodetmp->nextr
			&& simul1->nodetmp != simul1->nodetmp5
			&& ft_strcmp((simul1->nodetmp->nextr)->name, strend) != 0)
	{
		simul1->nodetmp4 = simul1->nodetmp;
		simul1->nodetmp = simul1->nodetmp->nextr;
	}
}

void		ft_simuldirect_p2_p2(t_simul *simul1, char *strend, int totant)
{
	if (simul1->nodetmp->client != 0)
	{
		simul1->s1 = ft_makestring(simul1->nodetmp->client, strend);
		simul1->node1 = lst_add_down_downr(&(simul1->node1), simul1->s1);
		simul1->nodetmp->client = 0;
	}
	if (simul1->nbtmp > 0 && simul1->nodetmp == simul1->nodetmp3
			&& simul1->nodetmp->client == 0
			&& ft_checknewant(simul1->rooms, simul1->nodetmp3, simul1->nbtmp))
	{
		simul1->s1 = ft_makestring(totant - simul1->nbtmp + 1,
				simul1->nodetmp->name);
		simul1->node1 = lst_add_down_downr(&(simul1->node1),
				simul1->s1);
		simul1->nodetmp->client = totant - simul1->nbtmp + 1;
		simul1->nbtmp--;
	}
	else if (simul1->nodetmp != simul1->nodetmp3)
	{
		simul1->nodetmp->client = simul1->nodetmp4->client;
		simul1->nodetmp4->client = 0;
		simul1->nodetmp5 = simul1->nodetmp;
	}
	simul1->nodetmp5 = simul1->nodetmp4;
}

void		ft_simuldirect_p2_p3(t_simul *simul1)
{
	simul1->s1 = ft_makestring(simul1->nodetmp4->client,
			simul1->nodetmp->name);
	simul1->node1 = lst_add_down_downr(&(simul1->node1), simul1->s1);
	simul1->nodetmp->client = simul1->nodetmp4->client;
	simul1->nodetmp4->client = 0;
	simul1->nodetmp5 = simul1->nodetmp;
}

void		ft_simuldirect_p2_p4(t_simul *simul1, int totant)
{
	simul1->s1 = ft_makestring(totant - simul1->nbtmp + 1,
			simul1->nodetmp->name);
	simul1->node1 = lst_add_down_downr(&(simul1->node1), simul1->s1);
	simul1->nodetmp->client = totant - simul1->nbtmp + 1;
	simul1->nbtmp--;
}