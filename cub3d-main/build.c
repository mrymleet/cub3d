/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:44:07 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/09 12:07:19 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_window_and_images(t_all *all)
{
	all->game = malloc(sizeof(t_game));
	all->game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3d", true);
	all->game->img_2d = mlx_new_image(all->game->mlx, WIDTH / 2, HEIGHT / 2);
	all->game->img_3d = mlx_new_image(all->game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(all->game->mlx, all->game->img_3d, 0, 0);
	mlx_image_to_window(all->game->mlx, all->game->img_2d, 0, 0);
}

void	build_window(t_all *all)
{
	int     index_x;
	int     index_y;
	uint32_t		i;
	double point[2];
	i = 0;
	index_y = 0;

	while (all->map[index_y])
	{
		index_x = 0;
		while (all->map[index_y][index_x] && all->map[index_y][index_x] !='\n')
		{
			if (all->map[index_y][index_x] == '0' || all->map[index_y][index_x] == '1'
			|| all->map[index_y][index_x] == ' ' )
			{
				point[0] = index_x * SQUARE_SIZE;
				point[1] = index_y * SQUARE_SIZE;
				draw_block(all->game->img_2d, point, specify_color(all->map[index_y][index_x]));		
			}
			else
			{
				if (all->game->position.y == -1 || all->game->position.x == -1)
				{
					point[0] = index_y * SQUARE_SIZE;
					point[1] = index_x * SQUARE_SIZE;
					all->game->position.x = index_x * SQUARE_SIZE;
					all->game->position.y = index_y * SQUARE_SIZE;
					all->map[index_y][index_x] = '0';
				
				}
				// draw_block(all->game->img_2d, point, specify_color(all->map[index_y][index_x]));		
			}
			index_x++;
		}
		index_y++;		
	}
	draw_rays(all);
	// draw_play(all, 0xFF0000FF);
}

