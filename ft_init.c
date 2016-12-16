/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:09:52 by syusof            #+#    #+#             */
/*   Updated: 2016/12/16 18:46:44 by syusof           ###   ########.fr       */
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

void		ft_init3(t_pr *pr1)
{
	pr1->node2 = NULL;
	pr1->nodebest = NULL;
	pr1->nodedata = NULL;
	pr1->nodedummie = NULL;
}
