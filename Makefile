# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:50:15 by syusof            #+#    #+#              #
#    Updated: 2017/02/08 22:16:52 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

LIB = libft/libft.a

OBJ = ft_add_node_l.o ft_add_node_r.o ft_addseries.o ft_checkdigit.o \
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

VPATH = srcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "-- done --"

$(LIB):
	@make -C libft/

%.o: %.c
		@gcc $(FLAGS) -I libft/ -I includes -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
