/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_returnvaline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:56:36 by syusof            #+#    #+#             */
/*   Updated: 2016/10/15 13:37:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"



#include<stdio.h>
int		ft_returnvaline(char *file)
{
	int	fd;
	int i;
	int	r1;
	int	r2;
	int	r3;
	int valine;
	char	*line;

	line = NULL;
	fd = 0;
	i = 0;
	r1 = 0;
	r2 = 0;
	r3 = 0;
	valine = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		valine++;
		if(ft_checknbant(line))
		{
			if(r1 >= 1)
			{
				valine--;
				return (valine);
			}
			r1++;
		}
		else if(ft_checkroom(line))
		{
		}
		else if(ft_checktube(line))
		{
		}
		else if(ft_strcmp(line,"##start") == 0)
		{
			if(r2 >= 1)
			{
				valine--;
				return (valine);
			}
			r2++;
		}
		else if(ft_strcmp(line,"##end") == 0)
		{
			if(r3 >= 1)
			{
				valine--;
				return (valine);
			}
			r3++;
		}
		else if(line[0] == '#' && line[1] != '#')
		{
		}
		else
		{
			valine--;
			return (valine);
		}
	}
	close(fd);
	return (valine);
}
