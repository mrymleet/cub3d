/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:52:37 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/23 11:55:23 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_window(t_all *all)
{
	uint32_t		col;
	uint32_t		row;

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

int32_t	get_rgb_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear(t_all *all)
{
	int		y;
	int		x;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(all->game->img_3d, x, y,
					get_rgb_color(0, 255, 255, 255));
			else
				mlx_put_pixel(all->game->img_3d, x, y,
					get_rgb_color(192, 192, 192, 255));
		}
	}
}

void	close_window(void *param)
{
	t_all		*all;

	all = param;
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_ESCAPE))
	{
		printf("The window has been closed manually!\n");
		mlx_close_window(all->game->mlx);
	}
}
