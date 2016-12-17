/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 14:19:08 by syusof           ###   ########.fr       */
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
			ft_read_map_p3(line, &read1, node1, data1, map1);
		else
			ft_read_map_p4(line, &read1, node1, map1);
	}
	(data1)->nbant = read1.ant1;
	close(read1.fd);
	return (1);
}
