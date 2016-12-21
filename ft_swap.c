/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:30:10 by syusof            #+#    #+#             */
/*   Updated: 2016/12/21 13:03:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void	ft_swap2(t_node **nodetmp,char *s1,char *s2)
{
	t_swap		swap1;

	ft_init8(&swap1);
	ft_swap_p1(&swap1, *nodetmp, s1, s2);
	if (swap1.cnt1 < swap1.cnt2)
		ft_swap_p2(&swap1, &nodetmp, s1);
	else if (swap1.cnt1 > swap1.cnt2)
		ft_swap_p3(&swap1, &nodetmp, s2);
}

void		ft_swap_p1(t_swap *swap1, t_node *nodetmp, char *s1, char *s2)
{
	swap1->nodetmp3 = nodetmp;
	while(ft_strcmp(swap1->nodetmp3->name,s1) != 0)
	{
		swap1->nodetmp3 = swap1->nodetmp3->nextl;
		swap1->cnt1++;
	}
	swap1->nodetmp4 = NULL;
	swap1->nodetmp4 = nodetmp;
	while(ft_strcmp(swap1->nodetmp4->name,s2) != 0)
	{
		swap1->nodetmp4 = swap1->nodetmp4->nextl;
		swap1->cnt2++;
	}
	swap1->nodetmp5 = nodetmp;
}

void		ft_swap_p2(t_swap *swap1, t_node ***nodetmp, char *s1)
{
		while(swap1->cnt1 - 1 > 0)
		{
			swap1->nodetmp5 = swap1->nodetmp5->nextl;
			swap1->cnt1--;
		}
		swap1->w = lst_add_downlrnew(&(swap1->w),(swap1->nodetmp4)->name);
		swap1->w->nextl = swap1->nodetmp3->nextl;
		if(ft_strcmp((**nodetmp)->name,s1) != 0)
			swap1->nodetmp5->nextl = swap1->w;
		else
			**nodetmp = swap1->w;

		swap1->nodetmp5 = **nodetmp;
		while(swap1->cnt2 - 1 > 0)
		{
			swap1->nodetmp5 = swap1->nodetmp5->nextl;
			swap1->cnt2--;
		}
		swap1->z = lst_add_downlrnew(&(swap1->z),swap1->nodetmp3->name);
		swap1->z->nextl = (swap1->nodetmp4)->nextl;
		swap1->nodetmp5->nextl = swap1->z;
}

void		ft_swap_p3(t_swap *swap1, t_node ***nodetmp, char *s2)
{
		while(swap1->cnt2 - 1 > 0)
		{
			swap1->nodetmp5 = (swap1->nodetmp5)->nextl;
			swap1->cnt2--;
		}
		swap1->w = lst_add_downlrnew(&(swap1->w),(swap1->nodetmp3)->name);
		swap1->w->nextl = (swap1->nodetmp4)->nextl;
		if(ft_strcmp((**nodetmp)->name,s2) != 0)
			swap1->nodetmp5->nextl = swap1->w;
		else
			**nodetmp = swap1->w;
		swap1->nodetmp5 = **nodetmp;
		while(swap1->cnt1 - 1 > 0)
		{
			swap1->nodetmp5 = swap1->nodetmp5->nextl;
			swap1->cnt1--;
		}
		swap1->z = lst_add_downlrnew(&(swap1->z),(swap1->nodetmp4)->name);
		(swap1->z)->nextl = (swap1->nodetmp3)->nextl;
		swap1->nodetmp5->nextl = swap1->z;
}

void	ft_swap2r(t_node **nodetmp,char *s1,char *s2)
{
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	t_node	*nodetmp5;
	t_node	*w;
	t_node	*z;
	int		cnt1;
	int		cnt2;

	cnt1 = 0;
	cnt2 = 0;
	w = NULL;
	z = NULL;
	nodetmp3 = NULL;
	nodetmp5 = NULL;
	nodetmp3 = *nodetmp;
	while(ft_strcmp(nodetmp3->name,s1) != 0)
	{
		nodetmp3 = nodetmp3->nextr;
		cnt1++;
	}
	nodetmp4 = NULL;
	nodetmp4 = *nodetmp;
	while(ft_strcmp(nodetmp4->name,s2) != 0)
	{
		nodetmp4 = nodetmp4->nextr;
		cnt2++;
	}
	nodetmp5 = *nodetmp;
	if (cnt1 < cnt2)
	{
		while(cnt1 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextr;
			cnt1--;
		}
		w = lst_add_downlrnew(&w,nodetmp4->name);
		w->nextr = nodetmp3->nextr;
		if(ft_strcmp((*nodetmp)->name,s1) != 0)
			nodetmp5->nextr = w;
		else
			*nodetmp = w;

		nodetmp5 = *nodetmp;
		while(cnt2 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextr;
			cnt2--;
		}


		z = lst_add_downlrnew(&z,nodetmp3->name);
		z->nextr = nodetmp4->nextr;
		nodetmp5->nextr = z;
	}
	else if (cnt1 > cnt2)
	{
		while(cnt2 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextr;
			cnt2--;
		}
		w = lst_add_downlrnew(&w,nodetmp3->name);
		w->nextr = nodetmp4->nextr;
		if(ft_strcmp((*nodetmp)->name,s2) != 0)
			nodetmp5->nextr = w;
		else
			*nodetmp = w;

		nodetmp5 = *nodetmp;
		while(cnt1 - 1 > 0)
		{
			nodetmp5 = nodetmp5->nextr;
			cnt1--;
		}


		z = lst_add_downlrnew(&z,nodetmp4->name);
		z->nextr = nodetmp3->nextr;
		nodetmp5->nextr = z;
	}
}

