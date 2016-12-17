/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:09:32 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 14:17:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_read_map_p4(char *line, t_read *read1, t_node **node1 , t_map *map1)
{
	if(ft_checkroom(line))
	{
		if (ft_checkroom2(line,node1) == 0)
			read1->r1 = 1;
		else
			map1->noderoom = lst_add_downl(&(map1->noderoom), line);
	}
	else if(ft_checktube2(line,*node1))
	{
		*node1 = ft_add_node_r(node1,line);
		map1->nodetube = lst_add_downl(&(map1->nodetube), line);
	}
	else if(line[0] == '#' && line[1] != '#')
		;
	else
		read1->r1 = 1;
}
