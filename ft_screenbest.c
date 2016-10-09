/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:54:27 by syusof            #+#    #+#             */
/*   Updated: 2016/10/09 13:28:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend)
{
	int	min;
	int	minbest;
	int	minbest2;
	int cnt;
	int r;
	int	iter;
	int nbelemnodedata;
	t_node	*nodetmp;
	t_node	*nodetmp3;

	nodetmp = NULL;
	nodetmp3= NULL;
	min = 0;
	minbest = 0;
	minbest2 = 0;
	iter = 0;
	nbelemnodedata = 0;
	cnt = 0;
	r = 0;
	nbelemnodedata = ft_countelem_lv1(nodedata);
	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	while(iter <= nbelemnodedata)
	{
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
			if(cnt > minbest && cnt < min)
					min = cnt;
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}
		nodetmp = nodedata;
		cnt = 0;
		while(nodetmp && min > 0 && cnt != min)
		{
			nodetmp3 = nodetmp;
			cnt = 0;
			while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
			{
				cnt++;
				nodetmp = nodetmp->nextr;
			}
			nodetmp = nodetmp3;
			if(cnt == min)
			{
				*nodebest = lst_add_downlrnew(nodebest,nodetmp->name);
				nodetmp = nodetmp->nextr;
				while(nodetmp)
				{
					*nodebest = lst_add_down_downr(nodebest,nodetmp->name);
					nodetmp = nodetmp->nextr;
				}
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}

		nodetmp = nodedata;
		cnt = 0;
		while(nodetmp && min > 0)
		{
			nodetmp3 = nodetmp;
			cnt = 0;
			r = 0;
			while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
			{
				cnt++;
				nodetmp = nodetmp->nextr;
			}
			nodetmp = nodetmp3;
			if(cnt == min)
			{
				while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0 && r == 0)
				{
					if(ft_checknode3(*nodebest,strend,nodetmp->name) == 0)
						r = 1;
					nodetmp = nodetmp->nextr;
				}
				nodetmp = nodetmp3;
				if(r == 0)
				{
					*nodebest = lst_add_downlrnew(nodebest,nodetmp->name);
					nodetmp = nodetmp->nextr;
					while(nodetmp)
					{
						*nodebest = lst_add_down_downr(nodebest,nodetmp->name);
						nodetmp = nodetmp->nextr;
					}
				}
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
		}
		if (minbest < min)
			minbest = min;
		iter++;
	}
	return (*nodebest);
}
