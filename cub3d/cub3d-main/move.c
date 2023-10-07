/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:44:04 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/07 08:49:07 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    clear_window(t_all *all)
{
	uint32_t            col;
	uint32_t            row;

	row = -1;
	while (++row < all->game->img_2d->width)
	{
		col = -1;
		while (++col < all->game->img_2d->height)
		{
			mlx_put_pixel(all->game->img_2d, row, col, 0xFFFFFF);
		}
	}
}	

void	moving_hook(void *param)
{
	t_all *all;
	t_point des;
	all = param;


	des.x = cos(all->game->player_ang * (M_PI / 180));
	des.y = sin(all->game->player_ang * (M_PI / 180));

	if (mlx_is_key_down(all->game->mlx, MLX_KEY_W))
	{
		if (all->map[(int)(all->game->position.y + 3 * des.y + 1) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.y) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.x + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.y - 1) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.y) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.x - 1) / SQUARE_SIZE] != '1')
		{
			all->game->position.x += des.x;
			all->game->position.y += des.y;
		}
	}
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_D))
	{
		if (all->map[(int)(all->game->position.y + 3 * des.x + 1) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.x) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.y + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.x - 1) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.x) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.y - 1) / SQUARE_SIZE] != '1')
		{
			all->game->position.x -= des.y;
			all->game->position.y += des.x;
		}
	}
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_S))
	{
		if (all->map[(int)(all->game->position.y - 3 * des.y + 1) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.y) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.x + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.y - 1) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.y) / SQUARE_SIZE][(int)(all->game->position.x - 3 * des.x - 1) / SQUARE_SIZE] != '1')
		{
			all->game->position.x -= des.x;
			all->game->position.y -= des.y;
		}
	}
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_A))
	{
		if (all->map[(int)(all->game->position.y - 3 * des.x + 1) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.x) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.y + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.x - 1) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.x) / SQUARE_SIZE][(int)(all->game->position.x + 3 * des.y - 1) / SQUARE_SIZE] != '1')
		{
			all->game->position.x += des.y;
			all->game->position.y -= des.x;
		}
	}
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_LEFT))
	{
		all->game->player_ang =  bound_angle(all->game->player_ang + 3);
	}
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_RIGHT))
	{
		all->game->player_ang =  bound_angle(all->game->player_ang - 3);
	}
	printf("angle = %f\n", all->game->player_ang);
	build_window(all);
}

float	bound_angle(float angle)
{
	if (angle < 0) {
		angle += 360;
	}
	if (angle > 360) {
		angle = fmod(angle, 360);
	}
	return angle;
}
