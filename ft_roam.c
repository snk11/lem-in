/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:25:16 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 17:54:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
void	ft_roam(t_node *node1,t_node  **processnodes,t_node **path1begi,char *strend,char *strbegi,int *ind1)
{
	int ind2;
	t_node	*nodetmp;
	t_node	*path1;
	int cnt;
	t_node	**nodeless;
	int continu;

	continu = 1;
	nodetmp = NULL;
	path1 = NULL;
	nodeless = NULL;
	ind2 = 0;
	cnt = 0;
	cnt = ft_countelem_lv1(node1);
	/*
	while(cnt > 0)
	{
	 	*nodeless = lst_add_downlrnew(nodeless,strbegi);
		nodetmp = node1;
		while(nodetmp)
		{
			*nodeless = lst_add_downl(nodeless,nodetmp->name);
			nodetmp = nodetmp->nextl;
		}
		cnt--;
	}
	*/
//	while(continu > 0)
//	{
//		while(*processnodes)
//			ft_roam2(node1,processnodes,path1begi,strend,strbegi,ind1);
//	}
}

void	ft_roam2(t_node *node1,t_node  **processnodes,t_node **path1begi,char *strend,char *strbegi,int *ind1)
{

	t_node *nodetmp;
	t_node	*path1;

	path1 = NULL;
	nodetmp = NULL;
	nodetmp = ft_cursref(node1,*processnodes);
	printf("nodetmp = %s\n",nodetmp->name);
	*processnodes = lst_rmtop(processnodes);
	if(nodetmp)
	{
		*path1begi = lst_add_downlrnew(path1begi,strbegi);
	}
	if(*path1begi)
	{
		path1 = *path1begi;
		while (path1->nextl)
			path1 = path1->nextl;
	}
	if(nodetmp)
	{
//		if(ft_strcmp(nodetmp->name,strend) != 0 && ft_checknode(path1,nodetmp->name))
		if(ft_checknode(path1,nodetmp->name) && ft_checknode(ft_cursref_first(node1,*processnodes),nodetmp->name) == 0)
		{
			*processnodes = lst_add_downl(processnodes,nodetmp->name);
			*path1begi = lst_add_down_downr(path1begi,nodetmp->name);
		}
		nodetmp = nodetmp->nextr;
	}

}
