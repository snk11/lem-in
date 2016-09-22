/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:56 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 12:12:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_lst2
{
	void				*content;
	struct s_lst2		*nextl;
	struct s_lst		*nextr;
}						t_lst2;

typedef struct			s_node_path
{
	char				*name;
	struct s_node_path	*next;
}						t_node_path;


t_lst2		*lst_add_downl(t_lst2 *toplist, t_lst2 *t_lst1);
void		*lst_add_downr(t_lst *toplist, t_lst *t_lst1);
t_lst		*create_lst1(void *content);
t_lst2		*create_lst2(void *content);
int		ft_checkremain(t_lst *lstremain, char *s);
char	*ft_makepath(char *str1,char *str2);
void	ft_remove_if(t_lst2 **lsta, t_lst2 *lstb);
t_node_path		*ft_createlst(char *s);
t_node_path		*lst_add_down(t_node_path **node1,char *s);
