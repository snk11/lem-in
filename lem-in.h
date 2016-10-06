/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:56 by syusof            #+#    #+#             */
/*   Updated: 2016/10/06 15:23:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

# define BUFF_SIZE 8192

typedef struct		s_env
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	int		index;
}					t_env;

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

typedef struct			s_node
{
	char				*name;
	struct s_node	*nextl;
	struct s_node	*nextr;
}						t_node;

typedef struct			s_data
{
	int					nbant;
	char				strbegi;
	char				strend;
}						t_data;

t_lst		*create_lst1(void *content);
t_lst2		*create_lst2(void *content);
t_node		*ft_createnode(char *s);
//t_path		*ft_createlstpath(char *s);
//t_path		*lst_add_down(t_path *path1);
t_node		*lst_add_downl(t_node **node1,char *s);
t_node		*lst_add_downr(t_node **node1,t_node *noderef,char *s);
t_node		*lst_add_down_downr(t_node **node1,char *s);
t_node		*lst_add_downlrnew(t_node **node1,char *strbegi);
int		ft_checknode(t_node *path1,char *s);
int		ft_checknode2(t_node *node,char *s);
void	ft_printfpath(t_node *path1begi);
t_node *ft_copytree(t_node *maintree,char *strbegi);
t_node	*ft_maketree(t_node *maintree,char *strbegi);
int		ft_countelem_lv1(t_node *node1);
t_node *ft_cursref(t_node *node1,t_node *noderef);
t_node *ft_cursref_first(t_node *node1,char *s);
void permute(char *a, int l, int r);
void swap(char *x, char *y);
t_node	*ft_maketree2(t_node *maintree,char *strbegi);
t_node *ft_copytree2(t_node *maintree,char *strbegi);
void permute2(t_node **nodetmp, t_node **nodedata,int r1,int r2);
void	swap2(t_node **nodetmp,char *s1,char *s2);
t_node	*ft_generate(t_node *node1,char *strbegi);
t_node	*ft_screen(t_node **nodedata,t_node *nodedummie,t_node *node1,char *strbegi,char *strend);
int		ft_checknode3(t_node *node,char *strend,char *s);
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend);
int		get_next_line(int const fd, char **line);
void			ft_read_map(char *file);
int		ft_checknbant(char *s);
int		ft_checktube(char *s);
int		ft_checkroom(char *s);
