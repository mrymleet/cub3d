# NAME=cub3d
# CC=cc
libft=libft/libft.a
# CFLAGS=-Wall -Wextra -Werror -g -fsanitize=address
# ARGS= -I $(MLX42)/include $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm
# MLX42 = /Users/$(USER)/MLX42

NAME	= cub3D

CC		:= cc
FLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast #-fsanitize=address -g
LIBMLX	:= /Users/$(USER)/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDES = -I $(LIBMLX)/include


SRC= main.c\
get_next_line/get_next_line.c\
parsing/check_map/characters.c parsing/check_map/empty_zero_one.c parsing/check_map/newlines.c parsing/check_map/surronded.c\
parsing/final_parse/store_colors.c parsing/final_parse/store_map.c parsing/final_parse/store_pictures.c parsing/final_parse/store_player.c parsing/final_parse/to_raycasting.c\
parsing/six_characters/colors.c parsing/six_characters/existance.c parsing/six_characters/path.c\
parsing/others/free.c parsing/others/read_map.c parsing/others/split.c parsing/others/string.c\
game/build.c game/draw.c game/move.c \
game/ray_casting/ray_cast.c game/ray_casting/get_inters_horizontals.c game/ray_casting/get_inters_verticals.c\
game/build_3d.c \
game/clearing.c game/utils.c \
parsing/read_map_1.c\

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(libft):
	make -C libft

$(NAME): $(OBJ) $(libft)
	$(CC) $(FLAGS) $(INCLUDES) $(libft) $(OBJ) $(LIBS) -o $(NAME)
#-framework Cocoa -framework OpenGL -framework IOKit
%.o: %.c
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ)


fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean  all

.PHONY: all clean fclean re bonus
