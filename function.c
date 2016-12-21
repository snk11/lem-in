/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:32:04 by syusof            #+#    #+#             */
/*   Updated: 2016/12/21 17:46:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"


#include <stdio.h>

void		ft_lstop_add_down(t_lst **toplist, char *s)
{
	t_op	*e;
	t_lst	*lstmp;
	t_lst		*lstmp2;
	int		i;

	i = 0;
	lstmp = NULL;
	lstmp2 = *toplist;
	e = (t_op*)malloc(sizeof(t_op));
	e->val = (char*)malloc(sizeof(char)*ft_strlen(s)+1);
	while(*s)
	{
		e->val[i] = *s;
		s++;
		i++;
	}
		lstmp = create_lst(e);
	if (*toplist == NULL)
		*toplist = lstmp;
	else
	{
		while(lstmp2 && lstmp2->next)
			lstmp2 = lstmp2->next;
		lstmp2->next = lstmp;
	}
}

t_lst		*create_lst(void *content)
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
//		if (!(curlst->content = malloc(sizeof(content))))
//			return (NULL);
//		curlst->content = ft_memmove(curlst->content, content, sizeof(content));
		curlst->content = ft_memmove2(content);
	}
	curlst->next = NULL;
	return (curlst);
}

t_node		*ft_remove_last_l(t_node **node1)
{
	t_node	*nodetmp;

	nodetmp = NULL;
	nodetmp = *node1;

	while(nodetmp && nodetmp->nextl && (nodetmp->nextl)->nextl)
		nodetmp = nodetmp->nextl;
	if(nodetmp)
		nodetmp->nextl = NULL;
	return (*node1);
}

t_node		*lst_add_downlrnew(t_node **node1,char *strbegi)
{
//	printf("newnormal\n");
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
//	if(*node1 == NULL)
	{
		*node1 = lst_add_downl(node1,strbegi);
		return (*node1);
	}
	/*
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
//	nodetmp = ft_createnode(nodetmp2->name);
//	nodetmp3 = nodetmp;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp4 = NULL;
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	nodetmp = nodetmp2->nextl;
	nodetmp3 = nodetmp;
	*node1 = lst_add_downl(node1,strbegi);
	return (*node1);
	*/
}

t_room		*lst_add_downlrnew_room(t_room **node1,char *strbegi)
{
//	printf("newnormal\n");
	t_room	*nodetmp;
	t_room	*nodetmp2;
	t_room	*nodetmp3;
	t_room	*nodetmp4;
	int		ind1;
	int cnt1;

	ind1 = 0;
	cnt1 = 0;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp4 = NULL;
//	if(*node1 == NULL)
	{
		*node1 = lst_add_downl_room(node1,strbegi);
		return (*node1);
	}
	/*
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
//	nodetmp = ft_createnode(nodetmp2->name);
//	nodetmp3 = nodetmp;
	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp4 = NULL;
	while(nodetmp2 && nodetmp2->nextl)
		nodetmp2 = (nodetmp2)->nextl;
	nodetmp = nodetmp2->nextl;
	nodetmp3 = nodetmp;
	*node1 = lst_add_downl_room(node1,strbegi);
	return (*node1);
	*/
}

t_room		*lst_add_downl_room(t_room **node1,char *s)
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
		if (!(curlst->name = malloc(sizeof(char) * ft_strlen(s))))
			return (NULL);
		curlst->name = ft_memmove(curlst->name, s, sizeof(char) * ft_strlen(s));
	}
	curlst->client = 0;
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}

t_room		*lst_add_down_downr_room(t_room **node1,char *s)
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
	while(nodetmp2 && nodetmp2->nextl)
	{
		nodetmp2 = (nodetmp2)->nextl;
	}

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
		if (!(curlst->name = malloc(sizeof(char) * ft_strlen(s))))
			return (NULL);
		curlst->name = ft_memmove(curlst->name, s, sizeof(char) * ft_strlen(s));
	}
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}

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

	if (nodetmp2)
	{
		while ((nodetmp2)->nextr)
			nodetmp2 = (nodetmp2)->nextr;
		(nodetmp2)->nextr = nodetmp;
	}
	return (*node1);
}

t_node		*lst_add_down_downr(t_node **node1,char *s)
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
	while(nodetmp2 && nodetmp2->nextl)
	{
		nodetmp2 = (nodetmp2)->nextl;
	}

	while ((nodetmp2)->nextr)
		nodetmp2 = (nodetmp2)->nextr;
	(nodetmp2)->nextr = nodetmp;
	return (*node1);
}
