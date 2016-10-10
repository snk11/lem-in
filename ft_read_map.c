/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/10 15:26:42 by syusof           ###   ########.fr       */
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
	int		i;
	char	*strbegi;
	char	*strend;
	t_data	dt1;

	dt1.nbant = 0;
	c = 0;
	strbegi = NULL;
	strend = NULL;
	line = NULL;
	j = 0;
	i = 0;
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
			printf("start = %s\n",strbegi);
		}
		if(ft_strcmp(line,"##end") == 0)
		{
			get_next_line(fd,&line);
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
			printf("end = %s\n",strend);
		}
	}
	close(fd);
}
