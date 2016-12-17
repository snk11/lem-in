/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:17:10 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 12:30:19 by syusof           ###   ########.fr       */
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

void		ft_read_map_p2(char *line, t_read *read1, t_node **node1 , t_map *map1, t_data *data1)
{
	if(read1->r3 >= 1)
		read1->r1 = 1;
	else
	{
		get_next_line(read1->fd,&line);
		if(ft_checkroom(line))
		{
			//					*node1 = ft_add_node_l(node1,line);
			if (ft_checkroom2(line,node1) == 0)
			{
				read1->r1 = 1;
				//						*node1 = ft_remove_last_l(node1);
			}
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
				//						printf("start = %s\n",strbegi);
				map1->nodestart = lst_add_downl(&(map1->nodestart), line);
			}
		}
		else
			read1->r1 = 1;
		read1->r3++;
	}
}
