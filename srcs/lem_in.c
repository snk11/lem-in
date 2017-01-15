/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2017/01/16 00:22:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_dmain		dmain1;

	ft_init12(&dmain1);
	ft_read_map(&dmain1, &(dmain1.data1), &(dmain1.map1));
	if (ft_checkmindata(dmain1.data1, dmain1.node2) == 0)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	dmain1.nodedummie = ft_generate2(dmain1.node2, dmain1.data1.strbegi,
			dmain1.data1.strend);
	dmain1.nodedata = ft_screen(&(dmain1.nodedata), dmain1);
	if (dmain1.nodedata == NULL)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	ft_printmap(dmain1.map1, dmain1.data1.nbant);
	dmain1.nodebest = ft_screenbest(&(dmain1.nodebest), dmain1.nodedata,
			(dmain1.data1).strend);
	if (dmain1.nodebest)
		ft_simuldirect(dmain1.nodebest,
				(dmain1.data1).strend, (dmain1.data1).nbant);
	return (1);
}
