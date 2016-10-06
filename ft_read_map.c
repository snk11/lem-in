/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 13:37:42 by syusof           ###   ########.fr       */
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

	c = 0;
	line = NULL;
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		dt1.nbant = ft_atoi(line);
	}
	printf("nbant = %d\n",dt1.nbant);
	close(fd);
}
