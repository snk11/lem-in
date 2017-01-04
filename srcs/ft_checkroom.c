/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:52:15 by syusof            #+#    #+#             */
/*   Updated: 2017/01/04 20:43:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkroom(char *s)
{
	int	space;

	space = 0;
	if (*s == 'L' || *s == '#')
		return (0);
	while (*s && space <= 2)
	{
		if(ft_checkroom_p1(&s, &space) == 0)
			return (0);
	}
	if (space == 0 || space == 1)
		return (0);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s)
		return (0);
	return (1);
}

int		ft_checkroom_p1(char **s, int *space)
{
		if (*space == 0)
		{
			if (ft_checkroom_p1_p1(*s) == 0)
				return (0);
		}
		else
		{
			if (ft_checkroom_p1_p2(*s) == 0)
				return (0);
		}
		if (**s == ' ')
			(*space)++;
		(*s)++;
		return (1);
}

int		ft_checkroom_p1_p1(char *s)
{
	while (*s && *s != ' ' && *s != '\t')
	{
		if (!ft_isalnum(*s))
			return (0);
		s++;
	}
	return (1);
}

int		ft_checkroom_p1_p2(char *s)
{
	while (*s && *s != ' ' && *s != '\t')
	{
		if (!ft_isdigit(*s) && *s != '-' && *s != '+')
			return (0);
		s++;
	}
	return (1);
}

int		ft_checkroom2(char *line, t_node **node2, t_node **nodecoors)
{
	t_checkr	checkr1;

	ft_init11(&checkr1);
	if (ft_checkroom(line))
	{
		ft_checkroom2_p1(&checkr1, line);
		ft_checkroom2_p2(&checkr1, line);
		if (ft_checkroom2_p3(checkr1.s2) == 0)
			return (0);
		if (ft_checkdouble_l(*nodecoors, checkr1.s2)
				&& ft_checkdouble_l(*node2, checkr1.s1) == 1)
		{
			*node2 = ft_add_node_l(node2, checkr1.s1);
			*nodecoors = lst_add_downl(nodecoors, checkr1.s2);
		}
		else if (ft_checkdouble_l(*nodecoors, checkr1.s2) == 0
				&& ft_checkdouble_l(*node2, checkr1.s1) == 1)
			return (0);
		else if (ft_checkdouble_l(*node2, checkr1.s1) == 0
				&& ft_checkdouble_l(*nodecoors, checkr1.s2) == 1)
			return (0);
	}
	return (1);
}

void	ft_checkroom2_p1(t_checkr *checkr1, char *line)
{
	while (line[checkr1->i] != ' ')
		checkr1->i++;
	checkr1->s1 = (char*)malloc(sizeof(char) * checkr1->i + 1);
	checkr1->i = 0;
	while (line[checkr1->i] != ' ')
	{
		(checkr1->s1)[checkr1->i] = line[checkr1->i];
		checkr1->i++;
	}
	(checkr1->s1)[checkr1->i] = 0;
	checkr1->i++;
	checkr1->k = checkr1->i;
	while (line[checkr1->i])
	{
		checkr1->j++;
		checkr1->i++;
	}
}

void	ft_checkroom2_p2(t_checkr *checkr1, char *line)
{
	checkr1->s2 = (char*)malloc(sizeof(char) * checkr1->j + 1);
	checkr1->i = checkr1->k;
	checkr1->j = 0;
	while (line[checkr1->i])
	{
		(checkr1->s2)[checkr1->j] = line[checkr1->i];
		checkr1->j++;
		checkr1->i++;
	}
	(checkr1->s2)[checkr1->j] = 0;
}

int		ft_checkroom2_p3(char *s2)
{
	t_checkr checkr2;

	ft_init11(&checkr2);
	ft_checkroom2_p1(&checkr2, s2);
	if (ft_checkint(checkr2.s1) == 0)
		return (0);
	ft_checkroom2_p2(&checkr2, s2);
	if (ft_checkint(checkr2.s2) == 0)
		return (0);
	return (1);
}
