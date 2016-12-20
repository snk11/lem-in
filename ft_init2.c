/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:55:54 by syusof            #+#    #+#             */
/*   Updated: 2016/12/20 14:32:48 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init6(t_scbest *scbest1)
{
	scbest1->numberlist = NULL;
	scbest1->nodetmp = NULL;
	scbest1->nodetmp3= NULL;
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
