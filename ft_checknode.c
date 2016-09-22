/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:24:18 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 15:48:59 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem-in.h"

int		ft_checknode(t_path *path1,char *s)
{
	char	*s1;
	char	*s2;
	int		len;
	int i;
	int j;
	int r;

	r = 1;
	s1 = path1->name;
	s2 = NULL;
	i = 0;
	while(s1[i] != 0)
	{
		len = 0;
		j = i;
		while(s1[i] != '/' && s1[i] != 0)
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			s2 = (char*)malloc(sizeof(char) * len + 1);
		}
		i = j;
		j = 0;
		while(s1[i] != '/' && s1[i] != 0)
		{
			s2[j] = s1[i];
			i++;
			j++;
		}
		if (s2)
			s2[j] = 0;
		if(ft_strcmp(s2,s) == 0)
			r = 0;
	}
	return (r);
}
