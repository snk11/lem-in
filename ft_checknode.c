/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:24:18 by syusof            #+#    #+#             */
/*   Updated: 2016/09/28 11:55:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"

int		ft_checknode(t_node *path1,char *s)
{
	int	r;

	r = 1;
	while (path1->nextr && r == 1)
	{
		path1 = path1->nextr;
		if (ft_strcmp(path1->name,s))
			r = 0;
	}
	return (r);
}
