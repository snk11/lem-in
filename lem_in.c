/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:42 by syusof            #+#    #+#             */
/*   Updated: 2016/12/16 18:51:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"




#include <stdio.h>
int main(int ac,char **av)
{
	t_pr	pr1;
	t_data	data1;
	t_map	map1;
	char	*line;

	line = NULL;
	data1.nbant = 0;
	ft_init(&data1);
	ft_init2(&map1);
	ft_init3(&pr1);
	ft_read_map(&(pr1.node2),av[1],&data1, &map1);
	if (ft_checkmindata(data1) == 0)
	{
		write(1,"ERROR",5);
		return (0);
	}
	pr1.nodedummie = ft_generate(pr1.node2,data1.strbegi);
	pr1.nodedata = ft_screen(&(pr1.nodedata), pr1.nodedummie, pr1.node2, data1.strbegi, data1.strend);
	if(pr1.nodedata == NULL)
	{
		write(1,"ERROR",5);
		return (0);
	}
	ft_printmap(map1, data1.nbant);
//	ft_printfpath(nodedata);
	pr1.nodebest = ft_screenbest(&(pr1.nodebest),pr1.nodedata,data1.strend);
//	ft_printfpath(nodebest);
	if (pr1.nodebest && !ft_checkdirect(pr1.nodebest, data1.strend))
		ft_simul(pr1.nodebest, data1.strbegi, data1.strend, data1.nbant);
	else if (pr1.nodebest && ft_checkdirect(pr1.nodebest, data1.strend))
		ft_simuldirect(pr1.nodebest, data1.strbegi, data1.strend, data1.nbant);
}
