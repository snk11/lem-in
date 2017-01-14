/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:19:07 by syusof            #+#    #+#             */
/*   Updated: 2017/01/14 19:12:24 by syusof           ###   ########.fr       */
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
			ft_del_last_p1(&nodetmp);
			if (nodetmp2)
				nodetmp2->nextl = NULL;
		}
		else
			ft_del_last_p1(&nodetmp2);
	}
}

void		ft_del_last_p1(t_node **nodetmp)
{
	free(*nodetmp);
	*nodetmp = NULL;
}
