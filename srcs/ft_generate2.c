/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:52:26 by syusof            #+#    #+#             */
/*   Updated: 2016/12/23 03:29:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate2(t_node *nodeprime, t_node **nodedata, t_node **nodescreen, char *strbegi)
{
	int		nbelem;
	int		lv;

	lv = 1;
	nbelem = ft_countelem_lv1(nodeprime);
	ft_dfs(nodeprime, nodedata, nodescreen, strbegi, nbelem, &lv);
	printf("\n");
	return (*nodescreen);

}

void		ft_dfs(t_node *nodeprime, t_node **nodedata, t_node **nodescreen, char *strbegi, int nbelem, int *lv)
{
	t_node		*nodetmp3;
	t_node		*nodetmp4;

	printf("lv = %d\n", *lv);
	printf("nodedata = \n");
	ft_printnode(*nodedata);
	nodetmp3 = ft_cursref_first(nodeprime, strbegi);
	printf("dfs = %s\n\n", nodetmp3->name);
	if (*lv < nbelem)
		*nodedata = lst_add_downl(nodedata, nodetmp3->name);
	nodetmp3 = nodetmp3->nextr;
	while (nodetmp3)
	{
		//		if (ft_checkdouble_l(*nodedata, nodetmp3->name))
		if (*lv < nbelem)
		{
			(*lv)++;
			ft_dfs(nodeprime, nodedata, nodescreen,nodetmp3->name,nbelem,lv);
		}
		else
		{
			*nodedata = lst_add_downl(nodedata, nodetmp3->name);
			nodetmp4 = *nodedata;
			*nodescreen = lst_add_downl(nodescreen, nodetmp4->name);
			printf("%s ", nodetmp4->name);
			nodetmp4 = nodetmp4->nextl;
			while (nodetmp4)
			{
				*nodescreen = lst_add_down_downr(nodescreen, nodetmp4->name);
				printf("%s ", nodetmp4->name);
				nodetmp4 = nodetmp4->nextl;
			}
			*nodescreen = lst_add_down_downr(nodescreen, nodetmp3->name);
			printf("\n");
			nodetmp4 = *nodedata;
			while (nodetmp4 && nodetmp4->nextl && (nodetmp4->nextl)->nextl)
			{
				nodetmp4 = nodetmp4->nextl;
			}
			nodetmp4->nextl = NULL;
		}
		nodetmp3 = nodetmp3->nextr;
	}
	if (*lv < nbelem)
	{
		nodetmp4 = *nodedata;
		while (nodetmp4 && nodetmp4->nextl && (nodetmp4->nextl)->nextl)
		{
			nodetmp4 = nodetmp4->nextl;
		}
		nodetmp4->nextl = NULL;
	}
	(*lv)--;
	ft_printnode(*nodedata);
	printf("\n");
}
