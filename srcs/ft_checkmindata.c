/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmindata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 18:53:01 by syusof            #+#    #+#             */
/*   Updated: 2016/12/23 04:40:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_checkmindata(t_data data1)
{
	if (data1.nbant == 0)
	{
		printf("nbantKO\n");
		return (0);
	}
	if (data1.strbegi == NULL)
	{
		printf("strbegiKO\n");
		return (0);
	}
	if (data1.strend == NULL)
	{
		printf("strendKO\n");
		return (0);
	}
	return (1);
}
