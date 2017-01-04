/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:52:26 by syusof            #+#    #+#             */
/*   Updated: 2017/01/04 12:47:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate2(t_node *nodeprime, char *strbegi, char *strend)
{
	t_gene	gene1;
	int		nbelem;
	int		lv;

	gene1.nodedata = NULL;
	gene1.nodescreen = NULL;
	lv = 1;
	nbelem = ft_countelem_lv1(nodeprime);
	ft_dfs(nodeprime, &gene1, strbegi, strend, nbelem, &lv);
//	printf("\n");
	return (gene1.nodescreen);

}

void		ft_dfs(t_node *nodeprime, t_gene *gene1, char *strbegi, char *strend, int nbelem, int *lv)
{
	t_node		*nodetmp3;
	t_node		*nodetmp4;

//	printf("lv = %d\n", *lv);
//	printf("nodedata = \n");
//	ft_printnode(gene1->nodedata);
	nodetmp3 = ft_cursref_first(nodeprime, strbegi);
//	printf("dfs = %s\n\n", nodetmp3->name);
	if (*lv < nbelem)
		gene1->nodedata = lst_add_downl(&(gene1->nodedata), nodetmp3->name);
	nodetmp3 = nodetmp3->nextr;
	while (nodetmp3)
	{
		//		if (ft_checkdouble_l(*nodedata, nodetmp3->name))
		if (*lv < nbelem && ft_strcmp(nodetmp3->name, strend) != 0 && ft_checkdouble_l(gene1->nodedata, nodetmp3->name))
		{
			(*lv)++;
			ft_dfs(nodeprime, gene1,nodetmp3->name,strend,nbelem,lv);
		}
		else
			{
				gene1->nodedata = lst_add_downl(&(gene1->nodedata), nodetmp3->name);
			nodetmp4 = gene1->nodedata;
			gene1->nodescreen = lst_add_downl(&(gene1->nodescreen), nodetmp4->name);
//			printf("%s ", nodetmp4->name);
			nodetmp4 = nodetmp4->nextl;
			while (nodetmp4)
			{
				gene1->nodescreen = lst_add_down_downr(&(gene1->nodescreen), nodetmp4->name);
//				printf("%s ", nodetmp4->name);
				nodetmp4 = nodetmp4->nextl;
			}
//			printf("\n");
			nodetmp4 = gene1->nodedata;
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
		nodetmp4 = gene1->nodedata;
		while (nodetmp4 && nodetmp4->nextl && (nodetmp4->nextl)->nextl)
		{
			nodetmp4 = nodetmp4->nextl;
		}
		nodetmp4->nextl = NULL;
	}
	(*lv)--;
//	ft_printnode(gene1->nodedata);
//	printf("\n");
}
