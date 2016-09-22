/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 15:58:59 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_proceed(t_node *node1, t_path *path1begi,t_path **path1,char *strbegi,char *strend)
{
	
	t_node		*nodetmp;

	path1 = NULL;
	nodetmp = node1;
	*path1 = ft_createlstpath(strbegi);
	path1begi = *path1;
	ft_search1(node1,strend,path1begi,path1);
}

void	ft_search1(t_node *node1,char *strend,t_path *path1begi,t_path **path1)
{
	t_node		*nodetmp;
	int	ind1;
	int	nbelem;
	t_path	pathtmp;

	ind1 = 0;
	nbelem = 0;

	nodetmp = node1;
	while(ft_strcmp(nodetmp->name,strend) != 0 && nodetmp)
	{
		while(ft_strcmp(nodetmp->name,strend) != 0 && nodetmp)
		{
			while(ft_strcmp(nodetmp->name,strend) != 0 && ind1 == 0 && nodetmp)
			{
				nodetmp = nodetmp->nextr;
				if(ft_checknode(*path1,nodetmp->name))
				{
					ind1 = 1;
					ft_makepath((*path1)->name,nodetmp->name);
					if(ft_strcmp(nodetmp->name,strend) == 0)
					{
						while (path1begi)
						{
							path1begi = path1begi->next;
							nbelem++;
						}
						if (nbelem > 1)
							*path1 = lst_add_down(*path1);
					}
					else
						ft_search1(node1,strend,path1begi,path1);
				}
			}
			nodetmp = nodetmp->nextl;
		}
	}
}

