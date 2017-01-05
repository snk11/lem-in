/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:52:15 by syusof            #+#    #+#             */
/*   Updated: 2017/01/05 01:06:21 by syusof           ###   ########.fr       */
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
		if (ft_checkroom_p1(&s, &space) == 0)
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
