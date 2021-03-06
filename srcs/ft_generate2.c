/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:52:26 by syusof            #+#    #+#             */
/*   Updated: 2017/01/15 22:12:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate2(t_node *nodeprime, char *strbegi, char *strend)
{
	t_gene	gene1;

	gene1.nodedata = NULL;
	gene1.nodescreen = NULL;
	gene1.lv = 1;
	gene1.nbelem = ft_countelem_lv1(nodeprime);
	gene1.lv = 1;
	ft_dijkstra(nodeprime, &gene1, strbegi, strend);
	return (gene1.nodescreen);
}
