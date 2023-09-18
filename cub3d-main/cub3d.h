#ifndef CUB3D
#define CUB3D

#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"


#include <stdio.h>
// #include <unistd.h>

typedef struct s_all
{
    char    **map;
    char    *line;
    char     **tmp;
    char       *str;

    int F;//wall
    int C;//space

    int NO;
    int SO;
    int EA;
    int WE;

    int wid;
    int count;

    int i;
    int j;

    int height;
    int width;

    void    *mlx;
    void    *win;
} t_all;

//parsing
void    read_map(char *str, t_all *all);
int     all_characters_exits(t_all *all);
int names_correct(t_all *all);

// int count_characters(t_all *all);
int check_path(t_all *all);
int check_numbers(t_all *all, char *str);//check characters
int only_num(char *str);
int count_virgules(char *str);

void    free_tmp(t_all *all);
int colors(t_all *all);
int check_map_characters(t_all *all);
int check_newlines(t_all *all);
int check_empty(t_all *all);
int check_empty_player(t_all *all);

// int is_space_or_tab(char c);
int identify_the_start(t_all *all);
char	**split_two(char *s);
int	surronded(t_all *all);

int string_empty(char *str);
int string_empty_one(char *str);
int identify_the_end(t_all *all);
void initialize_vars(t_all *all);
int path(t_all *all);
// int doesnt_belong(t_all *all);
int count_chars(t_all *all);
int empty(t_all *all, char c);
int up_down(t_all *all, int i); //check for the last one
int right_left(t_all *all, int i);
void    map_error(int err);
//----
char	**read_map_1(t_all all, char *path);
int     is_line_empty(char *line);
int	count_lines(char *path);

#endif