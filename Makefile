# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:50:15 by syusof            #+#    #+#              #
#    Updated: 2017/01/15 23:35:08 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

FILES = ft_add_node_l.c ft_add_node_r.c ft_addseries.c ft_checkdigit.c \
		ft_checkdirect.c ft_checkdouble_l.c ft_checkdouble_r.c \
		ft_checkint.c ft_checkint1.c ft_checkint2.c ft_checkint3.c \
		ft_checkmindata.c ft_checknbant.c ft_checknewant.c ft_checknode.c \
		ft_checkroom.c ft_checkroom2.c ft_checktube.c ft_checkzero.c \
		ft_copytree.c ft_countelem_lv1.c ft_countelem_lvr.c \
		ft_countelemroom_lvr.c ft_createroom.c ft_cursref.c ft_del_first.c \
		ft_del_last.c ft_dfs.c ft_dijkstra.c ft_generate2.c ft_getminpath.c \
		ft_init.c ft_init2.c ft_init3.c ft_makestring.c ft_maketree.c \
		ft_node_add_wholer.c ft_printmap.c ft_printsol.c ft_read_map.c \
		ft_read_map1.c ft_read_map2.c ft_screen.c ft_screenbest.c \
		ft_simuldirect.c ft_simuldirect2.c ft_sort.c ft_sortpath.c \
		ft_strlen_isdigit.c ft_swap.c ft_swappath.c ft_swapr.c function.c \
		function2.c function3.c get_next_line.c lem_in.c

SRCS = $(addprefix srcs/, $(FILES))

OFILES = ft_add_node_l.o ft_add_node_r.o ft_addseries.o ft_checkdigit.o \
		 ft_checkdirect.o ft_checkdouble_l.o ft_checkdouble_r.o \
		 ft_checkint.o ft_checkint1.o ft_checkint2.o ft_checkint3.o \
		 ft_checkmindata.o ft_checknbant.o ft_checknewant.o ft_checknode.o \
		 ft_checkroom.o ft_checkroom2.o ft_checktube.o ft_checkzero.o \
		 ft_copytree.o ft_countelem_lv1.o ft_countelem_lvr.o \
		 ft_countelemroom_lvr.o ft_createroom.o ft_cursref.o ft_del_first.o \
		 ft_del_last.o ft_dfs.o ft_dijkstra.o ft_generate2.o ft_getminpath.o \
		 ft_init.o ft_init2.o ft_init3.o ft_makestring.o ft_maketree.o \
		 ft_node_add_wholer.o ft_printmap.o ft_printsol.o ft_read_map.o \
		 ft_read_map1.o ft_read_map2.o ft_screen.o ft_screenbest.o \
		 ft_simuldirect.o ft_simuldirect2.o ft_sort.o ft_sortpath.o \
		 ft_strlen_isdigit.o ft_swap.o ft_swappath.o ft_swapr.o function.o \
		 function2.o function3.o get_next_line.o lem_in.o

FLAGS = -Wall -Werror -Wextra

MAIN = lem_in.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc $(FLAGS) -I libft/ -I includes/ -c $(SRCS)
	@gcc -o $(NAME) $(OFILES)  -L libft/ -lft
	@echo "-- done --"

clean:
	@rm -f $(OFILES)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
