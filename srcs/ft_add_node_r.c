/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:51:08 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 14:51:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_add_node_r(t_node **node1, char *line)
{
	t_checkt checkt1;

	ft_init10(&checkt1);
	ft_checktube2_p1(&checkt1, line);
	ft_checktube2_p2(&checkt1, line);
	if (ft_checkdouble_r(ft_cursref_first(*node1, checkt1.s1), checkt1.s2))
		*node1 = lst_add_downr(node1, ft_cursref_first(*node1, checkt1.s1),
				checkt1.s2);
	if (ft_checkdouble_r(ft_cursref_first(*node1, checkt1.s2), checkt1.s1))
		*node1 = lst_add_downr(node1, ft_cursref_first(*node1, checkt1.s2),
				checkt1.s1);
	return (*node1);
}
