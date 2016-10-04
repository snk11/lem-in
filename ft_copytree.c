/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copytree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:13:39 by syusof            #+#    #+#             */
/*   Updated: 2016/10/04 16:40:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


t_node *ft_copytree(t_node *maintree,char *strbegi)
{
	t_node	*rtree;
	t_node	*nodetmp2;

	nodetmp2 = maintree;
	rtree = NULL;
	if(maintree == NULL)
	{
		rtree = lst_add_downl(&rtree,strbegi);
		return (rtree);
	}
	nodetmp2 = maintree;
	while(nodetmp2 && nodetmp2->nextl)
	{
		rtree = lst_add_downl(&rtree,nodetmp2->name);
		while(nodetmp2 && nodetmp2->nextr)
		{
			nodetmp2 = nodetmp2->nextr;
			rtree = lst_add_down_downr(&rtree,nodetmp2->name);
		}
		nodetmp2 = (nodetmp2)->nextl;
	}
	return (rtree);
}
