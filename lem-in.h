/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:56 by syusof            #+#    #+#             */
/*   Updated: 2016/09/22 12:34:48 by syusof           ###   ########.fr       */
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
	struct s_node_path	*nextl;
	struct s_node_path	*nextr;
}						t_node_path;


t_lst		*create_lst1(void *content);
t_lst2		*create_lst2(void *content);
int		ft_checkremain(t_lst *lstremain, char *s);
char	*ft_makepath(char *str1,char *str2);
void	ft_remove_if(t_lst2 **lsta, t_lst2 *lstb);
t_node_path		*ft_createlst(char *s);
t_node_path		*lst_add_downl(t_node_path **node1,char *s);
t_node_path		*lst_add_downr(t_node_path **node1,char *s);
