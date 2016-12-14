/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:14:07 by syusof            #+#    #+#             */
/*   Updated: 2016/12/14 17:59:26 by syusof           ###   ########.fr       */
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
	int	i;
	int	j;
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	i = 0;
	j = 0;
	if(ft_checktube1(line))
	{
		i = 0;
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
//		printf("line[i] = %s\n",&(line[i]));
		while(line[i] && line[i] != EOF && line[i] != ' ' && line[i] != '\t')
		{
			j++;
			i++;
		}
//		printf("j = %d, i = %d\n", j, i);
		i = i - j;
		s2 = (char*)malloc(sizeof(char)*j+1);
		j = 0;
		while(line[i] && line[i] != EOF && line[i] != ' ' && line[i] != '\t')
		{
			s2[j] = line[i];
			j++;
			i++;
		}
		s2[j] = 0;
//		printf("s2 = %s\n",s2);
		if (ft_cursref_first(node1,s1) == NULL)
			return (0);
		if (ft_cursref_first(node1,s2) == NULL)
			return (0);
	}
	else
		return (0);
	return (1);
}
