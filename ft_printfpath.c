/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:20:28 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 15:48:04 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"



#include <stdio.h>
void	ft_printfpath(t_node *path1begi)
{
	t_node	*path1ind2;
	t_node	*path1ind;

		printf("============================begi PATH\n");
	path1ind2 = (path1begi);
	path1ind = NULL;
	while(path1ind2)
	{
		path1ind = path1ind2;
		while (path1ind2)
		{
			printf("path = %s\n",(path1ind2)->name);
			path1ind2 = (path1ind2)->nextr;
		}
		(path1ind2) = path1ind;
		(path1ind2) = (path1ind2)->nextl;
		printf("===============\n");
	}
		printf("==============================end PATH\n");
}
