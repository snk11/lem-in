/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:54:27 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 12:11:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend)
{
	int	min;
	int cnt;
	int r;
	t_node	*nodetmp;
	t_node	*nodetmp3;

	nodetmp = NULL;
	nodetmp3= NULL;
	min = 0;
	cnt = 0;
	r = 0;
	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0)
	{
		cnt++;
		nodetmp = nodetmp->nextr;
	}
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
		if(cnt < min)
			min = cnt;
		nodetmp = nodetmp3;
		nodetmp = nodetmp->nextl;
	}

	nodetmp = nodedata;
	cnt = 0;
	while(nodetmp && cnt != min)
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
	while(nodetmp)
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
	return (*nodebest);
}
