/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:52:26 by syusof            #+#    #+#             */
/*   Updated: 2016/12/23 00:41:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_generate2(t_node *nodeprime, t_node **nodedata, char *strbegi)
{
//	int		nbelem;

//	nbelem = ft_countelem_lv1(nodeprime);
	ft_dfs(nodeprime, nodedata, strbegi);
	printf("\n");
	return (*nodedata);

}

void		ft_dfs(t_node *nodeprime, t_node **nodedata, char *strbegi)
{
	t_node		*nodetmp3;

	nodetmp3 = ft_cursref_first(nodeprime, strbegi);
	printf("%s ", nodetmp3->name);
	*nodedata = lst_add_downl(nodedata, nodetmp3->name);
	while (nodetmp3)
	{
		if (ft_checkdouble_l(*nodedata, nodetmp3->name))
			ft_dfs(nodeprime, nodedata, nodetmp3->name );
		nodetmp3 = nodetmp3->nextr;
	}
}
