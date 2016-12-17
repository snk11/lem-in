/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 13:09:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



int	ft_read_map(t_node **node1,char *file,t_data *data1, t_map *map1)
{
	t_read	read1;
	char	*line;

	ft_init4(&read1);
	read1.fd = 0;
	while (get_next_line(read1.fd, &line) > 0 && read1.r1 == 0)
	{
		if(ft_checknbant(line))
			ft_read_map_p1(line, &read1);
		else if(ft_strcmp(line,"##start") == 0)
			ft_read_map_p2(line, &read1, node1, data1, map1);
		else if(ft_strcmp(line,"##end") == 0)
		{
			if(read1.r4 >= 1)
				read1.r1 = 1;
			else
			{
				get_next_line(read1.fd,&line);
				if(ft_checkroom(line))
				{
//					*node1 = ft_add_node_l(node1,line);
					if (ft_checkroom2(line,node1) == 0)
					{
						read1.r1 = 1;
//						*node1 = ft_remove_last_l(node1);
					}
					read1.i = 0;
					while(line[read1.i] != ' ')
						read1.i++;
					read1.s1 = (char*)malloc(sizeof(char)*read1.i+1);
					read1.i = 0;
					while(line[read1.i] != ' ')
					{
						read1.s1[read1.i] = line[read1.i];
						read1.i++;
					}
					read1.s1[read1.i] = 0;
					(data1)->strend = read1.s1;
//					printf("end = %s\n",strend);
					map1->nodeend = lst_add_downl(&(map1->nodeend), line);
				}
				else
					read1.r1 = 1;
				read1.r4++;
			}
		}
		else if(ft_checkroom(line))
		{
//			*node1 = ft_add_node_l(node1,line);
			if (ft_checkroom2(line,node1) == 0)
			{
				read1.r1 = 1;
//				ft_printfpath(*node1);
//				*node1 = ft_remove_last_l(node1);
//				ft_printfpath(*node1);
			}
			else
				map1->noderoom = lst_add_downl(&(map1->noderoom), line);

		}
		else if(ft_checktube2(line,*node1))
		{
			*node1 = ft_add_node_r(node1,line);
			map1->nodetube = lst_add_downl(&(map1->nodetube), line);
		}
		else if(line[0] == '#' && line[1] != '#')
		{
		}
		else
			read1.r1 = 1;
	}
	//	close(fd);
	//	l1 = ft_returnvaline(file);

	(data1)->nbant = read1.ant1;
	close(read1.fd);



	return (1);
}
