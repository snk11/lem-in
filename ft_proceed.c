/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 13:22:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_proceed(t_node *node1, t_lst2 *lstprime, t_lst2 *lstremain,char *strbegi,char *strend)
{
	
	t_path		*path1;
	t_node		*nodetmp;

	path1 = NULL;
	nodetmp = node1;
	path1 = ft_createlstpath(strbegi);
	while(ft_strcmp(nodetmp->name,strend) != 0)
	{
		while(ft_strcmp(nodetmp->name,strend) != 0)
		{
			nodetmp = nodetmp->nextl;
		}
	}
}
