/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmindata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 18:53:01 by syusof            #+#    #+#             */
/*   Updated: 2017/01/08 16:34:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_checkmindata(t_data data1, t_node *nodetmp)
{
	if (data1.nbant == 0)
		return (0);
	if (data1.strbegi == NULL || (data1.strbegi && ft_cursref_first(nodetmp, data1.strbegi)->nextr == NULL))
		return (0);
	if (data1.strend == NULL || (data1.strend && ft_cursref_first(nodetmp, data1.strend)->nextr == NULL))
		return (0);
	return (1);
}
