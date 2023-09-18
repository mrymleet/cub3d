NAME=cub3d
CC=cc
libft=libft/libft.a
CFLAGS=-Wall -Wextra -Werror #-fsanitize=address
SRC= main.c\
get_next_line/get_next_line.c\
get_next_line/get_next_line_utils.c\
parsing/read_map.c parsing/read_map_1.c\
parsing/path.c\
parsing/map.c\
parsing/split_again.c\


OBJ=$(SRC:.c=.o)

all: $(NAME)

$(libft):
	make -C libft

$(NAME): $(OBJ) $(libft)
	$(CC) $(CFLAGS) $(OBJ) $(libft) -o $(NAME) $(ARG1)

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