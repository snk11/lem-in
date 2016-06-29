/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/06/29 20:09:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_proceed(t_lst2 *lstpath, t_lst2 *lstprime, t_lst2 *lstremain)
{
	char	*s1;
	t_node1		*e;
	t_lst2		*lstmp;
	t_lst2		*lstprimebegi;
	t_lst		*lstmp1;
	t_lst		*lst1;
	t_lst		*lst3;
	t_lst		*lst1begi;
	t_lst		*lst2;

	lst1 = NULL;
	lstprimebegi = lstprime;
	lstprime = lstprime->nextl;
	while (lstprime)
	{
//		while (lstbeginnode && ft_checkremain(lstremain, ((t_node1*)(lstbeginnode->content))->name))
		lst1 = lstprime->nextr;
		lst1begi = lst1;
		while (lst1)
		{
			if (lstpath)
			{
//				while (lstpath)
				{
					s1 = ((t_node1*)(lstpath->content))->name;
					lst2 = lstpath->nextr;
					lst3 = lst1begi;
					while (lst3->next != lst1)
					{
						lst3 = lst3->next;
					}
					while (lst2->next)
					{
						lst2 = lst2->next;
					}
					if (ft_strcmp(((t_node1*)(lst3->content))->name,((t_node1*)(lst2->content))->name) == 0)
					{
						e = (t_node1*)malloc(sizeof(t_node1));
						lstmp1 = create_lst1(e);
						s1 = ((t_node1*)(lst1->content))->name;
						((t_node1*)(lstmp->content))->name = ft_strsub(((t_node1*)(lst1->content))->name, 0 , ft_strlen(s1));
						lst_add_downr(lst2, lst1);
					}
				}
			}
			else
			{
				e = (t_node1*)malloc(sizeof(t_node1));
				lstmp = create_lst2(e);
				s1 = ((t_node1*)(lstprime->content))->name;
				((t_node1*)(lstmp->content))->name = ft_strsub(((t_node1*)(lstprime->content))->name, 0 , ft_strlen(s1));
				lstpath = lst_add_downl(lstpath, lstmp);
				
				lst2 = lstpath->nextr;
				e = (t_node1*)malloc(sizeof(t_node1));
				lstmp1 = create_lst1(e);
				s1 = ((t_node1*)(lst1->content))->name;
				((t_node1*)(lstmp->content))->name = ft_strsub(((t_node1*)(lst1->content))->name, 0 , ft_strlen(s1));
				lst_add_downr(lst2, lstmp1);
			}
			lst1 = lst1->next;
		}
		ft_remove_if(&lstremain, lstprime);
		lstprime = lstprime->nextl;
		if (lstprime == 0 && lstremain != 0)
				lstprime = lstprimebegi;
	}
}
