/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:04:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/28 12:53:52 by mel-moun         ###   ########.fr       */
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
	int		i;

	i = -1;
	while (++i < 4)
		all->textures[i] = mlx_load_png(all->pics[i]);
	if (!all->textures[0] || !all->textures[1] \
	|| !all->textures[2] || !all->textures[3])
	{
		free_map(all);
		free_pics(all);
		exit(1);
	}
	i = -1;
	while (++i < 4)
	{
		if (all->textures[i]->width != 512 \
		|| all->textures[i]->height != 512)
		{
			printf("Error\n");
			exit (1);
		}
	}
}
