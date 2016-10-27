/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 17:29:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"




#include <stdio.h>
int main(int ac,char **av)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*nodetmp;
	t_node	*path1begi;
	t_node	*path1;
	t_node	*path1ind;
	t_node	*processnodes;
	t_node	*lvnodes;
	t_node	*nodedata;
	t_node	*nodedummie;
	t_node	*nodebest;
	t_data	data1;

//	data1 = NULL;
	node2 = NULL;
	nodebest = NULL;
	nodedata = NULL;
	nodedummie = NULL;
	path1begi = NULL;
	path1 = NULL;
	path1ind = NULL;
	processnodes = NULL;
	lvnodes = NULL;


//	if (!(data1 = (t_data*)malloc(sizeof(t_data))))
//		return (0);
	data1.nbant = 0;



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

	//	ft_proceed(node1,&processnodes,&path1begi,"0","1");

	//	ft_printfpath(processnodes);
	//	ft_printfpath(path1begi);
	if (av[1])
		ft_read_map(&node2,av[1],&data1);

//	ft_printfpath(node2);

	if (ft_checkmindata(data1) == 0)
	{
		write(1,"ERROR",5);
		return (0);
	}


	nodedummie = ft_generate(node2,"0");
//	ft_printfpath(nodedummie);

	nodedata = ft_screen(&nodedata,nodedummie,node2,"0","1");
	if(nodedata == NULL)
	{
		write(1,"ERROR",5);
		return (0);
	}


	ft_printfpath(nodedata);
	nodebest = ft_screenbest(&nodebest,nodedata,"1");
//	ft_printfpath(nodebest);
//	ft_simul(nodebest,"0","1",3);

	//	char str[] = "0123";
	//	int n = strlen(str);
	//	permute(str, 0, n-1);
	//	return 0;
	//	ft_printfpath(node1);

	//	t_node *tree1;

	//	tree1 = ft_maketree(node1,"0");
}

