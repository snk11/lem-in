/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:42:19 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 15:38:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_makestring(int nb, char *name)
{
	t_mkstring		mkstring1;

	ft_init3(&mkstring1);
	ft_makestring_p1(&mkstring1, nb, name);
	mkstring1.s1 = (char*)malloc(sizeof(char) * 2
			+ mkstring1.nb1 + mkstring1.nb2 + 1);
	mkstring1.s1[mkstring1.i] = 'L';
	mkstring1.i++;
	while (*(mkstring1.s2))
	{
		(mkstring1.s1)[mkstring1.i] = *mkstring1.s2;
		mkstring1.i++;
		mkstring1.s2++;
	}
	(mkstring1.s1)[mkstring1.i] = '-';
	mkstring1.i++;
	while (*name)
	{
		(mkstring1.s1)[mkstring1.i] = *name;
		mkstring1.i++;
		name++;
	}
	(mkstring1.s1)[mkstring1.i] = 0;
	return (mkstring1.s1);
}

void		ft_makestring_p1(t_mkstring *mkstring1, int nb, char *name)
{
	mkstring1->s2 = ft_itoa(nb);
	mkstring1->nb1 = ft_strlen(mkstring1->s2);
	mkstring1->nb2 = ft_strlen(name);
}
