/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:42:42 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/07 19:17:16 by mel-moun         ###   ########.fr       */
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
			if (!col || !row)
			{
				if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
					&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
					mlx_put_pixel(canvas, (location.x + col) / SCALE, (location.y + row) / SCALE, 841372671);
			}
			else
			{
				if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
					&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
					mlx_put_pixel(canvas, (location.x + col) / SCALE, (location.y + row) / SCALE, color);
			}
		}
	}
}

void    draw_play(t_all *all, long color)
{
	int            col;
	int            row;
	t_point    location;
// printf("-->%f | %f\n", position.x, position.y);
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
	// draw_line(all);
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
	// printf("Player y= %f | x= %f\n", data->game->position.y, data->game->position.x);
	while (++i < WIDTH)
	{
		ray = ray_cast(data, var_ang);
		// ray.wall_hit_x = data->game->position.x + cos(data->game->player_ang * (M_PI / 180)) * SQUARE_SIZE;
		// ray.wall_hit_y = data->game->position.y + sin(data->game->player_ang * (M_PI / 180)) * SQUARE_SIZE;
		// printf("src -> x = %f | y = %f\n", data->game->position.x, data->game->position.y);
		// printf("dst -> x = %f | y = %f\n", ray.wall_hit_x, ray.wall_hit_y);
		// ray.distance = 10;
		draw_ray(data, data->game->position, ray);
		var_ang += ang_step;
		var_ang = bound_angle(var_ang);
	}
}



// void	draw_ray(t_all *data, t_point target)
// {
// 	float		step;
// 	t_point		p1;
// 	t_point		d;

// 	p1.x = (data->game->position.y);
// 	p1.y = (data->game->position.x);
// 	d.x = target.x - p1.x;
// 	d.y = target.y - p1.y;
// 	// step = fabs(d.y);
// 	// if (fabs(d.x) > fabs(d.y))
// 	// 	step = fabs(d.x);

// 	while (1)
// 	{
		
// 		if ((p1.x / SCALE > 0 && p1.x / SCALE < HEIGHT)
// 			&& (p1.y / SCALE > 0 && p1.y / SCALE < WIDTH))
// 			{
// 				if (data->map[(int)(p1.x + 1) / SQUARE_SIZE][(int)(p1.y) / SQUARE_SIZE] == '1'
// 				|| data->map[(int)p1.x / SQUARE_SIZE][(int)(p1.y + 1) / SQUARE_SIZE] == '1'
// 				|| data->map[(int)(p1.x - 1) / SQUARE_SIZE][(int)(p1.y) / SQUARE_SIZE] == '1'
// 				|| data->map[(int)p1.x / SQUARE_SIZE][(int)(p1.y - 1) / SQUARE_SIZE] == '1')
// 					break;
// 				mlx_put_pixel(data->game->img_2d, p1.y / SCALE,
// 					p1.x / SCALE, 0xFF0000FF);
// 			}
// 		p1.x += (d.x) / step;
// 		p1.y += (d.y) / step;
// 	}
// }




float	distace_two_points(t_point src, t_point dst)
{
	// printf("src -> x = %f | y = %f\n", src.x, src.y);
	// printf("dst -> x = %f | y = %f\n", dst.x, dst.y);
	return (sqrt(pow((src.x - dst.x), 2)
	+ pow((src.y - dst.y), 2)));
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


int ft_abs(float n)
{
	if (n > 0)
		return (n);
	else
		return (n * (-1));
}