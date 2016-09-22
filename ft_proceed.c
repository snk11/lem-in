/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 11:54:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_proceed(t_node_path *node, t_lst2 *lstprime, t_lst2 *lstremain,char *strbegi,char *strend)
{
	
	t_node_path		*path1;

	path1 = NULL;
	path1 = ft_createlst(strbegi);
	while(ft_strcmp(node->name,strend) != 0)
	{
		
	}
}
