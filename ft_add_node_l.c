/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:46:36 by syusof            #+#    #+#             */
/*   Updated: 2016/12/15 18:43:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "lem_in.h"

t_node	*ft_add_node_l(t_node **node1,char *line)
{
	int i;
	char	*s1;

	s1 = NULL;
	i = 0;
	while(line[i] != ' ')
		i++;
	s1 = (char*)malloc(sizeof(char)*i+1);
	i = 0;
	while(line[i] != ' ')
	{
		s1[i] = line[i];
		i++;
	}
	s1[i] = 0;
	if (ft_checkdouble_l(*node1,s1))
	{
		*node1 = lst_add_downl(node1,s1);
//		printf("room = %s\n",line);
	}
	return (*node1);
}
