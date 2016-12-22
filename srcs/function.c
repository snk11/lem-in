/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:32:04 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 18:10:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_lstop_add_down(t_lst **toplist, char *s)
{
	t_op	*e;
	t_lst	*lstmp;
	t_lst	*lstmp2;
	int		i;

	i = 0;
	lstmp = NULL;
	lstmp2 = *toplist;
	e = (t_op*)malloc(sizeof(t_op));
	e->val = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (*s)
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
		while (lstmp2 && lstmp2->next)
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
		curlst->content = NULL;
	else
		curlst->content = ft_memmove2(content);
	curlst->next = NULL;
	return (curlst);
}

t_node		*ft_remove_last_l(t_node **node1)
{
	t_node	*nodetmp;

	nodetmp = NULL;
	nodetmp = *node1;
	while (nodetmp && nodetmp->nextl && (nodetmp->nextl)->nextl)
		nodetmp = nodetmp->nextl;
	if (nodetmp)
		nodetmp->nextl = NULL;
	return (*node1);
}

t_node		*lst_add_downlrnew(t_node **node1, char *strbegi)
{
	*node1 = lst_add_downl(node1, strbegi);
	return (*node1);
}

t_room		*lst_add_downlrnew_room(t_room **node1, char *strbegi)
{
	*node1 = lst_add_downl_room(node1, strbegi);
	return (*node1);
}
