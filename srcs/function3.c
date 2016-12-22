/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:04:07 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 18:13:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*lst_add_downr(t_node **node1, t_node *noderef, char *s)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	int		ind1;

	ind1 = 0;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createnode(s);
	if (!(nodetmp2))
		return (nodetmp);
	while (nodetmp2 && ind1 == 0)
	{
		if (ft_strcmp((nodetmp2)->name, (noderef)->name) == 0)
			ind1 = 1;
		else
			nodetmp2 = (nodetmp2)->nextl;
	}
	if (nodetmp2)
	{
		while ((nodetmp2)->nextr)
			nodetmp2 = (nodetmp2)->nextr;
		(nodetmp2)->nextr = nodetmp;
	}
	return (*node1);
}

t_node		*lst_add_down_downr(t_node **node1, char *s)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	int		ind1;

	ind1 = 0;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createnode(s);
	if (!(nodetmp2))
		return (nodetmp);
	while (nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	while ((nodetmp2)->nextr)
		nodetmp2 = (nodetmp2)->nextr;
	(nodetmp2)->nextr = nodetmp;
	return (*node1);
}
