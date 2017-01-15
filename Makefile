# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:50:15 by syusof            #+#    #+#              #
#    Updated: 2017/01/15 22:08:12 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

SRCS = srcs/*.c

OFILES = *.o

FLAGS = -Wall -Werror -Wextra

MAIN = lem_in.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc $(FLAGS) -I libft/ -I includes/ -c $(SRCS)
	gcc -o $(NAME) $(OFILES)  -L libft/ -lft

clean:
	rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
