/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdouble_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 19:22:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/14 19:23:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem-in.h"

int		ft_checkdouble_l(t_node *node,char *s)
{
	while(node)
	{
		if(ft_strcmp(node->name,s) == 0)
			return (0);
		node = node->nextl;
	}
	return (1);
}
