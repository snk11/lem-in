/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:09:47 by syusof            #+#    #+#             */
/*   Updated: 2016/12/21 14:19:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_node	*ft_maketree(t_node *maintree,char *strbegi)
{
	t_node	*rtree;
	
	rtree = ft_copytree(maintree,strbegi);

	return (rtree);
}
