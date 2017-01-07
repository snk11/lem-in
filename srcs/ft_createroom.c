/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:53:59 by syusof            #+#    #+#             */
/*   Updated: 2017/01/07 12:05:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_createroom(t_room **rooms, t_node *nodebest, char *strend)
{
	t_crtroom	crtroom1;

	crtroom1.nodetmp = NULL;
	crtroom1.nodetmp = nodebest;
	while (crtroom1.nodetmp)
	{
		crtroom1.ind1 = 0;
		ft_createroom_p1(&crtroom1, &rooms, strend);
		ft_createroom_p2(&crtroom1, &rooms, strend);
		crtroom1.nodetmp = crtroom1.nodetmp3;
		crtroom1.nodetmp = (crtroom1.nodetmp)->nextl;
	}
	return (*rooms);
}

void		ft_createroom_p1(t_crtroom *crtroom1, t_room ***rooms, char *strend)
{
	crtroom1->nodetmp3 = crtroom1->nodetmp;
	crtroom1->nodetmp = crtroom1->nodetmp->nextr;
	while (crtroom1->nodetmp
			&& ft_strcmp(crtroom1->nodetmp->name, strend) != 0
			&& crtroom1->ind1 == 0)
	{
		crtroom1->ind1 = 1;
		**rooms = lst_add_downl_room(*rooms, crtroom1->nodetmp->name);
		crtroom1->nodetmp = crtroom1->nodetmp->nextr;
	}
	while (crtroom1->nodetmp
			&& ft_strcmp(crtroom1->nodetmp->name, strend) != 0)
	{
		**rooms = lst_add_down_downr_room(*rooms, crtroom1->nodetmp->name);
		crtroom1->nodetmp = crtroom1->nodetmp->nextr;
	}
}

void		ft_createroom_p2(t_crtroom *crtroom1, t_room ***rooms, char *strend)
{
	if (crtroom1->nodetmp && ft_strcmp(crtroom1->nodetmp->name, strend) == 0)
	{
		if (crtroom1->ind1 == 0)
		{
			**rooms = lst_add_downl_room(*rooms
					, crtroom1->nodetmp->name);
			crtroom1->nodetmp = crtroom1->nodetmp->nextr;
		}
		else if (crtroom1->ind1 == 1)
		{
			**rooms = lst_add_down_downr_room(*rooms
					, crtroom1->nodetmp->name);
			crtroom1->nodetmp = crtroom1->nodetmp->nextr;
		}
	}
}
