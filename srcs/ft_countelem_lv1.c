/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countelem_lv1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:15:42 by syusof            #+#    #+#             */
/*   Updated: 2017/01/05 06:15:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_countelem_lv1(t_node *node1)
{
	t_node	*nodetmp2;
	int		cnt1;

	cnt1 = 0;
	nodetmp2 = node1;
	while (nodetmp2)
	{
		nodetmp2 = (nodetmp2)->nextl;
		cnt1++;
	}
	return (cnt1);
}
