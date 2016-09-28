/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/09/28 11:31:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"





#include <stdio.h>
void ft_proceed(t_node *node1, t_node *path1begi,t_node **path1,char *strbegi,char *strend)
{
	
	t_node		*nodetmp;

	*path1 = NULL;
	nodetmp = node1;
	*path1 = ft_createlstpath(strbegi);
	path1begi = *path1;
	ft_search1(node1,node1,strend,path1begi,path1);
}


void	ft_search1(t_node *node1,t_node *noderef,char *strend,t_node *path1begi,t_node **path1)
{
	int	ind1;
	int	ind2;
	int	nbelem;
	t_node	*nodetmp;

	ind1 = 0;
	ind2 = 0;
	nbelem = 0;

	nodetmp = node1;
	while (nodetmp && ind2 == 0)
	{
		if(ft_strcmp((nodetmp->name),(noderef->name)) == 0)
			ind2 = 1;
		else
			nodetmp = nodetmp->nextl;
	}
//		while(ft_strcmp(nodetmp->name,strend) != 0 && nodetmp)
		if(nodetmp)
		{
			while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0 && ind1 == 0)
			{
				if (nodetmp)
					printf("nodetmp = %s\n",nodetmp->name);
				nodetmp = nodetmp->nextr;
				if (nodetmp)
					printf("nodetmp = %s\n",nodetmp->name);
				if(nodetmp && ft_checknode(*path1,nodetmp->name) == 1)
				{
					ind1 = 1;
//					ft_makepath((*path1)->name,nodetmp->name);
					lst_add_downr(&path1begi,*path1,nodetmp->name);
					if(ft_strcmp(nodetmp->name,strend) == 0)
					{
						while (path1begi)
						{
							path1begi = path1begi->nextl;
							nbelem++;
						}
						if (nbelem > 1)
							*path1 = lst_add_downl(path1,nodetmp->name);
					}
					else
						ft_search1(node1,nodetmp,strend,path1begi,path1);
				}
			}
//			nodetmp = nodetmp->nextl;
		}
}

