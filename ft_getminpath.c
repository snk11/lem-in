/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getminpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:05:33 by syusof            #+#    #+#             */
/*   Updated: 2016/12/21 14:11:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_getminpath(t_node *nodedata,t_node *numberlist, char *strend)
{
	t_minpath		minpath1;

	minpath1.nodetmp = nodedata;
	minpath1.nodetmp3 = minpath1.nodetmp;
	ft_init9(&minpath1);
	while(minpath1.nodetmp)
	{
		minpath1.nodetmp3 = minpath1.nodetmp;
		minpath1.cnt = 0;
		if (minpath1.nodetmp && ft_checknode5(numberlist,ft_itoa(minpath1.i)))
			ft_getminpath_p1(&minpath1, strend);
		minpath1.nodetmp = minpath1.nodetmp3;
		minpath1.nodetmp = minpath1.nodetmp->nextl;
		minpath1.i++;
	}
	return (minpath1.index);
}

void		ft_getminpath_p1(t_minpath *minpath1, char *strend)
{
			while(minpath1->nodetmp
					&& ft_strcmp((minpath1->nodetmp)->name,strend) != 0)
			{
				minpath1->cnt++;
				minpath1->nodetmp = (minpath1->nodetmp)->nextr;
			}
			if (minpath1->min == 0 || minpath1->cnt < minpath1->min)
			{
				minpath1->min = minpath1->cnt;
				minpath1->index = minpath1->i;
			}
}
