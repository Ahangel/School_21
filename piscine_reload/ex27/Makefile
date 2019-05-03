# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crath <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 17:59:59 by crath             #+#    #+#              #
#    Updated: 2018/09/06 18:03:26 by crath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

FILE = ./main.c

OBJECT = ./main.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FILE)
	gcc $(FLAGS) -o $(NAME) $(OBJECT)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)
