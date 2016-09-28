/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/09/28 16:15:10 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"





#include <stdio.h>
void ft_proceed(t_node *node1,t_node **path1begi,char *strbegi,char *strend)
{
	
	t_node		*nodetmp;

	*path1begi = NULL;
	nodetmp = node1;
	*path1begi = ft_createnode(strbegi);
	ft_search1(node1,node1,strend,path1begi,0,strbegi);
}


void	ft_search1(t_node *node1,t_node *noderef,char *strend,t_node **path1begi,int nbelem,char *strbegi)
{
	int	ind1;
	int	ind2;
	int	nbelem1;
	t_node	*nodetmp;
	t_node	*path1;

	ind1 = 0;
	ind2 = 0;
	nbelem1 = nbelem;
	path1 = *path1begi;

	printf("search %s\n",noderef->name);
	nodetmp = node1;
	while (nodetmp && ind2 == 0)
	{
		if(ft_strcmp((nodetmp->name),(noderef->name)) == 0)
			ind2 = 1;
		else
			nodetmp = nodetmp->nextl;
	}
		if(nodetmp)
		{
//			while(nodetmp && ft_strcmp(nodetmp->name,strend) != 0 && ind1 == 0)
			while(nodetmp)
			{
				nodetmp = nodetmp->nextr;
				if(nodetmp)
				{
					if(ft_strcmp(strbegi,nodetmp->name) != 0)
						*path1begi = lst_add_downl(path1begi,strbegi);
				}
				path1 = *path1begi;
				while (path1->nextl)
					path1 = path1->nextl;
				if (nodetmp)
					printf("nodetmp evalued = %s\n",nodetmp->name);
				if(nodetmp && ft_checknode(*path1begi,nodetmp->name) == 1)
				{
					printf("gg\n");
//					ind1 = 1;
//					ft_makepath((*path1)->name,nodetmp->name);
					lst_add_downr(path1begi,path1,nodetmp->name);
					if(ft_strcmp(nodetmp->name,strend) == 0)
					{
//						while (path1begi)
//						{
//							path1begi = path1begi->nextl;
//							nbelem1++;
//						}
//						if (nbelem1 >= 1)
//						{
//							*path1begi = lst_add_downl(path1begi,strbegi);
//							ft_search1(node1,node1,strend,path1,path1begi,nbelem1,strbegi);
//							printf("create ldown ");
//						}
					}
					else
						ft_search1(node1,nodetmp,strend,path1begi,nbelem1,strbegi);
				}
			}
//			nodetmp = nodetmp->nextl;
		}
}

