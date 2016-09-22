/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 12:40:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"

int main(int ac,char **av)
{
	t_node_path	*node1;
	t_node_path	*nodetmp;

	nodetmp = node1;
	node1 = ft_createlst("1");
	lst_add_downl(&node1,"2");
	lst_add_downl(&node1,"3");
	lst_add_downl(&node1,"0");

	if(nodetmp)
	{
		lst_add_downr(&nodetmp,"0");
	}

	if(nodetmp)
	{
		nodetmp = nodetmp->nextl;
		lst_add_downr(&nodetmp,"0");
		lst_add_downr(&nodetmp,"3");
	}

	if(nodetmp)
	{
		nodetmp = nodetmp->nextl;
		lst_add_downr(&nodetmp,"2");
		lst_add_downr(&nodetmp,"1");
	}
	
	if(nodetmp)
	{
		nodetmp = nodetmp->nextl;
		lst_add_downr(&nodetmp,"1");
	}
}

