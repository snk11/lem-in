/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 08:19:51 by syusof            #+#    #+#             */
/*   Updated: 2016/12/17 16:08:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

t_node    *ft_screen(t_node **nodedata,t_node *nodedummie,t_node *node1,char *strbegi,char *strend)
{
	t_screen	screen1;

	ft_init5(&screen1);
	screen1.nodetmp = nodedummie;
	while(screen1.nodetmp)
	{
		screen1.nodetmp3 = screen1.nodetmp;
		if (ft_strcmp(screen1.nodetmp->name,strbegi) == 0)
		{
			screen1.ind1 = 0;
			screen1.ind2 = 0;
			while(screen1.nodetmp && screen1.ind2 == 0 && screen1.ind1 == 0)
				ft_screen_p1(node1, &screen1, strend);
			screen1.nodetmp = screen1.nodetmp3;
			if (screen1.ind1 == 0 && screen1.ind2 == 1)
				ft_screen_p2(&nodedata, &screen1);
			screen1.nodetmp = screen1.nodetmp3;
		}
		screen1.nodetmp = screen1.nodetmp->nextl;
	}
	return (*nodedata);
}

void		ft_screen_p1(t_node *node1, t_screen *screen1, char *strend)
{
				while(screen1->nodetmp && screen1->nodetmp->nextr && screen1->ind2 == 0 && screen1->ind1 == 0)
				{
					if(ft_checknode2(ft_cursref_first(node1,screen1->nodetmp->name),(screen1->nodetmp->nextr)->name) == 0)
						screen1->ind1 = 1;
					if(ft_strcmp((screen1->nodetmp->nextr)->name,strend) == 0)
						screen1->ind2 = 1;
					screen1->nodetmp = screen1->nodetmp->nextr;
				}
				screen1->nodetmp = screen1->nodetmp->nextr;
}

void		ft_screen_p2(t_node ***nodedata, t_screen *screen1)
{
				**nodedata = lst_add_downlrnew(*nodedata,screen1->nodetmp->name);
				screen1->nodetmp = screen1->nodetmp->nextr;
				while(screen1->nodetmp)
				{
					**nodedata = lst_add_down_downr(*nodedata,screen1->nodetmp->name);
					screen1->nodetmp = screen1->nodetmp->nextr;
				}
}
