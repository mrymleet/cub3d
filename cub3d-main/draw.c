/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:42:42 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/19 10:18:09 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_block(mlx_image_t *canvas, double point[2], long color)
{
	int            col;
	int            row;
	t_point    location;

	location.x = point[0];
	location.y = point[1];
	row = -1;
	while (++row < SQUARE_SIZE)
	{
		col = -1;
		while (++col < SQUARE_SIZE)
		{
			if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
				&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
				mlx_put_pixel(canvas, (location.x + col) / SCALE, (location.y + row) / SCALE, color);
		}
	}
}

void    draw_play(t_all *all, long color)
{
	int            col;
	int            row;
	t_point    location;

	location.x = all->game->position.x;
	location.y =  all->game->position.y;
	row = -1;
	while (++row < PLAYER_SIZE)
	{
		col = -1;
		while (++col < PLAYER_SIZE)
		{
			if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
					&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
					mlx_put_pixel( all->game->img_2d, (location.x + col) / SCALE, (location.y + row) / SCALE, color);
		}
	}
}

void    draw_rays(t_all *data)
{
	int            i;
	t_ray		ray;
	float		var_ang;
	float 		ang_step;

	ang_step = 60.0 / WIDTH;
	var_ang = data->game->player_ang - 30;
	var_ang = bound_angle(var_ang);
	i = -1;
	while (++i < WIDTH)
	{
		ray = ray_cast(data, var_ang);
		ray.distance = ray.distance
			* cos((var_ang - data->game->player_ang) * (M_PI / 180));
		draw_ray(data, data->game->position, ray);
		build_wall(data, ray, i);
		var_ang += ang_step;
		var_ang = bound_angle(var_ang);
	}
}

float	distace_two_points(t_point src, t_point dst)
{
	return (sqrt(pow((dst.x - src.x), 2) + pow((dst.y - src.y), 2)));
}



long	specify_color(char c)
{
	if (c == '0')
		return (0xFFFFFF);
	else if(c == '1')
		return (0x0000FF);
	else
		return (0x000000);

}
