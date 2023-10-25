/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:11:08 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/25 12:45:12 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "/Users/mel-moun/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 600

# define SQUARE_SIZE 50
# define PLAYER_SIZE 10
# define SCALE 3
# define STEP 2

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_double_point
{
	t_point	my_image;
	t_point	texture;
}	t_d_point;

typedef struct s_int_point
{
	int	x;
	int	y;
}	t_int_point;

typedef struct s_ray
{
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	float	angle;
	int		is_horz;
}	t_ray;

typedef struct s_game{
	mlx_t			*mlx;
	mlx_image_t		*img_2d;
	mlx_image_t		*img_3d;
	mlx_texture_t	*img;
	t_point			position;
	float			player_ang;
	t_ray			ray;
	int32_t			mouse_x;
	int32_t			mouse_y;
}	t_game;

typedef struct s_all
{
	char			**map;
	char			*line;
	char			**tmp;
	char			**cc;
	char			**cc1;
	char			*str;
	int				f;
	int				c;
	int				no;
	int				so;
	int				ea;
	int				we;
	int				wid;
	int				count;
	int				i;
	int				j;
	char			**final;
	char			**pics;
	char			player;
	int				floor[3];
	int				ciel[3];
	mlx_texture_t	*textures[4];
	t_game			*game;	
}	t_all;

//---------PARSING-----------------------

//reading map + to check its validity
void	read_map(char *str, t_all *all);
int		is_map_valid(t_all *all);
void	map_error(int err, t_all *all);

//check for 6 first characters
int		all_characters_exits(t_all *all);
int		names_correct(t_all *all);
int		check_path(t_all *all);
int		path(char *s);
int		colors(t_all *all);
int		count_virgules(char *str);
int		check_numbers(t_all *all, char *str);

//check validity of the map
int		identify_the_start(t_all *all);
int		check_map_characters(t_all *all);
int		count_chars(t_all *all);
int		check_newlines(t_all *all);
int		surronded(t_all *all);
int		up_down(t_all *all, int i);
int		right_left(t_all *all, int i);
int		check_empty(t_all *all);
int		empty(t_all *all, char c);
int		last_line(t_all *all);

//what raycaster needs
void	parsing(t_all *all);
void	store_player(t_all *all);
void	store_colors(t_all *all);
void	store_map(t_all *all);
void	exact_color(t_all *all, char *tmp);
void	store_colors_again(int i, char *tmp, t_all *all);
void	store_pictures(t_all *all);

//free stuffs
void	free_tmp(t_all *all);
void	free_map(t_all *all);
void	free_all_ccs(t_all *all);
void	free_pics(t_all *all);

//some string's manipulation
char	**split_two(char *s);
int		only_num(char *str);
int		check_num(char *tmp);
int		string_empty(char *str);
int		string_empty_one(char *str);
void	initialize_vars(t_all *all);
//-------------------------------------

int		count_lines(char *path);
void	create_window_and_images(t_all *all);
void	build_window(t_all *all);
void	draw_block(mlx_image_t *canvas, double point[2], long color);
void	draw_play(t_all *all, long color);
long	specify_color(char c);
void	close_window(void	*param);
void	clear_window(t_all *all);
void	clear(t_all *all);
void	moving_hook(void *param);
void	move_up(t_all *all);
void	move_down(t_all *all);
void	move_right(t_all *all);
void	move_left(t_all *all);
float	bound_angle(float angle);
void	draw_ray(t_all *data, t_point src, t_ray ray);
void	draw_rays(t_all *data);
float	distace_two_points(t_point src, t_point dst);
int		wall_detected(t_all *data, t_point src);
int		count_rows(char **str);
int		count_cols(char *str);
t_ray	ray_cast(t_all *data, float angle);
t_ray	get_inters_vertical(t_all *data, float angle);
t_ray	get_inters_horizontals(t_all *data, float angle);
void	build_wall(t_all *data, t_ray ray, int i);
void	draw_columns(t_all *data, t_point p, float height, t_ray ray);
void	draw_text(t_all *data, t_d_point d_point, float h, mlx_texture_t *tex);
void	get_wall_inters_v(t_all *data, t_point *p_intercept_v, float angle);
void	get_wall_inters_h(t_all *data, t_point *p_intercept_h, float angle);
void	increment(t_point *src, t_point d, float step);
uint8_t	*get_px_index(mlx_texture_t *tex, t_d_point d_point, t_int_point p1);
uint8_t	*get_pi_index(t_all *data, mlx_texture_t *tex, t_int_point p2);
void	init_data(t_all *all);
void	load_textures(t_all *all);
void	draw_square(t_all *all, int x, int y);
void	mouse_hook(t_all *all);
#endif