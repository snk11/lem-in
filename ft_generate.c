/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 18:08:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
//void	ft_generate(t_node *node1,int nb)
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i)); //backtrack
		}
	}
}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
