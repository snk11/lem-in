/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkremain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 17:08:07 by syusof            #+#    #+#             */
/*   Updated: 2016/06/29 17:57:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_checkremain(t_lst *lstremain, char *s)
{
	while (lstremain)
	{
		if (ft_strcmp(((t_node1*)(lstremain->content))->name,s) == 0)
			return (1);
		lstremain = lstremain->next;
	}
	return (0);
}
