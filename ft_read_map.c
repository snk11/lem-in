/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/12/16 15:22:30 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



int	ft_read_map(t_node **node1,char *file,t_data *data1, t_map *map1)
{
	int		fd;
	char	*line;
	int		j;
	int		i;
	int		r1;
	int		r2;
	int		r3;
	int		r4;
	char	*strbegi;
	char	*strend;
	int		ant1;
	t_node	*node2;
	char	*s1;

	s1 = NULL;
	node2 = NULL;
	ant1 = 0;
	strbegi = NULL;
	strend = NULL;
	line = NULL;
	j = 0;
	i = 0;
	r1 = 0;
	r2 = 0;
	r3 = 0;
	r4 = 0;
	fd = 0;
	while (get_next_line(fd, &line) > 0 && r1 == 0)
	{
		if(ft_checknbant(line))
		{
			if(r2 >= 1)
				r1 = 1;
			else
			{
				r2++;
				ant1 = ft_atoi(line);
			}
		}
		else if(ft_strcmp(line,"##start") == 0)
		{
			if(r3 >= 1)
				r1 = 1;
			else
			{
				get_next_line(fd,&line);
				if(ft_checkroom(line))
				{
//					*node1 = ft_add_node_l(node1,line);
					if (ft_checkroom2(line,node1,&node2) == 0)
					{
						r1 = 1;
//						*node1 = ft_remove_last_l(node1);
					}
					else
					{
						i = 0;
						while(line[i] != ' ')
							i++;
						strbegi = (char*)malloc(sizeof(char)*i+1);
						i = 0;
						while(line[i] != ' ')
						{
							strbegi[i] = line[i];
							i++;
						}
						strbegi[i] = 0;
//						printf("start = %s\n",strbegi);
						map1->nodestart = lst_add_downl(&(map1->nodestart), line);
					}
				}
				else
					r1 = 1;
				r3++;
			}
		}
		else if(ft_strcmp(line,"##end") == 0)
		{
			if(r4 >= 1)
				r1 = 1;
			else
			{
				get_next_line(fd,&line);
				if(ft_checkroom(line))
				{
//					*node1 = ft_add_node_l(node1,line);
					if (ft_checkroom2(line,node1,&node2) == 0)
					{
						r1 = 1;
//						*node1 = ft_remove_last_l(node1);
					}
					i = 0;
					while(line[i] != ' ')
						i++;
					strend = (char*)malloc(sizeof(char)*i+1);
					i = 0;
					while(line[i] != ' ')
					{
						strend[i] = line[i];
						i++;
					}
					strend[i] = 0;
//					printf("end = %s\n",strend);
					map1->nodeend = lst_add_downl(&(map1->nodeend), line);
				}
				else
					r1 = 1;
				r4++;
			}
		}
		else if(ft_checkroom(line))
		{
//			*node1 = ft_add_node_l(node1,line);
			if (ft_checkroom2(line,node1,&node2) == 0)
			{
				r1 = 1;
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
			r1 = 1;
	}
	//	close(fd);
	//	l1 = ft_returnvaline(file);

//	if (ant1 > 0)
		(data1)->nbant = ant1;
	if (strbegi)
		(data1)->strbegi = strbegi;
	if (strend)
		(data1)->strend = strend;
	close(fd);



	return (1);
}
