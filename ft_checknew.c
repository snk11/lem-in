/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:48:28 by syusof            #+#    #+#             */
/*   Updated: 2016/09/29 12:53:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"



#include <stdio.h>
int		ft_checknew(t_node *path1)
{
	while (path1->nextl)
		path1 = path1->nextl;
	while (path1->nextr)
		path1 = path1->nextr;
	printf("pathname = %s\n",path1->name);
	if(ft_strcmp(path1->name,"") == 0)
		return (1);
	return (0);
}
