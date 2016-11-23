/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:54:27 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 16:59:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



#include <stdio.h>
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend)
{
	int	min;
	int cnt;
	int nb1;
	int	 index;
	int r;
	int i;
	int		countdirect;
	int	iter;
	int		indirect;
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
	iter = 0;
	nbelemnodedata = 0;
	cnt = 0;
	r = 0;
	nbelemnodedata = ft_countelem_lv1(nodedata);
	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	iter = 0;
	nodetmp = nodedata;
	nodetmp3 = nodetmp;
	countdirect = 0;
	while(iter < nbelemnodedata)
	{
		r = 0;
		indirect = 0;
		//		printf("mini = %d, minbesti = %d\n",min,minbest);
		index = ft_getminpath(nodedata, numberlist, strend);

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
			if (ft_checkdirect(nodetmp, strend))
			{
				indirect = 1;
				countdirect++;
			}
			if (indirect == 0 || (indirect == 1 && countdirect <= 1))
			{
				while (nodetmp && ft_strcmp(nodetmp->name,strend) != 0 && r == 0)
				{
					if(*nodebest && ft_checknode6(*nodebest,strend,nodetmp->name) == 0)
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
		}
		//		if (minbest < min)
		//			minbest = min;
		iter++;

	}
	return (*nodebest);
}
