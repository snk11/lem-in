/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:52:26 by syusof            #+#    #+#             */
/*   Updated: 2017/01/04 13:39:39 by syusof           ###   ########.fr       */
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
	return (gene1.nodescreen);

}

