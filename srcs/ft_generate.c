/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 18:25:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate(t_node *node1, char *strbegi)
{
	t_gene	gene1;
	int		nbelem;

	gene1.nodedata = NULL;
	nbelem = 0;
	gene1.nodetmp = ft_maketree(node1, strbegi);
	nbelem = ft_countelem_lv1(gene1.nodetmp);
	permute2(&gene1, 0, nbelem - 1, strbegi);
	return (gene1.nodedata);
}
