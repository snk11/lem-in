/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:32:04 by syusof            #+#    #+#             */
/*   Updated: 2016/10/04 13:03:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"


#include <stdio.h>

t_node		*lst_add_downlrnewminus(t_node **node1, int p,char *strbegi)
{
	printf("newminus\n");
	t_node	*nodetmp;
	t_node	*nodetmp2;
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	int		ind1;
	int cnt1;

	ind1 = 0;
	cnt1 = 0;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp4 = NULL;
	if(*node1 == NULL)
	{
		*node1 = lst_add_downl(node1,strbegi);
		return (*node1);
	}
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
//	nodetmp = ft_createnode(nodetmp2->name);
//	nodetmp3 = nodetmp;
	while (nodetmp2 && (nodetmp2)->nextr)
	{
		nodetmp2 = (nodetmp2)->nextr;
		cnt1++;
	}
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp4 = NULL;
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp4 = NULL;
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	nodetmp = nodetmp2->nextl;
	nodetmp3 = nodetmp;
	*node1 = lst_add_downl(node1,strbegi);
	ft_printfpath(*node1);
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
		if (!(curlst->name = malloc(sizeof(s))))
			return (NULL);
		curlst->name = ft_memmove(curlst->name, s, sizeof(s));
	}
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}

/*
t_path		*ft_createlstpath(char *s)
{
	t_path	*curlst;

	curlst = NULL;
	if (!(curlst = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	if (s == NULL)
	{
		curlst->name = NULL;
	}
	else
	{
		if (!(curlst->name = malloc(sizeof(s))))
			return (NULL);
		curlst->name = ft_memmove(curlst->name, s, sizeof(s));
	}
	curlst->next = NULL;
	return (curlst);
}

t_path		*lst_add_down(t_path *path1)
{
	t_path	*pathtmp;

	pathtmp = NULL;
	pathtmp = ft_createlstpath(path1->name);
	if (!path1)
		return (pathtmp);
	while (path1)
		path1 = (path1)->next;
	path1->next = pathtmp;
	return (pathtmp);
}
*/

t_node		*lst_add_downl(t_node **node1,char *s)
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

t_node		*lst_add_downr(t_node **node1,t_node *noderef,char *s)
{
	t_node	*nodetmp;
	t_node	*nodetmp2;
	int		ind1;

	ind1 = 0;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createnode(s);
	if (!(nodetmp2))
		return (nodetmp);
	while(nodetmp2 && ind1 == 0)
	{
		if(ft_strcmp((nodetmp2)->name,(noderef)->name) == 0)
			ind1 = 1;
		else
			nodetmp2 = (nodetmp2)->nextl;
	}

	while ((nodetmp2)->nextr)
		nodetmp2 = (nodetmp2)->nextr;
	(nodetmp2)->nextr = nodetmp;
	return (*node1);
}

t_lst		*create_lst1(void *content)
{
	t_lst	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
	}
	else
	{
		if (!(curlst->content = malloc(sizeof(content))))
			return (NULL);
		curlst->content = ft_memmove(curlst->content, content, sizeof(content));
	}
	curlst->next = NULL;
	return (curlst);
}
t_lst2		*create_lst2(void *content)
{
	t_lst2	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lst2*)malloc(sizeof(t_lst2))))
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
	}
	else
	{
		if (!(curlst->content = malloc(sizeof(content))))
			return (NULL);
		curlst->content = ft_memmove(curlst->content, content, sizeof(content));
	}
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}
