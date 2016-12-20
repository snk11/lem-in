/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:55:54 by syusof            #+#    #+#             */
/*   Updated: 2016/12/20 12:59:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init6(t_scbest *scbest1)
{
	scbest1->numberlist = NULL;
	scbest1->nodetmp = NULL;
	scbest1->nodetmp3= NULL;
	scbest1->min = 0;
	scbest1->iter = 0;
	scbest1->nbelemnodedata = 0;
	scbest1->r = 0;
	scbest1->iter = 0;
	scbest1->countdirect = 0;
}
