/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 19:57:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"



#include <stdio.h>
t_node	*ft_generate(t_node *node1,char *strbegi)
{
	t_node	*nodetmp;
	t_node	*nodetmp3;
	t_node	*nodedata;

	nodedata = NULL;
	nodetmp3 = NULL;
	nodetmp = ft_maketree2(node1,strbegi);
	ft_printfpath(nodetmp);
	/*
	nodetmp3 = nodetmp;
	while(nodetmp3 && nodetmp3->nextl)
		nodetmp3 = nodetmp3->nextl;

	permute2(&nodetmp,&nodedata,nodetmp->name,nodetmp3->name);
	*/
	return (nodedata);
}

void permute2(t_node **nodetmp, t_node **nodedata,char *s1,char *s2)
{
	int	i;
	t_node *nodetmp2;
	t_node *nodetmp3;
	nodetmp3 = *nodetmp;
	if (ft_strcmp(s1,s2) == 0)
	{
	 	*nodedata = lst_add_downlrnew(nodedata,nodetmp3->name);
		nodetmp3 = nodetmp3->nextl;
		while(nodetmp3)
		{
			*nodedata = lst_add_down_downr(nodedata,nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
		}
	}
	else
	{
		while(ft_strcmp(nodetmp3->name,s1) != 0)
				nodetmp3 = nodetmp3->nextl;
		nodetmp2 = nodetmp3;
		while(ft_strcmp(nodetmp3->name,s2))
		{
			swap2(nodetmp,nodetmp2->name,nodetmp3->name);
			permute2(nodetmp,nodedata,(nodetmp3->nextl)->name,s2);
			swap2(nodetmp,nodetmp2->name,nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
		}

	}
}
void	swap2(t_node **nodetmp,char *s1,char *s2)
{
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	t_node	*nodetmp5;
	t_node	*w;
	int		cnt1;
	int		cnt2;

	cnt1 = 0;
	cnt2 = 0;
	nodetmp3 = NULL;
	nodetmp5 = NULL;
	nodetmp3 = *nodetmp;
	while(ft_strcmp(nodetmp3->name,s1) != 0)
	{
		nodetmp3 = nodetmp3->nextl;
		cnt1++;
	}
	nodetmp4 = NULL;
	nodetmp4 = *nodetmp;
	while(ft_strcmp(nodetmp4->name,s1) != 0)
	{
		nodetmp4 = nodetmp4->nextl;
		cnt2++;
	}
	nodetmp5 = *nodetmp;
	while(cnt1 - 1 > 0)
	{
		nodetmp5 = nodetmp5->nextl;
		cnt1--;
	}
	w = lst_add_downlrnew(&w,nodetmp4->name);
	w->nextl = nodetmp3->nextl;
	nodetmp5->nextl = w;

	nodetmp5 = *nodetmp;
	while(cnt2 - 1 > 0)
	{
		nodetmp5 = nodetmp5->nextl;
		cnt2--;
	}
	w = lst_add_downlrnew(&w,nodetmp3->name);
	w->nextl = nodetmp4->nextl;
	nodetmp5->nextl = w;

}


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
