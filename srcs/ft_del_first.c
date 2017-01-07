/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:44:25 by syusof            #+#    #+#             */
/*   Updated: 2017/01/07 18:49:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_del_first(t_node **node1)
{
	t_node		*nodetmp2;

	nodetmp2 = *node1;
	if (nodetmp2)
	{
		*node1 = (*node1)->nextl;
		free(nodetmp2);
		nodetmp2 = NULL;
	}
}
