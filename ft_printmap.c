/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:55:25 by syusof            #+#    #+#             */
/*   Updated: 2016/12/16 15:01:49 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_printmap(t_map map1, int nbant)
{
	ft_putnbr(nbant);
	ft_putstr("\n");
	ft_putstr("##start\n");
	ft_printsol(map1.nodestart);
	ft_putstr("##end\n");
	ft_printsol(map1.nodeend);
	ft_printsol(map1.noderoom);
	ft_printsol(map1.nodetube);
	ft_putstr("\n");
}
