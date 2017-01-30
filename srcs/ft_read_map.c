/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2017/01/30 14:26:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_read_map(t_dmain *dmain1, t_data *data1, t_map *map1)
{
	t_read	read1;

	ft_init4(&read1);
	read1.fd = 0;
	while (get_next_line(read1.fd, &(read1.line)) > 0 && read1.r1 == 0)
	{
		if (ft_checknbant(read1.line))
			ft_read_map_p1(&read1, map1);
		else if (ft_strcmp(read1.line, "##start") == 0)
			ft_read_map_p2(&read1, dmain1, data1, map1);
		else if (ft_strcmp(read1.line, "##end") == 0)
			ft_read_map_p3(&read1, dmain1, data1, map1);
		else if (read1.line && ft_strlen(read1.line) >= 2 && read1.line[0] == '#' && read1.line[1] == '#')
			;
		else
			ft_read_map_p4(&read1, dmain1, map1);
		free(read1.line);
		read1.line = NULL;
	}
	(data1)->nbant = read1.ant1;
	close(read1.fd);
	return (1);
}
