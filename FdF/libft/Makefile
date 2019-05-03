# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crath <crath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:50:53 by crath             #+#    #+#              #
#    Updated: 2019/03/03 15:58:56 by crath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 			ft_atoi.c \
				ft_atoi_array.c \
				ft_isprime.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_strlen.c \
				ft_memmove.c \
				ft_memdel.c \
				ft_memcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_strncpy.c \
				ft_isascii.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_isspace.c \
				ft_word_count.c \
				ft_swap.c \
				ft_memset.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_realloc.c \
				ft_binary_search.c \
				ft_qs_string.c \
				ft_quick_string.c \
				ft_qs.c \
				ft_bubblesort.c \
				ft_strndup.c \
				ft_copyuntil.c \
				ft_strjoinch.c \
				ft_numcount.c \
				ft_numlen.c \
				ft_strclen.c \
				ft_strclr.c \
				get_next_line.c \

HDR = libft.h

OFL = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLGS) -c $(SRC) -I $(HDR)
	@ar rc $(NAME) $(OFL)
	@ranlib $(NAME)

clean:
	/bin/rm -f $(OFL)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
