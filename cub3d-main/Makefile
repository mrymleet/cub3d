NAME=cub3d
CC=cc
libft=libft/libft.a
CFLAGS=-Wall -Wextra -Werror #-g -fsanitize=address
ARGS= -Iinclude -lglfw  -L"/Users/mdenguir/goinfre/homebrew/opt/glfw/lib"
MLX42 = /Users/mdenguir/MLX42/build/libmlx42.a
SRC= main.c\
get_next_line/get_next_line.c\
get_next_line/get_next_line_utils.c\
parsing/read_map.c parsing/read_map_1.c\
parsing/path.c\
parsing/map.c\
parsing/split_again.c\
build.c draw.c move.c \
ray_casting/ray_cast.c ray_casting/get_inters_horizontals.c ray_casting/get_inters_verticals.c\
build_3d.c \

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(libft):
	make -C libft

$(NAME): $(OBJ) $(libft) cub3d.h
	$(CC) $(CFLAGS) $(OBJ) $(libft) $(ARGS) $(MLX42) -o $(NAME) 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ)


fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean  all

.PHONY: all clean fclean re bonus