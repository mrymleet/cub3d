/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:38:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/09 12:17:13 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    build_wall(t_all *data, t_ray ray, int i, float ang)
{
    float       height;
    float       y_init;
    float       y_dst;

    height = 50000 / (ray.distance  * cos((data->game->player_ang - ang) * M_PI / 180));
    y_init = HEIGHT / 2 - height / 2;
    y_dst = y_init + height ;
    while (y_init <= y_dst)
    {
        if (i >= 0 && i < WIDTH && y_init >= 0 && y_init < HEIGHT)
            mlx_put_pixel(data->game->img_3d, i, y_init, 0x037ffc);
        y_init++;
    }
}