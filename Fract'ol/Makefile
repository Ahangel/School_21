# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crath <crath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 13:15:32 by crath             #+#    #+#              #
#    Updated: 2019/03/07 16:57:30 by crath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = \
		for_burningship.c		\
		all_hooks.c	\
		for_julia.c \
		main.c \
		for_mandelbrot.c \
		help_functions.c

all: $(NAME)

$(NAME): lib mlx
	@cd srcs && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd srcs && clang $(SRCS:.c=.o) -g -L../minilibx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -o $(NAME)
	mv srcs/fractol .

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd srcs && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@cd minilibx && make clean
	@/bin/rm -f $(NAME)

re: fclean all

