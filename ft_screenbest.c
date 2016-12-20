/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenbest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:54:27 by syusof            #+#    #+#             */
/*   Updated: 2016/12/20 13:13:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



#include <stdio.h>
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend)
{
	int	min;
	int	 index;
	int r;
	int i;
	int		countdirect;
	int	iter;
	int		indirect;
	int nbelemnodedata;
	t_node	*nodetmp;
	t_node	*nodetmp3;
	t_node	*numberlist;

	numberlist = NULL;
	nodetmp = NULL;
	nodetmp3= NULL;
	min = 0;
	iter = 0;
	nbelemnodedata = 0;
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
		index = ft_getminpath(nodedata, numberlist, strend);
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
		iter++;
	}
	return (*nodebest);
}
/*
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend)
{
	t_scbest		scbest1;

	scbest1.nbelemnodedata = ft_countelem_lv1(nodedata);
	scbest1.nodetmp = nodedata;
	scbest1.nodetmp3 = scbest1.nodetmp;
	while(scbest1.iter < scbest1.nbelemnodedata)
	{
		scbest1.r = 0;
		scbest1.indirect = 0;
		scbest1.index = ft_getminpath(nodedata, scbest1.numberlist, strend);
		if (scbest1.index >= 0)
		{
			if(scbest1.iter == 0)
				scbest1.numberlist = lst_add_downlrnew(&(scbest1.numberlist),ft_itoa(scbest1.index));
			else
				scbest1.numberlist = lst_add_downl(&(scbest1.numberlist),ft_itoa(scbest1.index));
			scbest1.i = scbest1.index;
			scbest1.nodetmp = nodedata;
			while (scbest1.nodetmp && scbest1.i > 0)
			{
				scbest1.nodetmp = scbest1.nodetmp->nextl;
				scbest1.i--;
			}
			scbest1.nodetmp3 = scbest1.nodetmp;
			if (ft_checkdirect(scbest1.nodetmp, strend))
			{
				scbest1.indirect = 1;
				scbest1.countdirect++;
			}
			if (scbest1.indirect == 0 || (scbest1.indirect == 1 && scbest1.countdirect <= 1))
			{
				while (scbest1.nodetmp && ft_strcmp(scbest1.nodetmp->name,strend) != 0 && scbest1.r == 0)
				{
					if(*nodebest && ft_checknode6(*nodebest,strend,scbest1.nodetmp->name) == 0)
						scbest1.r = 1;
					scbest1.nodetmp = scbest1.nodetmp->nextr;
				}
				scbest1.nodetmp = scbest1.nodetmp3;
				if(scbest1.r == 0)
				{
					*nodebest = lst_add_downlrnew(nodebest,scbest1.nodetmp->name);
					scbest1.nodetmp = scbest1.nodetmp->nextr;
					while(scbest1.nodetmp)
					{
						*nodebest = lst_add_down_downr(nodebest,scbest1.nodetmp->name);
						scbest1.nodetmp = scbest1.nodetmp->nextr;
					}
				}
			}
		}
		scbest1.iter++;
	}
	return (*nodebest);
}
*/
