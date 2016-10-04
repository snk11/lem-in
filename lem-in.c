/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/10/04 16:05:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"




#include <stdio.h>
/*
int main(int ac,char **av)
{
	t_node	*node1;
	t_node	*nodetmp;
	t_node	*path1begi;
	t_node	*path1;
	t_node	*path1ind;

	path1begi = NULL;
	path1 = NULL;
	path1ind = NULL;
	nodetmp = node1;
	node1 = ft_createnode("0");
	node1 = lst_add_downl(&node1,"1");
	node1 = lst_add_downl(&node1,"2");
	node1 = lst_add_downl(&node1,"3");

	nodetmp = node1;
	if(nodetmp)
	{
		printf("createR 1\n");
		node1 = lst_add_downr(&node1,nodetmp,"1");
	}

	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		printf("createR 0\n");
		lst_add_downr(&node1,nodetmp,"0");
		printf("createR 2\n");
		lst_add_downr(&node1,nodetmp,"2");
	}

	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		printf("createR 1\n");
		lst_add_downr(&node1,nodetmp,"1");
		printf("createR 3\n");
		lst_add_downr(&node1,nodetmp,"3");
	}
	
	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		printf("createR 2\n");
		lst_add_downr(&node1,nodetmp,"2");
	}

	ft_proceed(node1,&path1begi,"0","3");

	while(path1begi)
	{
		path1ind = path1begi;
		while (path1begi)
		{
			printf("path = %s\n",path1begi->name);
			path1begi = path1begi->nextr;
		}
		printf("\n");
		path1begi = path1ind;
		path1begi = path1begi->nextl;
	}
}
*/


int main(int ac,char **av)
{
	t_node	*node1;
	t_node	*nodetmp;
	t_node	*path1begi;
	t_node	*path1;
	t_node	*path1ind;

	path1begi = NULL;
	path1 = NULL;
	path1ind = NULL;
	nodetmp = node1;
	node1 = ft_createnode("0");

	node1 = lst_add_downl(&node1,"1");
	node1 = lst_add_downl(&node1,"2");
	node1 = lst_add_downl(&node1,"3");

	nodetmp = node1;
	if(nodetmp)
	{
		node1 = lst_add_downr(&node1,nodetmp,"2");
		node1 = lst_add_downr(&node1,nodetmp,"3");
	}

	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		node1 = lst_add_downr(&node1,nodetmp,"2");
		node1 = lst_add_downr(&node1,nodetmp,"3");
	}

	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		node1 = lst_add_downr(&node1,nodetmp,"0");
		node1 = lst_add_downr(&node1,nodetmp,"1");
		node1 = lst_add_downr(&node1,nodetmp,"3");
	}
	
	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		node1 = lst_add_downr(&node1,nodetmp,"0");
		node1 = lst_add_downr(&node1,nodetmp,"1");
		node1 = lst_add_downr(&node1,nodetmp,"2");
	}

	ft_proceed(node1,&path1begi,"0","1");

	ft_printfpath(path1begi);
}

