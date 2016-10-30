/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:52:15 by syusof            #+#    #+#             */
/*   Updated: 2016/10/30 18:58:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"



#include <stdio.h>
int		ft_checkroom(char *s)
{
	int space;

	space = 0;
	if(*s == 'L' || *s == '#')
		return (0);
	while(*s)
	{
		if((space == 1 || space == 2) && *s != ' ')
		{
			if(!(*s >= '0' && *s <= '9') )
				return (0);
		}
		if (*s == '-')
			return (0);
		if(*s == ' ')
			space++;
		if(space > 2)
			return (0);
		s++;
	}
	return (1);
}

int		ft_checkroom2(char *line, t_node **node1, t_node **node2)
{
	int i;
	int j;
	int k;
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	i = 0;
	j = 0;
	k = 0;
	if(ft_checkroom(line))
	{
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
		i++;
		k = i;
		while(line[i])
		{
			j++;
			i++;
		}
		s2 = (char*)malloc(sizeof(char)*j+1);
		i = k;
		j = 0;
		while(line[i])
		{
			s2[j] = line[i];
			j++;
			i++;
		}
		s2[j] = 0;
//		printf("s1 = %s, s2 = %s\n",s1,s2);
		if (ft_checkdouble_l(*node2,s2))
		{
			*node1 = ft_add_node_l(node1,s1);
			*node2 = lst_add_downl(node2,s2);
		}
		else if(ft_checkdouble_l(*node2,s2) == 0 && ft_checkdouble_l(*node1,s1) == 1)
			return (0);
	}
	return (1);
}
