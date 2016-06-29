/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:32:04 by syusof            #+#    #+#             */
/*   Updated: 2016/06/29 19:37:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

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
