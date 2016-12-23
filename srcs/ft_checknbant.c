/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknbant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:00:45 by syusof            #+#    #+#             */
/*   Updated: 2016/12/23 05:20:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checknbant(char *s)
{
	char	*s1;

	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	s1 = s;
	while (*s && *s != ' ' && *s != '\t')
	{
		printf("s1 = %s\n",s1);
		printf("s = %c\n",*s);
		if (!(*s >= '0' && *s <= '9'))
		{
			printf("s = %c\n",*s);
			return (0);
		}
		s++;
	}
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s)
		return (0);
	s = s1;
	if (ft_checkint(s) == 0)
		return (0);
	return (1);
}
