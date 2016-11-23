/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdouble_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 19:21:24 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 11:53:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int		ft_checkdouble_r(t_node *node,char *s)
{
	while(node)
	{
		if(ft_strcmp(node->name,s) == 0)
			return (0);
		node = node->nextr;
	}
	return (1);
}
