/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:55:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 12:26:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
void	ft_solv(t_node *node1,t_node  *noderef,char *strend,t_node **path1begi,char *strbegi,int *ind1)
{
	t_node	*nodetmp;
	int		ind2;

	printf("ref = %s\n",noderef->name);
	nodetmp = ft_cursref(node1,noderef);

	if (nodetmp)
		*path1begi = lst_add_down_downr(path1begi,nodetmp->name);

//	if((nodetmp->nextr && ft_strcmp((nodetmp->nextr)->name,strend) == 0 ) 
//		||(nodetmp->nextl && ft_strcmp((nodetmp->nextl)->name,strend) == 0 ))
//	{
//		printf("hh");
//	}
//	else
	{	
		if(nodetmp && nodetmp->nextr)
		{
//			printf("gg = %s\n",(nodetmp->nextr)->name);
			ft_solv(node1, (nodetmp->nextr),strend,path1begi,strbegi,ind1);
		}
		if (nodetmp && ft_cursref(node1,nodetmp->nextl))
			ft_solv(node1, ft_cursref(node1,nodetmp->nextl), strend,path1begi,strbegi,ind1);
	}
}


