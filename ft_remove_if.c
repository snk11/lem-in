/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 19:52:44 by syusof            #+#    #+#             */
/*   Updated: 2016/06/29 20:05:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_remove_if(t_lst2 **lsta, t_lst2 *lstb)
{
	t_lst2 *lst;
	t_lst2 *lstmp1;

	while (ft_strcmp(((t_node1*)((*lsta)->content))->name,((t_node1*)(lstb->content))->name) == 0)
	{
		lstmp1 = (*lsta)->nextl;
		free(*lsta);
		*lsta = lstmp1;
	}
	if (*lsta)
	{
		lstmp1 = *lsta;
		lst = (*lsta)->nextl;
		while (lst)
		{
			if (ft_strcmp(((t_node1*)((*lsta)->content))->name,((t_node1*)(lstb->content))->name) == 0)
			{
				lstmp1->nextl = lst->nextl;
				free(lst);
				lst = lstmp1->nextl;
			}
			lstmp1 = lstmp1->nextl;
			if (lst)
				lst = lst->nextl;
		}
	}
}
