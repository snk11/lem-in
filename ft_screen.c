/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 08:19:51 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 11:55:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

t_node    *ft_screen(t_node **nodedata,t_node *nodedummie,t_node *node1,char *strbegi,char *strend)
{
	t_node    *nodetmp;
	t_node    *nodetmp3;
	int        ind1;
	int        ind2;

	nodetmp = NULL;
	nodetmp3 = NULL;
	ind1 = 0;
	ind2 = 0;
	nodetmp = nodedummie;
	while(nodetmp)
	{
		nodetmp3 = nodetmp;
		if (ft_strcmp(nodetmp->name,strbegi) == 0)
		{
			ind1 = 0;
			ind2 = 0;
			while(nodetmp && ind2 == 0 && ind1 == 0)
			{
				while(nodetmp && nodetmp->nextr && ind2 == 0 && ind1 == 0)
				{
					if(ft_checknode2(ft_cursref_first(node1,nodetmp->name),(nodetmp->nextr)->name) == 0)
						ind1 = 1;
					if(ft_strcmp((nodetmp->nextr)->name,strend) == 0)
						ind2 = 1;
					nodetmp = nodetmp->nextr;
				}
				nodetmp = nodetmp->nextr;
			}
			nodetmp = nodetmp3;
			if (ind1 == 0 && ind2 == 1)
			{
				*nodedata = lst_add_downlrnew(nodedata,nodetmp->name);
				nodetmp = nodetmp->nextr;
				while(nodetmp)
				{
					*nodedata = lst_add_down_downr(nodedata,nodetmp->name);
					nodetmp = nodetmp->nextr;
				}
			}
			nodetmp = nodetmp3;
		}
		nodetmp = nodetmp->nextl;
	}
	return (*nodedata);
}
