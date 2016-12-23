/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:09:52 by syusof            #+#    #+#             */
/*   Updated: 2016/12/23 05:01:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init(t_data *data1)
{
	data1->nbant = 0;
	data1->strbegi = NULL;
	data1->strend = NULL;
}

void		ft_init2(t_map *map1)
{
	map1->nodestart = NULL;
	map1->nodeend = NULL;
	map1->noderoom = NULL;
	map1->nodetube = NULL;
}

void		ft_init3(t_mkstring *mkstring1)
{
	mkstring1->nb1 = 0;
	mkstring1->nb2 = 0;
	mkstring1->i = 0;
}

void		ft_init4(t_read *read1)
{
	read1->s1 = NULL;
	read1->ant1 = 0;
	read1->j = 0;
	read1->i = 0;
	read1->r1 = 0;
	read1->r2 = 0;
	read1->r3 = 0;
	read1->r4 = 0;
	read1->fd = 0;
}

void		ft_init5(t_screen *screen1)
{
	screen1->nodetmp = NULL;
	screen1->nodetmp3 = NULL;
	screen1->ind1 = 0;
	screen1->ind2 = 0;
}
