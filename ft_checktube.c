/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:14:07 by syusof            #+#    #+#             */
/*   Updated: 2016/12/21 15:09:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int		ft_checktube1(char *s)
{
	int	t;
	t = 0;
	while(*s && *s != ' ' && *s != '\t')
	{
		if (ft_checktube1_p1(s) == 0)
			return (0);
		if(*s == '-')
			t++;
		if (t > 1)
			return (0);
		s++;
	}
	if(t == 0)
		return (0);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s)
		return (0);
	return (1);
}

int		ft_checktube1_p1(char *s)
{
	while (*s && *s != '-' && *s != ' ' && *s != '\t')
	{
		if (!ft_isalnum(*s))
			return (0);
		s++;
	}
	return (1);
}

int		ft_checktube2(char *line,t_node *node1)
{
	t_checkt checkt1;

	ft_init10(&checkt1);
	if(ft_checktube1(line))
	{
		checkt1.i = 0;
		ft_checktube2_p1(&checkt1, line);
		ft_checktube2_p2(&checkt1, line);
		if (ft_cursref_first(node1,checkt1.s1) == NULL)
			return (0);
		if (ft_cursref_first(node1,checkt1.s2) == NULL)
			return (0);
	}
	else
		return (0);
	return (1);
}

void		ft_checktube2_p1(t_checkt *checkt1, char *line)
{
		while(line[checkt1->i] != '-')
			checkt1->i++;
		checkt1->s1 = (char*)malloc(sizeof(char)*checkt1->i+1);
		checkt1->i = 0;
		while(line[checkt1->i] != '-')
		{
			(checkt1->s1)[checkt1->i] = line[checkt1->i];
			checkt1->i++;
		}
		(checkt1->s1)[checkt1->i] = 0;
		checkt1->i++;
		checkt1->j = 0;
		while(line[checkt1->i] && line[checkt1->i] != EOF && line[checkt1->i] != ' ' && line[checkt1->i] != '\t')
		{
			checkt1->j++;
			checkt1->i++;
		}
}

void		ft_checktube2_p2(t_checkt *checkt1, char *line)
{
		checkt1->i = checkt1->i - checkt1->j;
		checkt1->s2 = (char*)malloc(sizeof(char)*checkt1->j+1);
		checkt1->j = 0;
		while(line[checkt1->i] && line[checkt1->i] != EOF && line[checkt1->i] != ' ' && line[checkt1->i] != '\t')
		{
			(checkt1->s2)[checkt1->j] = line[checkt1->i];
			checkt1->j++;
			checkt1->i++;
		}
		checkt1->s2[checkt1->j] = 0;
}
