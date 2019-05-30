# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crath <crath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 12:23:08 by crath             #+#    #+#              #
#    Updated: 2019/05/30 15:47:37 by crath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h includes

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_PATH = srcs
HEAD_PATH = includes

SRC = ft_putchar.c ft_putwchar.c ft_putnchar.c ft_putstr.c \
	  ft_strlen.c  ft_strdup.c ft_wstrlen.c ft_putwstr.c ft_strjoin.c\
	  ft_printf.c ft_read_format.c ft_create_format.c ft_print_format.c \
	  ft_print_c.c ft_print_s.c ft_print_num.c ft_print_f.c \
	  ft_print_dec.c ft_print_oct.c ft_print_hex.c ft_itoa.c ft_print_f2.c \
	  ft_memcpy.c

OBJ = $(patsubst %.c,%.o,$(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: $(SRC_PATH)/%.c
	gcc $(CFLAGS) -c $^ -o $@ -I$(HEAD_PATH)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
