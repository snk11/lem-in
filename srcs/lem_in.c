/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/12/23 04:17:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		main_p1(t_dmain *dmain1)
{
	if (dmain1->nodebest
			&& !ft_checkdirect(dmain1->nodebest, (dmain1->data1).strend))
		ft_simul(dmain1->nodebest,
				(dmain1->data1).strend, (dmain1->data1).nbant);
	else if (dmain1->nodebest
			&& ft_checkdirect(dmain1->nodebest, (dmain1->data1).strend))
		ft_simuldirect(dmain1->nodebest,
				(dmain1->data1).strend, (dmain1->data1).nbant);
}

int			main(void)
{
	t_dmain		dmain1;
	t_node		*nodescreen;

	nodescreen = NULL;
	ft_init12(&dmain1);
	ft_read_map(&(dmain1.node2), &(dmain1.data1), &(dmain1.map1));
	if (ft_checkmindata(dmain1.data1) == 0)
	{
		write(1, "ERROR", 5);
		return (0);
	}
//	ft_printnode(dmain1.node2);
	dmain1.nodedummie = ft_generate2(dmain1.node2, &(dmain1.nodedata),&nodescreen,dmain1.data1.strbegi, dmain1.data1.strend);
	ft_printnode(nodescreen);
	dmain1.nodedata = nodescreen;
	dmain1.nodedummie = ft_generate(dmain1.node2, dmain1.data1.strbegi);
//	ft_printnode(dmain1.nodedummie);
	dmain1.nodedata = ft_screen(&(dmain1.nodedata), dmain1);
	if (dmain1.nodedata == NULL)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	ft_printmap(dmain1.map1, dmain1.data1.nbant);
	dmain1.nodebest = ft_screenbest(&(dmain1.nodebest), dmain1.nodedata,
			(dmain1.data1).strend);
	main_p1(&dmain1);
	return (1);
}
