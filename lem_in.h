/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:39:56 by syusof            #+#    #+#             */
/*   Updated: 2016/12/22 17:21:19 by syusof           ###   ########.fr       */
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

typedef struct			s_map
{

	t_node				*nodestart;
	t_node				*nodeend;
	t_node				*noderoom;
	t_node				*nodetube;
}						t_map;

typedef struct			s_data
{
	int					nbant;
	char				*strbegi;
	char				*strend;
}						t_data;

typedef struct			s_pr
{
	t_node				*node2;
	t_node				*nodetmp;
	t_node				*nodedata;
	t_node				*nodedummie;
	t_node				*nodebest;
}						t_pr;

typedef struct			s_read
{
	int					fd;
	int					j;
	int					i;
	int					r1;
	int					r2;
	int					r3;
	int					r4;
	int					ant1;
	char				*s1;
	char				*line;
}						t_read;

typedef struct			s_screen
{
	t_node				*nodetmp;
	t_node				*nodetmp3;
	int					ind1;
	int					ind2;
}						t_screen;

typedef struct			s_scbest
{
	int	min;
	int	 index;
	int r;
	int i;
	int		countdirect;
	int	iter;
	int		indirect;
	int nbelemnodedata;
	t_node	*nodetmp;
	t_node	*nodetmp3;
	t_node	*numberlist;
}						t_scbest;


typedef struct			s_simul
{
	int nbelem;
	int nbtmp;
	int	r1;
	int cnt1;
	t_node *node1;
	t_node *node2;
	t_room *nodetmp;
	t_room *nodetmp3;
	t_room *nodetmp4;
	t_room *nodetmp5;
	t_room	*rooms;
	char	*s1;
}						t_simul;

typedef struct			s_swap
{
	t_node	*nodetmp3;
	t_node	*nodetmp4;
	t_node	*nodetmp5;
	t_node	*w;
	t_node	*z;
	int		cnt1;
	int		cnt2;
}						t_swap;

typedef struct			s_minpath
{
	t_node		*nodetmp;
	t_node		*nodetmp3;
	int			min;
	int			cnt;
	int			i;
	int			index;
}						t_minpath;

typedef struct			s_checkt
{
	int	i;
	int	j;
	char	*s1;
	char	*s2;
}						t_checkt;

typedef struct			s_checkr
{
	int i;
	int j;
	int k;
	char	*s1;
	char	*s2;
	t_node	*node2;
}						t_checkr;

typedef struct			s_crtroom
{
	t_node	*nodetmp;
	t_node	*nodetmp3;
	int		ind1;
}						t_crtroom;

typedef struct			s_mkstring
{
	char	*s1;
	char	*s2;
	int		nb1;
	int		nb2;
	int		i;
	int		j;
}						t_mkstring;

