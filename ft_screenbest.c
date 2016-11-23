/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:54:27 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 16:06:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



#include <stdio.h>
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend)
{
	int	min;
	int	minbest;
	int	minbest2;
	int cnt;
	int nb1;
	int ind1;
	int	 index;
	int r;
	int i;
	int	iter;
	int nbelemnodedata;
	t_node	*nodetmp;
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	t_node	*numberlist;

	numberlist = NULL;
	nodetmp = NULL;
	nodetmp3= NULL;
	nodetmp4= NULL;
	nb1 = 0;
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
	/*
	   while(nodetmp)
	   {
	   if(iter == 0)
	   numberlist = lst_add_downlrnew(&numberlist,ft_itoa(iter));
	   else
	   numberlist = lst_add_downl(&numberlist,ft_itoa(iter));
	   iter++;
	   nodetmp = nodetmp->nextl;
	   }
	   */
	iter = 0;
	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	while(iter < nbelemnodedata)
	{
//		printf("mini = %d, minbesti = %d\n",min,minbest);
		index = ft_getminpath(nodedata, numberlist, iter, minbest, strend);

			printf("index = %d\n",index);
//		printf("min = %d, minbest = %d\n",min,minbest);
		//		nodetmp = nodedata;
		if (index >= 0)
		{
			if(iter == 0)
				numberlist = lst_add_downlrnew(&numberlist,ft_itoa(index));
			else
				numberlist = lst_add_downl(&numberlist,ft_itoa(index));
			i = index;
			nodetmp = nodedata;
			while (nodetmp && i > 0)
			{
				nodetmp = nodetmp->nextl;
				i--;
			}
			nodetmp3 = nodetmp;
			while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0 && r == 0)
			{
				if(*nodebest && ft_checknode6(*nodebest,strend,nodetmp->name) == 0)
					r = 1;
				nodetmp = nodetmp->nextr;
			}
			printf("r = %d\n",r);
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
//		if (minbest < min)
//			minbest = min;
		iter++;


/*
		cnt = 0;
		ind1 = 0;
		i = 0;
		while(nodetmp && min > 0 && ind1 == 0)
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
					if(*nodebest && ft_checknode6(*nodebest,strend,nodetmp->name) == 0)
						r = 1;
					nodetmp = nodetmp->nextr;
				}
				printf("r = %d\n",r);
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
				ind1 = 1;
			}
			nodetmp = nodetmp3;
			nodetmp = nodetmp->nextl;
			i++;
		}
		if (minbest < min)
			minbest = min;
		iter++;
		*/
	}
	return (*nodebest);
}
