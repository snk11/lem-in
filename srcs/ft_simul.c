/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:54:58 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 19:41:10 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_simul(t_node *nodebest, char *strend, int totant)
{
	t_simul		simul1;

	ft_init7(&simul1);
	simul1.rooms = ft_createroom(&(simul1.rooms), nodebest, strend);
	simul1.nbtmp = totant;
	simul1.nodetmp = simul1.rooms;
	while (simul1.r1 == 0)
	{
		simul1.nodetmp = simul1.rooms;
		simul1.node1 = NULL;
		ft_simul_p1(&simul1, strend, totant);
		if (ft_checkzero(simul1.rooms) == 1)
			simul1.r1 = 1;
		ft_sort(&(simul1.node1));
		ft_addseries(&simul1.node2, simul1.node1);
	}
	ft_printsol(simul1.node2);
}

void		ft_simul_p1(t_simul *simul1, char *strend, int totant)
{
	while (simul1->nodetmp)
	{
		simul1->nodetmp3 = simul1->nodetmp;
		ft_simul_p1_p0(simul1);
		while (simul1->nodetmp4 != NULL)
		{
			simul1->nodetmp = simul1->nodetmp3;
			simul1->nodetmp4 = NULL;
			ft_simul_p1_p42(simul1, strend);
			if (simul1->nodetmp->nextr
					&& ft_strcmp((simul1->nodetmp->nextr)->name, strend) == 0)
				ft_simul_p1_p1(simul1, strend, totant);
			else if (simul1->nodetmp != simul1->nodetmp3)
				ft_simul_p1_p2(simul1);
			else if (simul1->nbtmp > 0 && simul1->nodetmp == simul1->nodetmp3
					&& (simul1->nodetmp)->client == 0
					&& ft_checknewant(simul1->rooms,
						simul1->nodetmp3, simul1->nbtmp))
				ft_simul_p1_p3(simul1, totant);
		}
		simul1->nodetmp = simul1->nodetmp3;
		simul1->nodetmp = simul1->nodetmp->nextl;
	}
}

void		ft_simul_p1_p0(t_simul *simul1)
{
	while (simul1->nodetmp && simul1->nodetmp->nextr)
		simul1->nodetmp = simul1->nodetmp->nextr;
	simul1->nodetmp5 = simul1->nodetmp;
	simul1->nodetmp4 = simul1->nodetmp;
}

void		ft_simul_p1_p42(t_simul *simul1, char *strend)
{
	while (simul1->nodetmp && simul1->nodetmp->nextr
			&& simul1->nodetmp != simul1->nodetmp5
			&& ft_strcmp((simul1->nodetmp->nextr)->name, strend) != 0)
	{
		simul1->nodetmp4 = simul1->nodetmp;
		simul1->nodetmp = simul1->nodetmp->nextr;
	}
}
