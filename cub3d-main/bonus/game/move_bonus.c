/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:37:14 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/27 10:46:11 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	moving_hook(void *param)
{
	t_all		*all;
	t_point		des;

	all = param;
	des.x = cos(all->game->player_ang * (M_PI / 180));
	des.y = sin(all->game->player_ang * (M_PI / 180));
	clear(all);
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_W))
		move_up(all);
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_D))
		move_right(all);
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_S))
		move_down(all);
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_A))
		move_left(all);
	// mouse_hook(all);
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_LEFT))
		all->game->player_ang = bound_angle(all->game->player_ang - 3);
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_RIGHT))
		all->game->player_ang = bound_angle(all->game->player_ang + 3);
	build_window(all);
}

void	move_up(t_all *all)
{
	t_point		des;

	des.x = cos(all->game->player_ang * (M_PI / 180));
	des.y = sin(all->game->player_ang * (M_PI / 180));
	if (all->map[(int)(all->game->position.y + 3 * des.y + 1) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.y) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.x + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.y - 1) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.y) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.x - 1) / SQUARE_SIZE] != '1')
	{
		all->game->position.x += 2 * des.x;
		all->game->position.y += 2 * des.y;
	}
}

void	move_down(t_all *all)
{
	t_point		des;

	des.x = cos(all->game->player_ang * (M_PI / 180));
	des.y = sin(all->game->player_ang * (M_PI / 180));
	if (all->map[(int)(all->game->position.y - 3 * des.y + 1) / SQUARE_SIZE]
	[(int)(all->game->position.x - 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.y) / SQUARE_SIZE]
		[(int)(all->game->position.x - 3 * des.x + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.y - 1) / SQUARE_SIZE]
		[(int)(all->game->position.x - 3 * des.x) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.y) / SQUARE_SIZE]
		[(int)(all->game->position.x - 3 * des.x - 1) / SQUARE_SIZE] != '1')
	{
		all->game->position.x -= 2 * des.x;
		all->game->position.y -= 2 * des.y;
	}
}

void	move_right(t_all *all)
{
	t_point		des;

	des.x = cos(all->game->player_ang * (M_PI / 180));
	des.y = sin(all->game->player_ang * (M_PI / 180));
	if (all->map[(int)(all->game->position.y + 3 * des.x + 1) / SQUARE_SIZE]
	[(int)(all->game->position.x - 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.x) / SQUARE_SIZE]
		[(int)(all->game->position.x - 3 * des.y + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.x - 1) / SQUARE_SIZE]
		[(int)(all->game->position.x - 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y + 3 * des.x) / SQUARE_SIZE]
		[(int)(all->game->position.x - 3 * des.y - 1) / SQUARE_SIZE] != '1')
	{
		all->game->position.x -= 2 * des.y;
		all->game->position.y += 2 * des.x;
	}
}

void	move_left(t_all *all)
{
	t_point		des;

	des.x = cos(all->game->player_ang * (M_PI / 180));
	des.y = sin(all->game->player_ang * (M_PI / 180));
	if (all->map[(int)(all->game->position.y - 3 * des.x + 1) / SQUARE_SIZE]
	[(int)(all->game->position.x + 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.x) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.y + 1) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.x - 1) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.y) / SQUARE_SIZE] != '1'
		&& all->map[(int)(all->game->position.y - 3 * des.x) / SQUARE_SIZE]
		[(int)(all->game->position.x + 3 * des.y - 1) / SQUARE_SIZE] != '1')
	{
		all->game->position.x += 2 * des.y;
		all->game->position.y -= 2 * des.x;
	}
}
