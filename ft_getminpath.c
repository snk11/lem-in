/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getminpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:05:33 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 16:02:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_getminpath(t_node *nodedata,t_node *numberlist, int iter, int minbest,char *strend)
{
	t_node		*nodetmp;
	t_node		*nodetmp3;
	int			min;
	int			cnt;
	int			i;
	int			index;

	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	min = 0;
	cnt = 0;
	i = 0;
	index = -1;
	/*
	   while(nodetmp && ft_checknode5(nodedata,ft_itoa(i)) == 0 && ft_strcmp(nodetmp->name,strend) != 0)
	   {
	   cnt++;
	   nodetmp = nodetmp->nextr;
	   }
	   if(cnt > minbest)
	   min = cnt;
	   nodetmp = nodetmp3;
	   nodetmp = nodetmp->nextl;
	   */
	//	while(nodetmp)
	while(nodetmp)
	{
		nodetmp3 = nodetmp;
		cnt = 0;
		if (nodetmp && ft_checknode5(numberlist,ft_itoa(i)))
		{
			while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
			{
				cnt++;
				nodetmp = nodetmp->nextr;
			}
			if (min == 0)
			{
				min = cnt;
				index = i;
			}
			else if(cnt < min)
			{
				min = cnt;
				index = i;
			}
		}
		/*
		   if(min == 0 && cnt > minbest)
		   {
		   min = cnt;
		   index = i;
		   }
		   else if(cnt > minbest && cnt < min)
		   {
		   min = cnt;
		   index = i;
		   }
		   */
		nodetmp = nodetmp3;
		nodetmp = nodetmp->nextl;
		i++;
	}
	return (index);
}
