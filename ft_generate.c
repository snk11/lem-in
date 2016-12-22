/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 15:18:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate(t_node *node1, char *strbegi)
{
	t_node	*nodetmp;
	t_node	*nodedata;
	int		nbelem;

	nodedata = NULL;
	nbelem = 0;
	nodetmp = ft_maketree(node1, strbegi);
	nbelem = ft_countelem_lv1(nodetmp);
	permute2(&nodetmp, &nodedata, 0, nbelem - 1, strbegi);
	return (nodedata);
}
