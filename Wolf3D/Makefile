# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:22:13 by fmacgyve          #+#    #+#              #
#    Updated: 2019/03/17 15:45:16 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d
FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./srcs
OBJ_DIR		= ./obj
INCL_DIR	= ./includes

CFILES		= main.c wolf.c get_next_line.c read_map.c validate_map.c ray.c hooks.c movement.c rotating.c read_textures.c floor_casting.c read_music.c threads.c
OFILES		= $(CFILES:.c=.o)
HFILES		= get_next_line.h libft.h wolf3d.h

RAW_CFILES	= $(addprefix $(SRC_DIR)/,$(CFILES))
RAW_OFILES	= $(addprefix $(OBJ_DIR)/,$(OFILES))
RAW_HFILES	= $(addprefix $(INCL_DIR)/,$(HFILES))
SDL_LIBS	= $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image)
INCLUDES	= -I $(INCL_DIR)

all: $(OBJ_DIR) $(NAME) $(RAW_HFILES)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OFILES)
	make -C ./libft
	make -C ./maps
	gcc $(FLAGS) $(INCLUDES) $(RAW_OFILES) $(SDL_LIBS) $(shell sdl2-config --cflags --libs) -lSDL2 -lSDL2_image -lSDL2_mixer libft/libft.a  -o $(NAME)
	$(shell ./checkSDL.sh)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(RAW_HFILES) Makefile
	gcc $(FLAGS) $(INCLUDES) $(shell sdl2-config --cflags) -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./maps
	rm -f $(RAW_OFILES)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./maps
	rm -rf $(NAME)

re: fclean all
