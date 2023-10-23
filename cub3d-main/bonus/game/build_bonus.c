/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:44:07 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/23 15:41:12 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	create_window_and_images(t_all *all)
{
	all->game = malloc(sizeof(t_game));
	all->game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3d", true);
	all->game->img_2d = mlx_new_image(all->game->mlx, WIDTH, HEIGHT);
	all->game->img_3d = mlx_new_image(all->game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(all->game->mlx, all->game->img_3d, 0, 0);
	mlx_image_to_window(all->game->mlx, all->game->img_2d, 0, 0);
}

void	build_window(t_all *all)
{
	int			x;
	int			y;

	y = -1;
	while (all->map[++y])
	{
		x = 0;
		while (all->map[y][x] && all->map[y][x] != '\n')
		{
			if (all->map[y][x] == '0' || all->map[y][x] == '1'
			|| all->map[y][x] == ' ' )
				draw_square(all, x, y);
			else
			{
				if (all->game->position.y == -1 || all->game->position.x == -1)
				{
					all->game->position.x = x * SQUARE_SIZE;
					all->game->position.y = y * SQUARE_SIZE;
					all->map[y][x] = '0';
				}
			}
			x++;
		}
	}
	draw_rays(all);
}

void	draw_square(t_all *all, int x, int y)
{
	double		point[2];

	point[0] = x * SQUARE_SIZE;
	point[1] = y * SQUARE_SIZE;
	draw_block(all->game->img_2d, point,
		specify_color(all->map[y][x]));
}
