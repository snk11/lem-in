/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 21:15:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate(t_node *node2, char *strbegi)
{
	t_gene	gene1;
	int		nbelem;

	gene1.nodedata = NULL;
	nbelem = 0;
	gene1.nodetmp = ft_maketree(node2, strbegi);
//	ft_printnode(gene1.nodetmp);
	nbelem = ft_countelem_lv1(gene1.nodetmp);
	permute1(&gene1, 0, 0, strbegi);
	return (gene1.nodedata);
}
