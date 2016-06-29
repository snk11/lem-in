/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/06/29 19:19:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_proceed(t_lst2 *lstpath, t_lst2 *lstremain)
{
	char	*s1;
	t_node1		*e;
	t_lst2		*lstmp;
	t_lst		*lstmp1;
	t_lst		*lst1;
	t_lst		*lst3;
	t_lst		*lst1begi;
	t_lst		*lst2;

	lst1 = NULL;
	lstremain = lstremain->nextl;
	while (lstremain)
	{
//		while (lstbeginnode && ft_checkremain(lstremain, ((t_node1*)(lstbeginnode->content))->name))
		lst1 = lstremain->nextr;
		lst1begi = lst1;
		while (lst1)
		{
			lst1 = lstremain->nextr;
			if (lstpath)
			{
				while (lstpath)
				{
					s1 = ((t_node1*)(lstpath->content))->name;
					lst2 = lstpath->nextr;
					lst3 = lst1begi;
					while (lst3->next != lst1)
					{
						lst3 = lst3->next;
					}
					while (lst2)
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
				s1 = ((t_node1*)(lstremain->content))->name;
				((t_node1*)(lstmp->content))->name = ft_strsub(((t_node1*)(lstremain->content))->name, 0 , ft_strlen(s1));
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
		lstremain = lstremain->nextl;
	}
}
