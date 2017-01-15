# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:50:15 by syusof            #+#    #+#              #
#    Updated: 2017/01/15 23:29:15 by syusof           ###   ########.fr        #
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

OFILES = *.o

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
