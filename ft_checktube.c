/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:14:07 by syusof            #+#    #+#             */
/*   Updated: 2016/10/15 15:54:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

int		ft_checktube1(char *s)
{
	int	t;

	t = 0;
	while(*s)
	{
		if (*s == ' ')
			return (0);
		if(*s == '-')
			t++;
		if (t > 1)
			return (0);
		s++;
	}
	if(t == 1)
		return (1);
	return (0);
}

int		ft_checktube2(char *line,t_node *node1)
{
	int	i;
	int	j;
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	i = 0;
	j = 0;
	if(ft_checktube1(line))
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
		if (ft_cursref_first(node1,s1) == NULL)
			return (0);
		if (ft_cursref_first(node1,s2) == NULL)
			return (0);
	}
	else
		return (0);
	return (1);
}
