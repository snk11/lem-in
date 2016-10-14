/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2016/10/14 20:37:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
int	ft_read_map(t_node **node1,char *file,t_data *data1)
{
	int		fd;
	char	*line;
	int		j;
	int		c;
	int		i;
	int		l1;
	char	*s1;
	char	*s2;
	char	*strbegi;
	char	*strend;
	int		ant1;

	ant1 = 0;
	c = 0;
	s1 = NULL;
	s2 = NULL;
	strbegi = NULL;
	strend = NULL;
	line = NULL;
	j = 0;
	i = 0;
	l1 = 0;

	l1 = ft_returnvaline(file);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if(ft_checknbant(line))
			ant1 = ft_atoi(line);
		else if(ft_checkroom(line))
		{
			i = 0;
			while(line[i] != ' ')
				i++;
			s1 = (char*)malloc(sizeof(char)*i+1);
			i = 0;
			while(line[i] != ' ')
			{
				s1[i] = line[i];
				i++;
			}
			s1[i] = 0;
//			if (ft_checkdouble_l(*node1,s1))
				*node1 = lst_add_downl(node1,s1);
			printf("room = %s\n",line);
		}
		else if(ft_checktube(line))
		{
			i = 0;
			while(line[i] != '-')
				i++;
			s1 = (char*)malloc(sizeof(char)*i+1);
			i = 0;
			while(line[i] != '-')
			{
				s1[i] = line[i];
				i++;
			}
			s1[i] = 0;
			i++;
			j = 0;
			while(line[i] != '\n' && line[i] != EOF)
			{
				j++;
				i++;
			}
			i = i - j;
			s2 = (char*)malloc(sizeof(char)*j+1);
			j = 0;
			while(line[i] != '\n' && line[i] != EOF)
			{
				s2[j] = line[i];
				j++;
				i++;
			}
			s2[j] = 0;
//			if (ft_checkdouble_r(ft_cursref_first(*node1,s1),s1))
				*node1 = lst_add_downr(node1,ft_cursref_first(*node1,s1),s2);
			printf("tube = %s\n",line);
		}
		l1--;
	}
	close(fd);
	l1 = ft_returnvaline(file);
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
		l1--;
	}

	if (ant1 > 0)
		(data1)->nbant = ant1;
	if (strbegi)
		(data1)->strbegi = strbegi;
	if (strend)
		(data1)->strend = strend;
	close(fd);
	return (1);
}
