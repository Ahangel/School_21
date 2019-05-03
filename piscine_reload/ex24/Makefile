# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crath <crath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:50:53 by crath             #+#    #+#              #
#    Updated: 2018/11/20 16:57:41 by crath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/*.c

OBJECT = ./*.o

FLAGS = -Wall -Wextra -Werror

HEADER = ./includes/

all: compile

compile:
	gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJECT)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
