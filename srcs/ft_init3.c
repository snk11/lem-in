/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:22:54 by syusof            #+#    #+#             */
/*   Updated: 2017/01/14 17:25:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init11(t_checkr *checkr1)
{
	checkr1->s1 = NULL;
	checkr1->s2 = NULL;
	checkr1->i = 0;
	checkr1->j = 0;
	checkr1->k = 0;
}

void		ft_init12(t_dmain *dmain1)
{
	dmain1->line = NULL;
	(dmain1->data1).nbant = 0;
	ft_init(&(dmain1->data1));
	ft_init2(&(dmain1->map1));
	dmain1->nodecoors = NULL;
	dmain1->node2 = NULL;
	dmain1->nodebest = NULL;
	dmain1->nodedata = NULL;
	dmain1->nodedummie = NULL;
}

void		ft_init13(t_dij *dij1)
{
	dij1->cnt = 0;
	dij1->indend = 0;
	dij1->nodetmp2 = NULL;
	dij1->nodetmp5 = NULL;
}
