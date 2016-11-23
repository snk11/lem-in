/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:56 by syusof            #+#    #+#             */
/*   Updated: 2016/11/23 14:12:35 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>

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

typedef struct			s_room
{
	char				*name;
	int				client;
	struct s_room	*nextl;
	struct s_room	*nextr;
}						t_room;
typedef struct			s_op
{
	char				*val;
}						t_op;

typedef struct			s_data
{
	int					nbant;
	char				*strbegi;
	char				*strend;
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
int		ft_checknode2(t_node *node,char *s);
int		ft_checknode3(t_node *node,char *strend,char *s);
int		ft_checknode4(t_node *node,char *strend,char *s);
int		ft_checknode5(t_node *node,char *s);
int		ft_checknode6(t_node *node,char *strend,char *s);
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
void permute2(t_node **nodetmp, t_node **nodedata,int r1,int r2,char *strbegi);
void	swap2(t_node **nodetmp,char *s1,char *s2);
t_node	*ft_generate(t_node *node1,char *strbegi);
t_node	*ft_screen(t_node **nodedata,t_node *nodedummie,t_node *node1,char *strbegi,char *strend);
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend);
int		get_next_line(int const fd, char **line);
int		ft_checknbant(char *s);
int		ft_checktube1(char *s);
int		ft_checktube1_p1(char *s);
int		ft_checktube2(char *line,t_node *node1);
int		ft_checkroom(char *s);
int		ft_checkroom_p1(char *s);
int		ft_checkroom2(char *line, t_node **node1, t_node **node2);
t_room		*lst_add_downlrnew_room(t_room **node1,char *strbegi);
t_room		*lst_add_downl_room(t_room **node1,char *s);
t_room		*ft_createnode_room(char *s);
t_room		*lst_add_down_downr_room(t_room **node1,char *s);
t_room	*ft_createroom(t_room **rooms,t_node *nodebest,char *strend);
void	ft_printfpath_room(t_room *path1begi);
void	ft_simul(t_node *nodebest,char *strbegi,char *strend,int nbant);
//t_node		*lst_rmtop(t_node **node1);
//t_node		*lst_rmnoderef(t_node **node1,t_node *noderef);
int	ft_checkzero(t_room *rooms);
int	ft_read_map(t_node **node1,char *file,t_data *data1);
int		ft_checknewant(t_room *room,t_room *node,int nbant);
int	ft_checkmindata(t_data data1);
int		ft_checkdouble_l(t_node *node,char *s);
int		ft_checkdouble_r(t_node *node,char *s);
t_node	*ft_add_node_l(t_node **node1,char *line);
t_node	*ft_add_node_r(t_node **node1,char *line);
t_node		*ft_remove_last_l(t_node **node1);
void		ft_lstop_add_down(t_lst **toplist, char *s);
t_lst		*create_lst(void *content);
int						ft_checkdigit(char *s);
int						ft_strlen_isdigit(char *s);
int						ft_checkint(char *s);
int						ft_checkint_p1(char *s1);
int						ft_checkint_p2(char *s1);
int						ft_checkint_p2_p1(char *s1);
int						ft_checkint_p2_p1_p1(char *s1);
int						ft_checkint_p2_p1_p4(char *s1);
int						ft_checkint_p2_p1_p7(char *s1);
int						ft_checkint_p2_p1_p42(char *s1);
int						ft_checkint_p2_p1_p8(char *s1);
int						ft_checkint_p2_p1_p3(char *s1);
int						ft_checkint_p2_p2(char *s1);
int						ft_checkint_p2_p2_p1(char *s1);
int						ft_checkint_p2_p2_p4(char *s1);
int						ft_checkint_p2_p2_p7(char *s1);
int						ft_checkint_p2_p2_p42(char *s1);
int						ft_checkint_p2_p2_p8(char *s1);
int						ft_checkint_p2_p2_p3(char *s1);
void					ft_init(t_data *data1);
int						ft_getminpath(t_node *nodedata, int minbest,char *strend);

#endif