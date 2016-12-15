/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/12/15 18:58:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"




#include <stdio.h>
int main(int ac,char **av)
{
	t_node	*node2;
	t_node	*nodetmp;
	t_node	*nodedata;
	t_node	*nodedummie;
	t_node	*nodebest;
	t_data	data1;
	char	*line;

	line = NULL;
	node2 = NULL;
	nodebest = NULL;
	nodedata = NULL;
	nodedummie = NULL;
	data1.nbant = 0;
	ft_init(&data1);
	ft_read_map(&node2,av[1],&data1);
	if (ft_checkmindata(data1) == 0)
	{
		write(1,"ERROR",5);
		return (0);
	}
	nodedummie = ft_generate(node2,data1.strbegi);
	nodedata = ft_screen(&nodedata, nodedummie, node2, data1.strbegi, data1.strend);
	if(nodedata == NULL)
	{
		write(1,"ERROR",5);
		return (0);
	}
//	ft_printfpath(nodedata);
	nodebest = ft_screenbest(&nodebest,nodedata,data1.strend);
//	ft_printfpath(nodebest);
	if (nodebest && !ft_checkdirect(nodebest, data1.strend))
		ft_simul(nodebest, data1.strbegi, data1.strend, data1.nbant);
	else if (nodebest && ft_checkdirect(nodebest, data1.strend))
		ft_simuldirect(nodebest, data1.strbegi, data1.strend, data1.nbant);
}
