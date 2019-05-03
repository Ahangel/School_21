# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crath <crath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 19:45:34 by crath             #+#    #+#              #
#    Updated: 2019/03/03 15:57:58 by crath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	make_fdf.c		\
		all_output.c	\
		all_math.c

all: $(NAME)

$(NAME): lib mlx
	@cd src && gcc -Wall -Wextra -Werror -c $(SRC) -g
	cd src && gcc $(SRC:.c=.o) -g -L../minilibx -lmlx -framework OpenGL -framework AppKit -L../libft -lft -o $(NAME)
	mv src/fdf .

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd src && /bin/rm -f $(SRC:.c=.o)

fclean: clean
	@cd libft && make fclean
	@cd minilibx && make clean
	@/bin/rm -f $(NAME)

re: fclean all
