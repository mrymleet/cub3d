/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:44:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/18 17:34:39 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


t_ray    ray_cast(t_all *data, float angle)
{
    t_ray	horz_ray;
	t_ray	vert_ray;

    vert_ray = get_inters_vertical(data, angle);
    horz_ray = get_inters_horizontals(data, angle);
    if (vert_ray.distance < horz_ray.distance)
        return(vert_ray);
    else
        return (horz_ray);
}

int count_rows(char **str)
{
    int     count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}

int count_cols(char *str)
{
    int     count;

    count = 0;
    while (str && str[count])
        count++;
    return (count);
}
// int	point_reach_wall(t_all *all, t_point p)
// {
// 	if (p.x > 0 && p.x < WIDTH && p.y < HEIGHT && p.y > 0)
//     {
//         if (all->map[(int) p.x / SQUARE_SIZE]
//         && all->map[(int) p.x / SQUARE_SIZE][(int) p.y / SQUARE_SIZE]
//         && all->map[(int) p.x / SQUARE_SIZE][(int) p.y / SQUARE_SIZE] == '1')
//             return (1);
//     }
//     return (0);
// }

void	draw_ray(t_all *data, t_point src, t_ray ray)
{
	float		step;
	int			i;
	t_point		d;

	d.x = ray.wall_hit_x - src.x;
	d.y = ray.wall_hit_y - src.y;
	step = fabs(d.y);
	if (fabs(d.x) > fabs(d.y))
		step = fabs(d.x);
	i = -1;
	while (++i < step)
	{
		if ((src.x / SCALE >= 0 && src.x / SCALE < data->game->img_2d->width)
			&& (src.y / SCALE >= 0 && src.y / SCALE < data->game->img_2d->height))
			{
				// if (data->map[(int)(src.y + 1) / SQUARE_SIZE][(int)(src.x) / SQUARE_SIZE] == '1'
				// || data->map[(int)src.y / SQUARE_SIZE][(int)(src.x + 1) / SQUARE_SIZE] == '1'
				// || data->map[(int)(src.y - 1) / SQUARE_SIZE][(int)(src.x) / SQUARE_SIZE] == '1'
				// || data->map[(int)src.y / SQUARE_SIZE][(int)(src.x - 1) / SQUARE_SIZE] == '1')
				// 	break;
				mlx_put_pixel(data->game->img_2d, src.x / SCALE,
					src.y / SCALE, 0xFF0000FF);
			}
		src.x += (d.x) / step;
		src.y += (d.y) / step;
	}
}