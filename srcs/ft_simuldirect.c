/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simuldirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:13:07 by syusof            #+#    #+#             */
/*   Updated: 2017/01/03 14:31:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_simuldirect(t_node *nodebest, char *strend, int totant)
{
	t_simul		simul1;

	ft_init7(&simul1);
	ft_simuldirect_p0(&simul1, nodebest, strend, totant);
	while (simul1.r1 == 0)
	{
		simul1.nodetmp = simul1.rooms;
		simul1.node1 = NULL;
		while (simul1.nodetmp)
		{
			if (simul1.nodetmp && ft_countelemroom_lvr(simul1.nodetmp) == 1)
				ft_simuldirect_p1(&simul1, totant);
			else if (simul1.nodetmp
					&& ft_countelemroom_lvr(simul1.nodetmp) >= 1)
				ft_simuldirect_p2(&simul1, strend, totant);
			simul1.nodetmp = simul1.nodetmp3;
			simul1.nodetmp = simul1.nodetmp->nextl;
		}
		if (ft_checkzero(simul1.rooms) == 1)
			simul1.r1 = 1;
		ft_sort(&simul1.node1);
		ft_addseries(&(simul1.node2), simul1.node1);
	}
	ft_printsol(simul1.node2);
}

void		ft_simuldirect_p0(t_simul *simul1, t_node *nodebest,
		char *strend, int totant)
{
	simul1->rooms = ft_createroom(&(simul1->rooms), nodebest, strend);
	simul1->nbtmp = totant;
	simul1->nodetmp = simul1->rooms;
}

void		ft_simuldirect_p1(t_simul *simul1, int totant)
{
	simul1->nodetmp3 = simul1->nodetmp;
	while (simul1->nodetmp && (simul1->nodetmp)->nextr)
		simul1->nodetmp = simul1->nodetmp->nextr;
	simul1->nodetmp5 = simul1->nodetmp;
	simul1->nodetmp4 = simul1->nodetmp;
	while (simul1->nodetmp4 != NULL)
	{
		simul1->nodetmp = simul1->nodetmp3;
		simul1->nodetmp4 = NULL;
		if (!(simul1->nodetmp)->nextr)
			ft_simuldirect_p1_p1(simul1, totant);
		else if (simul1->nbtmp > 0
				&& simul1->nodetmp == simul1->nodetmp3
				&& simul1->nodetmp->client == 0
				&& ft_checknewant(simul1->rooms, simul1->nodetmp3,
					simul1->nbtmp))
		{
			simul1->s1 = ft_makestring(totant - simul1->nbtmp + 1,
					simul1->nodetmp->name);
			simul1->node1 = lst_add_down_downr(&(simul1->node1), simul1->s1);
			simul1->nodetmp->client = totant - simul1->nbtmp + 1;
			simul1->nbtmp--;
		}
	}
}

void		ft_simuldirect_p1_p1(t_simul *simul1, int totant)
{
	if ((simul1->nodetmp)->client != 0)
	{
		simul1->nodetmp->client = 0;
	}
	if (simul1->nbtmp > 0
			&& simul1->nodetmp == simul1->nodetmp3
			&& simul1->nodetmp->client == 0
			&& ft_checknewant(simul1->rooms, simul1->nodetmp3, simul1->nbtmp))
	{
		simul1->s1 = ft_makestring(totant - simul1->nbtmp + 1,
				simul1->nodetmp->name);
		simul1->node1 = lst_add_down_downr(&(simul1->node1), simul1->s1);
		(simul1->nodetmp)->client = totant - simul1->nbtmp + 1;
		(simul1->nbtmp)--;
	}
	simul1->nodetmp5 = simul1->nodetmp4;
}

void		ft_simuldirect_p2(t_simul *simul1, char *strend, int totant)
{
	simul1->nodetmp3 = simul1->nodetmp;
	ft_simuldirect_p2_p0(simul1);
	while (simul1->nodetmp4 != NULL)
	{
		simul1->nodetmp = simul1->nodetmp3;
		simul1->nodetmp4 = NULL;
		ft_simuldirect_p2_p1(simul1, strend);
		if (simul1->nodetmp->nextr
				&& ft_strcmp((simul1->nodetmp->nextr)->name, strend) == 0)
			ft_simuldirect_p2_p2(simul1, strend, totant);
		else if (simul1->nodetmp != simul1->nodetmp3)
			ft_simuldirect_p2_p3(simul1);
		else if (simul1->nbtmp > 0
				&& simul1->nodetmp == simul1->nodetmp3
				&& simul1->nodetmp->client == 0
				&& ft_checknewant(simul1->rooms, simul1->nodetmp3,
					simul1->nbtmp))
			ft_simuldirect_p2_p4(simul1, totant);
	}
}
