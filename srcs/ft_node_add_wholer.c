/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add_wholer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:54:04 by syusof            #+#    #+#             */
/*   Updated: 2017/01/14 12:50:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_node_add_wholer(t_node **nodetmp1, t_node *nodetmp2, char *strbegi)
{
	while (nodetmp2 && nodetmp2->nextl)
		nodetmp2 = nodetmp2->nextl;
	*nodetmp1 = lst_add_downl(&(*nodetmp1), strbegi);
	while (nodetmp2)
	{
		*nodetmp1 = lst_add_down_downr(&(*nodetmp1), nodetmp2->name);
		nodetmp2 = nodetmp2->nextr;
	}
}
