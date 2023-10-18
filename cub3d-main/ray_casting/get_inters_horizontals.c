/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inters_horizontals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:41:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/18 16:19:39 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray   get_inters_horizontals(t_all *data, float angle)
{
    t_ray       ray;
    t_point     p_intercept_h;
    float       x_step;
    float       y_step;
    t_point     p_check;

    // ray.is_facing_down = (angle > 0 && angle < 180);
	// ray.is_facing_up = !ray.is_facing_down;
	// ray.is_facing_right = (angle < 90 || angle > 270);
	// ray.is_facing_left = !ray.is_facing_right;

    
    p_intercept_h.y = floor(data->game->position.y / SQUARE_SIZE) * SQUARE_SIZE;
    if (angle > 0 && angle < 180)
	    p_intercept_h.y += SQUARE_SIZE;
    if (angle < 0 || angle > 180)
         p_intercept_h.y -= 0.001;
    p_intercept_h.x = data->game->position.x + (p_intercept_h.y - data->game->position.y) / tan(angle * (M_PI / 180));
    y_step = SQUARE_SIZE;
    if (angle < 0 || angle > 180)
        y_step *= -1;
    x_step = y_step / tan(angle * (M_PI / 180));
    while (p_intercept_h.x >= 0 && p_intercept_h.x < WIDTH && p_intercept_h.y >= 0 && p_intercept_h.y < HEIGHT)
    {
        p_check.x = floor(p_intercept_h.x / SQUARE_SIZE);
        p_check.y = floor(p_intercept_h.y / SQUARE_SIZE);
        if ((p_check.y >= count_rows(data->map)
        || p_check.x >= count_cols(data->map[(int)p_check.y]))
        || data->map[(int) p_check.y][(int) p_check.x] == '1')
            break;
        else
        {
            p_intercept_h.x += x_step;
            p_intercept_h.y += y_step;
        }
    }
    // if (p_intercept_h.y >= 0 && p_intercept_h.y < HEIGHT
    //     && p_intercept_h.x >= 0 && p_intercept_h.x < WIDTH)
    // {
        ray.wall_hit_x = p_intercept_h.x;
        ray.wall_hit_y = p_intercept_h.y;
        ray.angle = angle;
        ray.distance = distace_two_points(data->game->position, p_intercept_h);
        ray.is_horz = 1;
    // }
    return (ray);
}