/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:22:04 by syusof            #+#    #+#             */
/*   Updated: 2016/09/29 13:36:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "lem-in.h"

int		ft_checkp(t_node *node1,int p)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	t_node	*nodetmp3;
	int		ind1;
	int cnt1;

	ind1 = 0;
	cnt1 = 0;
	nodetmp2 = node1;
	nodetmp = NULL;
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	nodetmp = ft_createnode(nodetmp2->name);
	nodetmp3 = nodetmp;
	while (nodetmp2 && (nodetmp2)->nextr)
	{
		nodetmp2 = (nodetmp2)->nextr;
		nodetmp = ft_createnode(nodetmp2->name);
		nodetmp3->nextr = nodetmp;
		nodetmp3 = nodetmp;
		cnt1++;
	}
	if(cnt1 == 0)
		return (1);
	if ((cnt1 - 1 - p) > 0)
		return (1);
	return (0);
}

