/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:38:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/19 10:16:36 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_wall(t_all *data, t_ray ray, int i)
{
	t_point		p;

	p.x = i;
	p.y = ((HEIGHT / 2) - (((HEIGHT / 2) * SQUARE_SIZE) / ray.distance));
	draw_columns(data, p, HEIGHT - (p.y * 2), ray);
}

void	draw_columns(t_all *data, t_point p, float height, t_ray ray)
{
	t_d_point		d_point;
	mlx_texture_t	*texture;
	float			width_ratio;

	d_point.my_image.x = p.x;
	d_point.my_image.y = p.y;
	if (ray.is_horz)
	{
		texture = data->textures[0];
		if (ray.angle < 0 || ray.angle > 180)
			texture = data->textures[1];
		width_ratio = (float)(texture->width / SQUARE_SIZE);
		d_point.texture.x = fmod(ray.wall_hit_x, SQUARE_SIZE) * (width_ratio);
	}
	else
	{
		texture = data->textures[2];
		if (ray.angle < 270 && ray.angle > 90)
			texture = data->textures[3];
		width_ratio = (float)(texture->width / SQUARE_SIZE);
		d_point.texture.x = fmod(ray.wall_hit_y, SQUARE_SIZE) * (width_ratio);
	}
	draw_text(data, d_point, height, texture);
}

void	draw_text(t_all *data, t_d_point d_point, float h, mlx_texture_t *tex)
{
	t_int_point		p1;
	t_int_point		p2;
	uint8_t			*px;
	uint8_t			*pi;

	p1.x = d_point.texture.x;
	p1.y = -1;
	p2.x = d_point.my_image.x;
	p2.y = d_point.my_image.y - 1;
	if (h > data->game->img_3d->height)
		p1.y = (h - data->game->img_3d->height) / 2;
	if (p2.y < 0)
		p2.y = 0;
	while (++p2.y < (int)data->game->img_3d->height - 1 && ++p1.y < h - 1)
	{
		d_point.texture.y = p1.y * (float) tex->height / h;
		if (d_point.texture.y < tex->height
			&& (d_point.texture.y * tex->width + p1.x)
			< tex->width * tex->height)
		{
			px = get_px_index(tex, d_point, p1);
			pi = get_pi_index(data, tex, p2);
			ft_memmove(pi, px, tex->bytes_per_pixel);
		}
	}
}

uint8_t	*get_px_index(mlx_texture_t *tex, t_d_point d_point, t_int_point p1)
{
	return (&tex->pixels[((int)d_point.texture.y * tex->width + p1.x)
			* tex->bytes_per_pixel]);
}

uint8_t	*get_pi_index(t_all *data, mlx_texture_t *tex, t_int_point p2)
{
	return (&data->game->img_3d->pixels[(p2.y
				* (data->game->img_3d->width) + p2.x)
			* tex->bytes_per_pixel]);
}
