/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:09:47 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 19:49:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


t_node	*ft_maketree2(t_node *maintree,char *strbegi)
{
	t_node	*rtree;
	
	rtree = ft_copytree2(maintree,strbegi);

	ft_printfpath(rtree);
	return (rtree);
}

t_node	*ft_maketree(t_node *maintree,char *strbegi)
{
	t_node	*rtree;
	
	rtree = ft_copytree(maintree,strbegi);

	ft_printfpath(rtree);
	return (rtree);
}
