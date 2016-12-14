/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:50 by syusof            #+#    #+#             */
/*   Updated: 2016/12/14 21:02:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



#include <stdio.h>
t_node	*ft_generate(t_node *node1,char *strbegi)
{
	t_node	*nodetmp;
	t_node	*nodedata;
	int		nbelem;

	nodedata = NULL;
	nbelem = 0;
	nodetmp = ft_maketree2(node1,strbegi);


	nbelem = ft_countelem_lv1(nodetmp);
	permute2(&nodetmp,&nodedata,0,nbelem - 1,strbegi);
	return (nodedata);
}

void permute2(t_node **nodetmp, t_node **nodedata,int r1,int r2,char *strbegi)
{
	int	i;
	int	r;
	t_node *nodetmp2;
	t_node *nodetmp3;
	nodetmp3 = *nodetmp;

	r = r1;
	if (r1 == r2 && ft_strcmp(nodetmp3->name,strbegi) == 0)
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
		while(r1 > 0)
		{
			nodetmp3 = nodetmp3->nextl;
			r1--;
		}
		r1 = r;
		nodetmp2 = nodetmp3;
		while(r <= r2)
		{
			swap2(nodetmp,nodetmp2->name,nodetmp3->name);
			permute2(nodetmp,nodedata,r1 + 1,r2,strbegi);
			swap2(nodetmp,nodetmp2->name,nodetmp3->name);
			nodetmp3 = nodetmp3->nextl;
			r++;
		}
	}
}

void	swap2(t_node **nodetmp,char *s1,char *s2)
{
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	t_node	*nodetmp5;
	t_node	*w;
	t_node	*z;
	int		cnt1;
	int		cnt2;
	int		sw;

	sw = 0;
	cnt1 = 0;
	cnt2 = 0;
	w = NULL;
	z = NULL;
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
	while(ft_strcmp(nodetmp4->name,s2) != 0)
	{
		nodetmp4 = nodetmp4->nextl;
		cnt2++;
	}
	nodetmp5 = *nodetmp;
	if (cnt1 < cnt2)
	{
		while(cnt1 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextl;
			cnt1--;
		}
		w = lst_add_downlrnew(&w,nodetmp4->name);
		w->nextl = nodetmp3->nextl;
		if(ft_strcmp((*nodetmp)->name,s1) != 0)
			nodetmp5->nextl = w;
		else
			*nodetmp = w;

		nodetmp5 = *nodetmp;
		while(cnt2 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextl;
			cnt2--;
		}


		z = lst_add_downlrnew(&z,nodetmp3->name);
		z->nextl = nodetmp4->nextl;
		nodetmp5->nextl = z;
	}
	else if (cnt1 > cnt2)
	{
		while(cnt2 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextl;
			cnt2--;
		}
		w = lst_add_downlrnew(&w,nodetmp3->name);
		w->nextl = nodetmp4->nextl;
		if(ft_strcmp((*nodetmp)->name,s2) != 0)
			nodetmp5->nextl = w;
		else
			*nodetmp = w;

		nodetmp5 = *nodetmp;
		while(cnt1 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextl;
			cnt1--;
		}


		z = lst_add_downlrnew(&z,nodetmp4->name);
		z->nextl = nodetmp3->nextl;
		nodetmp5->nextl = z;
	}
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
