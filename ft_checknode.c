/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:24:18 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 10:46:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"

int		ft_checknode3(t_node *node,char *strend,char *s)
{
	while (node->nextr)
	{
		node = node->nextr;
		if (ft_strcmp(node->name,strend) == 0)
			return (1);
		if (ft_strcmp(node->name,s) == 0)
			return (0);
	}
	return (1);
}

int		ft_checknode2(t_node *node,char *s)
{
	int	r;

	r = 0;
	while (node->nextr && r == 0)
	{
		node = node->nextr;
		if (ft_strcmp(node->name,s) == 0)
			r = 1;
	}
	return (r);
}

int		ft_checknode(t_node *path1,char *s)
{
	int	r;

	r = 1;
	if (ft_strcmp(path1->name,s) == 0)
		return (0);
	while (path1->nextr && r == 1)
	{
		path1 = path1->nextr;
		if (ft_strcmp(path1->name,s) == 0)
			r = 0;
	}
	return (r);
}
