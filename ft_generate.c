/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 14:40:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



#include <stdio.h>
t_node	*ft_generate(t_node *node1,char *strbegi)
{
	t_node	*nodetmp;
	t_node	*nodedata;
	int		nbelem;

	nodedata = NULL;
	nbelem = 0;
	nodetmp = ft_maketree2(node1,strbegi);


	nbelem = ft_countelem_lv1(nodetmp);
	permute2(&nodetmp,&nodedata,0,nbelem - 1,strbegi);
	return (nodedata);
}

void permute2(t_node **nodetmp, t_node **nodedata,int r1,int r2,char *strbegi)
{
	int	i;
	int	r;
	t_node *nodetmp2;
	t_node *nodetmp3;
	nodetmp3 = *nodetmp;

	r = r1;
	if (r1 == r2 && ft_strcmp(nodetmp3->name,strbegi) == 0)
	{
		*nodedata = lst_add_downlrnew(nodedata,nodetmp3->name);
		nodetmp3 = nodetmp3->nextl;
		while(nodetmp3)
		{
			*nodedata = lst_add_down_downr(nodedata,nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
		}
	}
	else
	{
		while(r1 > 0)
		{
			nodetmp3 = nodetmp3->nextl;
			r1--;
		}
		r1 = r;
		nodetmp2 = nodetmp3;
		while(r <= r2)
		{
			swap2(nodetmp,nodetmp2->name,nodetmp3->name);
			permute2(nodetmp,nodedata,r1 + 1,r2,strbegi);
			swap2(nodetmp,nodetmp2->name,nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
			r++;
		}
	}
}
