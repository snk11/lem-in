/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:51:08 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 15:41:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "lem-in.h"

t_node	*ft_add_node_r(t_node **node1,char *line)
{
	int	i;
	int	j;
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	i = 0;
	j = 0;
	while(line[i] != '-')
		i++;
	s1 = (char*)malloc(sizeof(char)*i+1);
	i = 0;
	while(line[i] != '-')
	{
		s1[i] = line[i];
		i++;
	}
	s1[i] = 0;
	i++;
	j = 0;
	while(line[i] != '\n' && line[i] != EOF)
	{
		j++;
		i++;
	}
	i = i - j;
	s2 = (char*)malloc(sizeof(char)*j+1);
	j = 0;
	while(line[i] != '\n' && line[i] != EOF)
	{
		s2[j] = line[i];
		j++;
		i++;
	}
	s2[j] = 0;
	if (ft_checkdouble_r(ft_cursref_first(*node1,s1),s2))
		*node1 = lst_add_downr(node1,ft_cursref_first(*node1,s1),s2);
	if (ft_checkdouble_r(ft_cursref_first(*node1,s2),s1))
		*node1 = lst_add_downr(node1,ft_cursref_first(*node1,s2),s1);
	printf("tube = %s\n",line);
	return (*node1);
}
