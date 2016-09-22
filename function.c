/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:32:04 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 12:12:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

t_node_path		*ft_createlst(char *s)
{
	t_node_path	*curlst;

	curlst = NULL;
	if (!(curlst = (t_node_path*)malloc(sizeof(t_node_path))))
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

t_node_path		*lst_add_down(t_node_path **node1,char *s)
{
	t_node_path	*nodetmp;
	t_node_path	*nodetmp2;

	nodetmp2 = *node1;
	nodetmp = NULL;
	nodetmp = ft_createlst(s);
	if (!(*node1))
		return (nodetmp);
	while (node1)
		*node1 = (*node1)->next;
	(*node1)->next = nodetmp;
	return (nodetmp2);
}

t_lst2		*lst_add_downl(t_lst2 *toplist, t_lst2 *lst1)
{
	char		*s1;
	t_lst2		*lstmp;

	lstmp = NULL;
	lstmp = create_lst2((lst1)->content);
	s1 = ((t_node1*)(lst1->content))->name;
	((t_node1*)(lstmp->content))->name = ft_strsub(((t_node1*)(lst1->content))->name, 0 , ft_strlen(s1));
	if (!toplist)
		return (lstmp);
	while (toplist)
		toplist = toplist->nextl;
	toplist->nextl = lstmp;
	return (lstmp);
}

void		*lst_add_downr(t_lst *toplist, t_lst *lst1)
{
	char		*s1;
	t_lst		*lstmp;

	lstmp = NULL;
	lstmp = create_lst1((lst1)->content);
	s1 = ((t_node1*)(lst1->content))->name;
	((t_node1*)(lstmp->content))->name = ft_strsub(((t_node1*)(lst1->content))->name, 0 , ft_strlen(s1));
	if (!toplist)
		return (lstmp);
	while (toplist)
		toplist = toplist->next;
	toplist->next = lstmp;
	return (lstmp);
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
