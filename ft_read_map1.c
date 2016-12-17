/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:17:10 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 14:00:21 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_read_map_p1(char *line, t_read *read1)
{
	if(read1->r2 >= 1)
		read1->r1 = 1;
	else
	{
		read1->r2++;
		read1->ant1 = ft_atoi(line);
	}
}

void		ft_read_map_p2(char *line, t_read *read1, t_node **node1 , t_data *data1, t_map *map1)
{
	if(read1->r3 >= 1)
		read1->r1 = 1;
	else
	{
		get_next_line(read1->fd,&line);
		if(ft_checkroom(line))
			ft_read_map_p2_p1(line, read1, node1, data1, map1);
		else
			read1->r1 = 1;
		read1->r3++;
	}
}

void		ft_read_map_p2_p1(char *line, t_read *read1, t_node **node1, t_data *data1, t_map *map1)
{
	if (ft_checkroom2(line,node1) == 0)
		read1->r1 = 1;
	else
	{
		read1->i = 0;
		while(line[read1->i] != ' ')
			read1->i++;
		read1->s1 = (char*)malloc(sizeof(char)*read1->i+1);
		read1->i = 0;
		while(line[read1->i] != ' ')
		{
			read1->s1[read1->i] = line[read1->i];
			read1->i++;
		}
		read1->s1[read1->i] = 0;
		(data1)->strbegi = read1->s1;
		map1->nodestart = lst_add_downl(&(map1->nodestart), line);
	}
}

void		ft_read_map_p3(char *line, t_read *read1, t_node **node1, t_data *data1, t_map *map1)
{
	if(read1->r4 >= 1)
		read1->r1 = 1;
	else
	{
		get_next_line(read1->fd,&line);
		if(ft_checkroom(line))
			ft_read_map_p3_p1(line, read1, node1, data1, map1);
		else
			read1->r1 = 1;
		read1->r4++;
	}
}

void		ft_read_map_p3_p1(char *line, t_read *read1, t_node **node1, t_data *data1, t_map *map1)
{
			if (ft_checkroom2(line,node1) == 0)
			{
				read1->r1 = 1;
			}
			read1->i = 0;
			while(line[read1->i] != ' ')
				read1->i++;
			read1->s1 = (char*)malloc(sizeof(char)*read1->i+1);
			read1->i = 0;
			while(line[read1->i] != ' ')
			{
				read1->s1[read1->i] = line[read1->i];
				read1->i++;
			}
			read1->s1[read1->i] = 0;
			(data1)->strend = read1->s1;
			map1->nodeend = lst_add_downl(&(map1->nodeend), line);
}
