/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursref.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:28:16 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 08:46:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_node *ft_cursref_first(t_node *node1,char *s)
{

	t_node	*nodetmp;
	int		ind2;

	ind2 = 0;
	nodetmp = node1;
	if (s)
	{
		while (nodetmp && ind2 == 0)
		{
			if(ft_strcmp((nodetmp->name),s) == 0)
				ind2 = 1;
			else
				nodetmp = nodetmp->nextl;
		}
	}
	else
		return (NULL);
	return (nodetmp);
}
t_node *ft_cursref(t_node *node1,t_node *noderef)
{

	t_node	*nodetmp;
	int		ind2;

	ind2 = 0;
	nodetmp = node1;
	if (noderef)
	{
		while (nodetmp && ind2 == 0)
		{
			if(ft_strcmp((nodetmp->name),noderef->name) == 0)
				ind2 = 1;
			else
				nodetmp = nodetmp->nextl;
		}
		if (nodetmp)
			nodetmp = nodetmp->nextr;
	}
	else
		return (NULL);
	return (nodetmp);
}
