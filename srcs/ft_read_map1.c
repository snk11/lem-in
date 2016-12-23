/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:17:10 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 16:57:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_read_map_p1(t_read *read1)
{
	if (read1->r2 >= 1)
		read1->r1 = 1;
	else
	{
		read1->r2++;
		read1->ant1 = ft_atoi(read1->line);
	}
}

void		ft_read_map_p2(t_read *read1, t_node **node1, t_data *data1,
		t_map *map1)
{
	if (read1->r3 >= 1)
		read1->r1 = 1;
	else
	{
		get_next_line(read1->fd, &(read1->line));
		if (ft_checkroom(read1->line))
			ft_read_map_p2_p1(read1, node1, data1, map1);
		else
			read1->r1 = 1;
		read1->r3++;
	}
}

void		ft_read_map_p2_p1(t_read *read1, t_node **node1, t_data *data1,
		t_map *map1)
{
	if (ft_checkroom2(read1->line, node1) == 0)
		read1->r1 = 1;
	else
	{
		read1->i = 0;
		while ((read1->line)[read1->i] != ' ')
			read1->i++;
		read1->s1 = (char*)malloc(sizeof(char) * read1->i + 1);
		read1->i = 0;
		while ((read1->line)[read1->i] != ' ')
		{
			read1->s1[read1->i] = (read1->line)[read1->i];
			read1->i++;
		}
		read1->s1[read1->i] = 0;
		(data1)->strbegi = read1->s1;
		map1->nodestart = lst_add_downl(&(map1->nodestart), read1->line);
	}
}

void		ft_read_map_p3(t_read *read1, t_node **node1, t_data *data1,
		t_map *map1)
{
	if (read1->r4 >= 1)
		read1->r1 = 1;
	else
	{
		get_next_line(read1->fd, &(read1->line));
		if (ft_checkroom(read1->line))
			ft_read_map_p3_p1(read1, node1, data1, map1);
		else
			read1->r1 = 1;
		read1->r4++;
	}
}

void		ft_read_map_p3_p1(t_read *read1, t_node **node1, t_data *data1,
		t_map *map1)
{
	if (ft_checkroom2(read1->line, node1) == 0)
	{
		read1->r1 = 1;
	}
	read1->i = 0;
	while ((read1->line)[read1->i] != ' ')
		read1->i++;
	read1->s1 = (char*)malloc(sizeof(char) * read1->i + 1);
	read1->i = 0;
	while ((read1->line)[read1->i] != ' ')
	{
		read1->s1[read1->i] = (read1->line)[read1->i];
		read1->i++;
	}
	read1->s1[read1->i] = 0;
	(data1)->strend = read1->s1;
	map1->nodeend = lst_add_downl(&(map1->nodeend), read1->line);
}