typedef struct			s_dmain
{
	t_node				*node2;
	t_node				*nodetmp;
	t_node				*nodedata;
	t_node				*nodedummie;
	t_node				*nodebest;
	t_data	data1;
	t_map	map1;
	char	*line;
}						t_dmain;

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
int		ft_countelem_lv1(t_node *node1);
t_node *ft_cursref(t_node *node1,t_node *noderef);
t_node *ft_cursref_first(t_node *node1,char *s);
void permute(char *a, int l, int r);
void swap(char *x, char *y);
t_node	*ft_maketree(t_node *maintree,char *strbegi);
t_node *ft_copytree(t_node *maintree,char *strbegi);
void permute2(t_node **nodetmp, t_node **nodedata,int r1,int r2,char *strbegi);
void	ft_swap2(t_node **nodetmp,char *s1,char *s2);
t_node	*ft_generate(t_node *node1,char *strbegi);
t_node		*ft_screen(t_node **nodedata, t_dmain dmain1);
t_node	*ft_screenbest(t_node **nodebest,t_node *nodedata,char *strend);
int		get_next_line(int const fd, char **line);
int		ft_checknbant(char *s);
int		ft_checktube1(char *s);
int		ft_checktube1_p1(char *s);
int		ft_checktube2(char *line,t_node *node1);
int		ft_checkroom(char *s);
int		ft_checkroom_p1(char *s);
int		ft_checkroom2(char *line, t_node **node1);
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
int	ft_read_map(t_node **node1,char *file,t_data *data1, t_map *map1);
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
int						ft_getminpath(t_node *nodetmp,t_node *numberlist, char *strend);
void					ft_getminpath_p1(t_minpath *minpath1, char *strend);
int						ft_checkdirect(t_node *node1, char *strend);
void					ft_simuldirect(t_node *nodebest,char *strbegi,char *strend,int totant);
int						ft_countelemroom_lvr(t_room *room1);
char					*ft_makestring(int nb, char *name);
void					ft_makestring_p1(t_mkstring *mkstring1, int nb, char *name);
void					ft_sort(t_node **node1);
void					ft_sort_p1(t_node **nodetmp3, int *r);
void					ft_swap2r(t_node **nodetmp,char *s1,char *s2);
void					ft_addseries(t_node **node2, t_node *node1);
void					ft_printsol(t_node *node);
void					ft_init2(t_map *map1);
void					ft_printmap(t_map map1, int nbant);
//void					ft_init3(t_pr *pr1);
void					ft_init4(t_read *read1);
void					ft_init5(t_screen *screen1);
void					ft_read_map_p1(t_read *read1);
void					ft_read_map_p2(t_read *read1, t_node **node1 , t_data *data1, t_map *map1);
void					ft_read_map_p2_p1(t_read *read1, t_node **node1, t_data *data1, t_map *map1);
void		ft_read_map_p3(t_read *read1, t_node **node1, t_data *data1, t_map *map1);
void		ft_read_map_p3_p1(t_read *read1, t_node **node1, t_data *data1, t_map *map1);
void						ft_read_map_p4(t_read *read1, t_node **node1, t_map *map1);
void					permute_p1(t_node **nodedata, t_node *nodetmp3);
void					ft_screen_p1(t_node *node1, t_screen *screen1, char *strend);
void					ft_screen_p2(t_node ***nodedata, t_screen *screen1);
void		ft_init6(t_scbest *scbest1);
void		ft_screenbest_p1(t_scbest *scbest1, t_node ***nodebest, t_node *nodedata, char *strend);
void		ft_screenbest_p1_p1(t_scbest *scbest1, t_node *nodedata, char *strend);
void		ft_screenbest_p1_p2(t_scbest *scbest1, t_node ***nodebest, char *strend);
void		ft_init7(t_simul *simul1);
void		ft_simul_p1(t_simul *simul1, char *strend, int totant);
void		ft_simul_p1_p0(t_simul *simul1);
void		ft_simul_p1_p42(t_simul *simul1, char *strend);
void		ft_simul_p1_p1(t_simul *simul1, char *strend, int totant);
void		ft_simul_p1_p1_p1(t_simul *simul1);
void		ft_simul_p1_p2(t_simul *simul1);
void		ft_simul_p1_p3(t_simul *simul1, int totant);
void		ft_simuldirect_p0(t_simul *simul1, t_node *nodebest, char *strend, int totant);
void		ft_simuldirect_p1(t_simul *simul1, int totant);
void		ft_simuldirect_p1_p1(t_simul *simul1, int totant);
void		ft_simuldirect_p2(t_simul *simul1, char *strend, int totant);
void		ft_simuldirect_p2_p0(t_simul *simul1);
void		ft_simuldirect_p2_p1(t_simul *simul1, char *strend);
void		ft_simuldirect_p2_p2(t_simul *simul1, char *strend, int totant);
void		ft_simuldirect_p2_p3(t_simul *simul1);
void		ft_simuldirect_p2_p4(t_simul *simul1, int totant);
void		ft_init8(t_swap *swap1);
void		ft_swap_p1(t_swap *swap1, t_node *nodetmp, char *s1, char *s2);
void		ft_swap_p2(t_swap *swap1, t_node ***nodetmp, char *s1);
void		ft_swap_p3(t_swap *swap1, t_node ***nodetmp, char *s2);
void		ft_swapr_p1(t_swap *swap1, t_node *nodetmp, char *s1, char *s2);
void		ft_swapr_p2(t_swap *swap1, t_node ***nodetmp, char *s1);
void		ft_swapr_p3(t_swap *swap1, t_node ***nodetmp, char *s2);
void		ft_init9(t_minpath *minpath1);
void		ft_init10(t_checkt *checkt1);
void		ft_checktube2_p1(t_checkt *checkt1, char *line);
void		ft_checktube2_p2(t_checkt *checkt1, char *line);
void		ft_init11(t_checkr *checkr1);
void		ft_checkroom2_p1(t_checkr *checkr1, char *line);
void		ft_checkroom2_p2(t_checkr *checkr1, char *line);
void		ft_createroom_p1(t_crtroom *crtroom1, t_room ***rooms, char *strend);
void		ft_createroom_p2(t_crtroom *crtroom1, t_room ***rooms, char *strend);
void		permute_p2(t_node **nodetmp3, int *r, int *r1);
void		ft_init12(t_dmain *dmain1);
void		ft_init3(t_mkstring *mkstring1);

#endif
