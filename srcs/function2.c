/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:02:46 by syusof            #+#    #+#             */
/*   Updated: 2017/01/05 00:34:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*lst_add_downl_room(t_room **node1, char *s)
{
	t_room	*nodetmp;
	t_room	*nodetmp2;

	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createnode_room(s);
	if (!(nodetmp2))
		return (nodetmp);
	while ((nodetmp2)->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	(nodetmp2)->nextl = nodetmp;
	return (*node1);
}

t_room		*ft_createnode_room(char *s)
{
	t_room	*curlst;

	curlst = NULL;
	if (!(curlst = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (s == NULL)
	{
		curlst->name = NULL;
	}
	else
	{
//		if (!(curlst->name = malloc(sizeof(char) * ft_strlen(s))))
//			return (NULL);
		curlst->name = ft_memmove2(s);
	}
	curlst->client = 0;
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}

t_room		*lst_add_down_downr_room(t_room **node1, char *s)
{
	t_room	*nodetmp;
	t_room	*nodetmp2;
	int		ind1;

	ind1 = 0;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createnode_room(s);
	if (!(nodetmp2))
		return (nodetmp);
	while (nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	while ((nodetmp2)->nextr)
		nodetmp2 = (nodetmp2)->nextr;
	(nodetmp2)->nextr = nodetmp;
	return (*node1);
}

t_node		*ft_createnode(char *s)
{
	t_node	*curlst;

	curlst = NULL;
	if (!(curlst = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	if (s == NULL)
	{
		curlst->name = NULL;
	}
	else
	{
//		if (!(curlst->name = malloc(sizeof(char) * ft_strlen(s))))
//			return (NULL);
		curlst->name = ft_memmove2(s);
	}
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}

t_node		*lst_add_downl(t_node **node1, char *s)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;

	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createnode(s);
	if (!(nodetmp2))
		return (nodetmp);
	while ((nodetmp2)->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	(nodetmp2)->nextl = nodetmp;
	return (*node1);
}
