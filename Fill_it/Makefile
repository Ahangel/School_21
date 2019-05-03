# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:46:51 by marvin            #+#    #+#              #
#    Updated: 2018/12/14 17:50:23 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h includes libft
vpath %.c srcs libft

FLAGS = -Wall -Wextra -Werror

NAME = fillit

OBJ = $(notdir $(patsubst %.c,%.o,$(wildcard srcs/*.c)))

LIB_OBJ = $(notdir $(patsubst %.c,%.o,$(wildcard libft/*.c)))

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	gcc $^ -o $@ 

%.o: %.c $(LIB)
	gcc $(FLAGS) -c $^ -Ilibft -Iincludes

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
