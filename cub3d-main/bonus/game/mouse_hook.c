/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:03 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/25 16:34:08 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	mouse_hook(t_all *all)
{
	int32_t		tmp_mouse;

	tmp_mouse = all->game->mouse_x;
	mlx_get_mouse_pos(all->game->mlx, &all->game->mouse_x, &all->game->mouse_y);
	if (tmp_mouse > all->game->mouse_x)
	{
		if (all->game->mouse_x < WIDTH && all->game->mouse_x >= 0
			&& all->game->mouse_y < HEIGHT && all->game->mouse_y >= 0)
			all->game->player_ang = bound_angle(all->game->player_ang - 3);
	}
	if (tmp_mouse < all->game->mouse_x)
	{
		if (all->game->mouse_x < WIDTH && all->game->mouse_x >= 0
			&& all->game->mouse_y < HEIGHT && all->game->mouse_y >= 0)
			all->game->player_ang = bound_angle(all->game->player_ang + 3);
	}
}