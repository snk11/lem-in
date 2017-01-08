/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:19:07 by syusof            #+#    #+#             */
/*   Updated: 2017/01/08 12:38:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_del_last(t_node **node1)
{
	t_node		*nodetmp;
	t_node		*nodetmp2;

	nodetmp = *node1;
	if (nodetmp)
	{
		nodetmp2 = nodetmp;
		nodetmp = nodetmp->nextl;
		while (nodetmp && nodetmp->nextl)
		{
			nodetmp2 = nodetmp;
			nodetmp = nodetmp->nextl;
		}
		if (nodetmp)
		{
			free(nodetmp);
			nodetmp = NULL;
			if(nodetmp2)
				nodetmp2->nextl = NULL;
		}
		else
		{
			free(nodetmp2);
			nodetmp2 = NULL;
		}
	}
}
