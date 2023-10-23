/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:04:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/23 11:54:22 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(t_all *all)
{
	all->game->position.x = -1;
	all->game->position.y = -1;
	all->game->mouse_x = 0;
	all->game->mouse_y = 0;
	if (all->player == 'N')
		all->game->player_ang = 270;
	else if (all->player == 'W')
		all->game->player_ang = 0;
	else if (all->player == 'S')
		all->game->player_ang = 90;
	else if (all->player == 'E')
		all->game->player_ang = 180;
	load_textures(all);
}

void	load_textures(t_all *all)
{
	all->textures[0] = mlx_load_png(all->pics[0]);
	all->textures[1] = mlx_load_png(all->pics[1]);
	all->textures[2] = mlx_load_png(all->pics[2]);
	all->textures[3] = mlx_load_png(all->pics[3]);
}
