/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:38:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/18 17:29:23 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    build_wall(t_all *data, t_ray ray, int i)
{
    t_point  p;

    p.x = i;
    p.y = ((HEIGHT / 2) - (((HEIGHT / 2) * SQUARE_SIZE) / ray.distance));
    draw_columns(data, p, HEIGHT - (p.y * 2), ray);
}

void	draw_columns(t_all *data, t_point p, float height, t_ray ray)
{
    t_point         img;
    t_point         tex;
    mlx_texture_t	*texture;
	float			width_ratio;

    img.x = p.x;
	img.y = p.y;
	if (ray.is_horz)
	{
		texture = data->textures[0];
		if (ray.angle < 0 || ray.angle > 180)
			texture = data->textures[1];
		width_ratio = (float)(texture->width / SQUARE_SIZE);
		tex.x = fmod(ray.wall_hit_x, SQUARE_SIZE) * (width_ratio);
	}
	else
	{
		texture = data->textures[2];
		if (ray.angle < 270 && ray.angle > 90)
			texture = data->textures[3];
		width_ratio = (float)(texture->width / SQUARE_SIZE);
		tex.x = fmod(ray.wall_hit_y, SQUARE_SIZE) * (width_ratio);
	}
    draw_text(data, img, tex, height, texture);
}

void	draw_text(t_all *data, t_point img, t_point ttex, float h, mlx_texture_t *tex)
{
    t_int_point	    p1;
	t_int_point	    p2;
	uint8_t			*px;
	uint8_t			*pi;

	p1.x = ttex.x;
	p1.y = -1;
	p2.x = img.x;
	p2.y = img.y - 1;
    
	if (h > data->game->img_3d->height)
		p1.y = (h - data->game->img_3d->height) / 2;
	if (p2.y < 0)
		p2.y = 0;
	while (++p2.y < (int)data->game->img_3d->height - 1 && ++p1.y < h - 1)
	{
		ttex.y = p1.y * (float) tex->height / h;
		if (ttex.y < tex->height
			&& (ttex.y * tex->width + p1.x) < tex->width * tex->height)
		{
			px = &tex->pixels[((int)ttex.y * tex->width + p1.x) * tex->bytes_per_pixel];
			pi = &data->game->img_3d->pixels[(p2.y * (data->game->img_3d->width) + p2.x) * tex->bytes_per_pixel];
			
			ft_memmove(pi, px, tex->bytes_per_pixel);
		}
	}
}
