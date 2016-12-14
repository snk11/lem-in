/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:42:19 by syusof            #+#    #+#             */
/*   Updated: 2016/12/14 19:10:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_makestring(int nb, char *name)
{
	char	*s1;
	char	*s2;
	int		nb1;
	int		nb2;
	int		i;
	int		j;
	nb1 = 0;
	nb2 = 0;
	i = 0;

	s2 = ft_itoa(nb);
	nb1 = ft_strlen(s2);
	nb2 = ft_strlen(name);
	s1 = (char*)malloc(sizeof(char) * 2 + nb1 + nb2 + 1);
	s1[i] = 'L';
	i++;
	while (*s2)
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '-';
	i++;
	while (*name)
	{
		s1[i] = *name;
		i++;
		name++;
	}
	s1[i] = 0;
	return (s1);
}
