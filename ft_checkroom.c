/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:52:15 by syusof            #+#    #+#             */
/*   Updated: 2016/10/15 14:35:47 by syusof           ###   ########.fr       */
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
