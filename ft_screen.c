/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 08:19:51 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 16:58:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

t_node	*ft_screen(t_node **nodedata,t_node *nodedummie,t_node *node1,char *strbegi,char *strend)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	int		ind1;
	int		ind2;

	nodetmp = NULL;
	nodetmp3 = NULL;
	ind1 = 0;
	ind2 = 1;
	nodetmp = nodedummie;
	while(nodetmp)
	{
		nodetmp3 = nodetmp;
		if (ft_strcmp(nodetmp->name,strbegi) == 0 && *nodedata)
		{
			ind1 = 0;
			nodetmp2 = *nodedata;
			while(nodetmp2 && ind1 == 0)
			{
				nodetmp4 = nodetmp2;
				nodetmp = nodetmp3;
				nodetmp2 = nodetmp2->nextr;
				nodetmp = nodetmp->nextr;
				while (nodetmp)
				{
					if(ft_strcmp(nodetmp->name,nodetmp2->name) == 0)
						ind1 = 1;
					nodetmp = nodetmp->nextr;
					nodetmp2 = nodetmp2->nextr;
				}
				nodetmp2 = nodetmp4;
				nodetmp2 = nodetmp2->nextl;
			}
		}
		nodetmp = nodetmp3;
		if (nodetmp && (ind1 == 0 || ind2 == 1))
		{
			ind2 = 0;
			*nodedata = lst_add_downlrnew(nodedata,nodetmp->name);
			nodetmp = nodetmp->nextr;
			while(nodetmp)
			{
				*nodedata = lst_add_down_downr(nodedata,nodetmp->name);
				nodetmp = nodetmp->nextr;
			}
		}
		nodetmp = nodetmp3;
		nodetmp = nodetmp->nextl;
	}
	return (*nodedata);
}
