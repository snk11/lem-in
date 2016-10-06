/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 17:25:10 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
void			ft_read_map(char *file)
{
	int		fd;
	char	*line;
	int		j;
	int		c;
	t_data	dt1;

	dt1.nbant = 0;
	c = 0;
	line = NULL;
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if(ft_checknbant(line))
			dt1.nbant = ft_atoi(line);
		else if(ft_checkroom(line))
			printf("room = %s\n",line);
		else if(ft_checktube(line))
			printf("tube = %s\n",line);
	}
	printf("nbant = %d\n",dt1.nbant);
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if(ft_strcmp(line,"##start") == 0)
		{
			get_next_line(fd,&line);
			printf("start = %s\n",line);
		}
		if(ft_strcmp(line,"##end") == 0)
		{
			get_next_line(fd,&line);
			printf("end = %s\n",line);
		}
	}
	close(fd);
}
