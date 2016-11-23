/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getminpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:05:33 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 14:09:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_getminpath(t_node *nodedata, int minbest,char *strend)
{
	t_node		*nodetmp;
	t_node		*nodetmp3;
	int			min;
	int			cnt;

	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	min = 0;
	cnt = 0;
	while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
	{
		cnt++;
		nodetmp = nodetmp->nextr;
	}
	if(cnt > minbest)
		min = cnt;
	nodetmp = nodetmp3;
	nodetmp = nodetmp->nextl;
	while(nodetmp)
	{
		nodetmp3 = nodetmp;
		cnt = 0;
		while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
		{
			cnt++;
			nodetmp = nodetmp->nextr;
		}
		if(min == 0 && cnt > minbest)
			min = cnt;
		else if(cnt > minbest && cnt < min)
			min = cnt;
		nodetmp = nodetmp3;
		nodetmp = nodetmp->nextl;
	}
	return (min);
}
