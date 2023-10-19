#ifndef CUB3D
#define CUB3D

#include <fcntl.h>
# include <math.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "/Users/mdenguir/MLX42/include/MLX42/MLX42.h"
#include <string.h> // ................to remove
#include <stdio.h>
// #include <unistd.h>
#define WIDTH 1200
#define HEIGHT 600

#define SQUARE_SIZE 50
#define PLAYER_SIZE 10
#define SCALE 3
#define STEP 2

typedef struct s_point
{
	float x;
	float y;
} t_point;

typedef struct s_double_point
{
	t_point my_image;
	t_point texture;
} t_d_point;

typedef struct s_int_point
{
	int x;
	int y;
} t_int_point;

typedef struct s_ray
{
	float wall_hit_x;
	float wall_hit_y;
	float distance;
	float	angle;
	int is_horz;
	// int		is_facing_down;
	// int		is_facing_up;
	// int		is_facing_right;
	// int		is_facing_left;
}	t_ray;

typedef struct s_game{
	mlx_t    *mlx;
	mlx_image_t     *img_2d;
	mlx_image_t     *img_3d;
	mlx_texture_t	*img;
	// mlx_texture_t	*SO;
	// mlx_texture_t	*WE;
	// mlx_texture_t	*EA;
	t_point    position;
	float		player_ang;
	t_ray		ray;
}	t_game;

	

typedef struct s_all
{
	char    **map;
	char    *line;
	char     **tmp;
	char       *str;
	mlx_texture_t	*textures[4];

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
	t_game  *game;
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
char	**read_map_1(t_all *all, char *path);
int     is_line_empty(char *line);
int	count_lines(char *path);
void	free_2_dimensions(char **str);
int	ft_get_width(char **s);
int	ft_get_height(char **s);


void	create_window_and_images(t_all *all);
void	build_window(t_all *all);
void    draw_block(mlx_image_t *canvas, double point[2], long color);
void    draw_play(t_all *all, long color);
long    specify_color(char c);
void	close_window(void* param);
void    clear_window(t_all *all);
void	clear(t_all *all);
void	moving_hook(void *param);
void	move_up(t_all *all);
void	move_down(t_all *all);
void	move_right(t_all *all);
void	move_left(t_all *all);

float	bound_angle(float angle);
void    draw_ray(t_all *data, t_point src, t_ray ray);
void    draw_rays(t_all *data);

float	distace_two_points(t_point src, t_point dst);
int	wall_detected(t_all *data, t_point src);
int count_rows(char **str);
int count_cols(char *str);
t_ray    ray_cast(t_all *data, float angle);
t_ray   get_inters_vertical(t_all *data, float angle);
t_ray   get_inters_horizontals(t_all *data, float angle);
void    build_wall(t_all *data, t_ray ray, int i);
void	draw_columns(t_all *data, t_point p, float height, t_ray ray);
void	draw_text(t_all *data, t_d_point d_point, float h, mlx_texture_t *tex);
void    get_wall_inters_v(t_all *data, t_point *p_intercept_v, float angle);
void    get_wall_inters_h(t_all *data, t_point *p_intercept_h, float angle);
void	increment(t_point *src, t_point d, float step);
uint8_t	*get_px_index(mlx_texture_t *tex, t_d_point d_point, t_int_point p1);
uint8_t	*get_pi_index(t_all *data, mlx_texture_t *tex, t_int_point p2);

#endif