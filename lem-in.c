/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 17:24:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"

int main(int ac,char **av)
{
	t_node	*node1;
	t_node	*nodetmp;
	t_path	*path1begi;
	t_path	*path1;

	path1begi = NULL;
	path1 = NULL;
	nodetmp = node1;
	node1 = ft_createnode("0");
	node1 = lst_add_downl(&node1,"1");
	node1 = lst_add_downl(&node1,"2");
	node1 = lst_add_downl(&node1,"3");

	if(nodetmp)
	{
		lst_add_downr(&nodetmp,"1");
	}

	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		lst_add_downr(&nodetmp,"0");
		lst_add_downr(&nodetmp,"2");
	}

	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		lst_add_downr(&nodetmp,"1");
		lst_add_downr(&nodetmp,"3");
	}
	
	nodetmp = node1;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	nodetmp = nodetmp->nextl;
	if(nodetmp)
	{
		lst_add_downr(&nodetmp,"2");
	}

	ft_proceed(node1,path1begi,&path1,"0","3");
}

