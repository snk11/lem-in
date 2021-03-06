/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:55:54 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 15:22:21 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init6(t_scbest *scbest1)
{
	scbest1->numberlist = NULL;
	scbest1->nodetmp = NULL;
	scbest1->nodetmp3 = NULL;
	scbest1->min = 0;
	scbest1->iter = 0;
	scbest1->nbelemnodedata = 0;
	scbest1->r = 0;
	scbest1->iter = 0;
	scbest1->countdirect = 0;
}

void		ft_init7(t_simul *simul1)
{
	simul1->node1 = NULL;
	simul1->node2 = NULL;
	simul1->s1 = NULL;
	simul1->rooms = NULL;
	simul1->nbtmp = 0;
	simul1->nbelem = 0;
	simul1->nodetmp = NULL;
	simul1->nodetmp3 = NULL;
	simul1->nodetmp4 = NULL;
	simul1->nodetmp5 = NULL;
	simul1->cnt1 = 0;
	simul1->r1 = 0;
}

void		ft_init8(t_swap *swap1)
{
	swap1->cnt1 = 0;
	swap1->cnt2 = 0;
	swap1->w = NULL;
	swap1->z = NULL;
	swap1->nodetmp3 = NULL;
	swap1->nodetmp5 = NULL;
}

void		ft_init9(t_minpath *minpath1)
{
	minpath1->min = 0;
	minpath1->cnt = 0;
	minpath1->i = 0;
	minpath1->index = -1;
}

void		ft_init10(t_checkt *checkt1)
{
	checkt1->s1 = NULL;
	checkt1->s2 = NULL;
	checkt1->i = 0;
	checkt1->j = 0;
}
