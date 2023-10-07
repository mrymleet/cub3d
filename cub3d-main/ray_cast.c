/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:44:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/07 10:14:00 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_ray    ray_cast(t_all *all, float angle)
{
    t_point     p_intercept_v;
    t_point     p_intercept_h;
    float       x_step;
    float       y_step;
    // float       next_h_x;
	// float       next_h_y;
    t_point     p_check;
    // int foundVertWallHit = 0;
    // int foundHorzWallHit = 0;
    t_point     h_hit_wall_point;
    t_point     v_hit_wall_point;
    t_ray ray;
    ray.wall_hit_x=0;
    ray.wall_hit_y=0;

    p_intercept_v.x = floor((double)all->game->position.x / SQUARE_SIZE) * SQUARE_SIZE;
    if (angle < 90 || angle > 270)
        p_intercept_v.x += SQUARE_SIZE;
    if (angle > 90 && angle < 270)
        p_intercept_v.x -= 0.001;
    p_intercept_v.y = all->game->position.y + ((p_intercept_v.x - all->game->position.x) * tan(angle * (M_PI / 180)));
    //**************************
    x_step = SQUARE_SIZE;
    if (angle < 270 && angle > 90)
        x_step *= -1;
    y_step = x_step * tan(angle * (M_PI / 180));

    while (p_intercept_v.x >= 0 && p_intercept_v.x < WIDTH
    && p_intercept_v.y >= 0 && p_intercept_v.y < HEIGHT)
    {
        // p_check.x = next_h_x;
        // if (angle < 0 || angle > 180)
        //     p_check.y = next_h_y - 1;    
        p_check.x = floor(p_intercept_v.x / SQUARE_SIZE);
        p_check.y = floor(p_intercept_v.y / SQUARE_SIZE);
        // printf("angle = %f | x = %f | y = %f  c = |%c|\n", angle, p_check.x, p_check.y, all->map[(int)p_check.x][(int)p_check.y]);
        if ((p_check.y >= count_rows(all->map)
        || p_check.x >= count_cols(all->map[(int)p_check.y]))
            || all->map[(int)p_check.y][(int)p_check.x] == '1')
        {
            // h_hit_wall_point.x = p_intercept_v.x;
            // h_hit_wall_point.y = p_intercept_v.y;
            // foundHorzWallHit = 1;
            break;
        }
        else
        {
            p_intercept_v.x += x_step;
            p_intercept_v.y += y_step;
        }
    }
    v_hit_wall_point.x = p_intercept_v.x;
    v_hit_wall_point.y = p_intercept_v.y;
    //     // draw_ray(all, all->game->position, h_hit_wall_point);
    
    // ############
    p_intercept_h.y = floor(all->game->position.y / SQUARE_SIZE) * SQUARE_SIZE;
    if (angle > 0 && angle < 180)
	    p_intercept_h.y += SQUARE_SIZE;
    if (angle < 0 || angle > 180)
         p_intercept_h.y -= 0.001;
    p_intercept_h.x = all->game->position.x + (p_intercept_h.y - all->game->position.y) / tan(angle * (M_PI / 180));
    y_step = SQUARE_SIZE;
    if (angle < 0 || angle > 180)
        y_step *= -1;
    x_step = y_step / tan(angle * (M_PI / 180));
    while (p_intercept_h.x >= 0 && p_intercept_h.x < WIDTH && p_intercept_h.y >= 0 && p_intercept_h.y < HEIGHT)
    {
        p_check.x = floor(p_intercept_h.x / SQUARE_SIZE);
        p_check.y = floor(p_intercept_h.y / SQUARE_SIZE);
        if ((p_check.y >= count_rows(all->map)
        || p_check.x >= count_cols(all->map[(int)p_check.y]))
        || all->map[(int) p_check.y][(int) p_check.x] == '1')
        {
            // v_hit_wall_point.x = next_v_x;
            // v_hit_wall_point.y = next_v_y;
            // foundVertWallHit = 1;
            // printf("angle = %f | x = %f | y = %f\n", angle, v_hit_wall_point.x, v_hit_wall_point.y);
            break;
        }
        else
        {
            p_intercept_h.x += x_step;
            p_intercept_h.y += y_step;
        }
    }
    h_hit_wall_point.x = p_intercept_h.x;
    h_hit_wall_point.y = p_intercept_h.y;
    float distance;
    distance = distace_two_points(all->game->position, p_intercept_h) ;
    if (distance > distace_two_points(all->game->position, p_intercept_v))
    {
        distance = distace_two_points(all->game->position, p_intercept_v);
        if (p_intercept_v.y >= 0 && p_intercept_v.x < WIDTH
        && p_intercept_v.x >= 0 && p_intercept_v.y < HEIGHT)
        {
                // draw_ray(all, all->game->position, v_hit_wall_point);
            ray.wall_hit_x = p_intercept_v.x;
            ray.wall_hit_y = p_intercept_v.y;
            ray.distance = distance;
            
        }
    }
    else
    {
        if (p_intercept_h.y >= 0 && p_intercept_h.y < HEIGHT
        && p_intercept_h.x >= 0 && p_intercept_h.x < WIDTH)
        {
            ray.wall_hit_x = p_intercept_h.x;
            ray.wall_hit_y = p_intercept_h.y;
            ray.distance = distance;
        }
        // ray.wall_hit_x = p_intercept_h.x;
        // ray.wall_hit_y = p_intercept_h.y;
        // ray.distance = 10;
    }
    return (ray);
    // printf("==>x= %f|y= %f\n",  h_hit_wall_point.x, h_hit_wall_point.y);
    // printf("==>%f\n", distance);
    //   ########
}

int	point_reach_wall(t_all *all, t_point p)
{
    // printf("      --> x = %f y= %f \n", p.x, p.y);
	if (p.x > 0 && p.x < WIDTH && p.y < HEIGHT && p.y > 0)
    {
        if (all->map[(int) p.x / SQUARE_SIZE]
        && all->map[(int) p.x / SQUARE_SIZE][(int) p.y / SQUARE_SIZE]
        && all->map[(int) p.x / SQUARE_SIZE][(int) p.y / SQUARE_SIZE] == '1')
            return (1);
    }
    return (0);
}

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
		if ((src.x / SCALE >= 0 && src.x / SCALE < WIDTH)
			&& (src.y / SCALE >= 0 && src.y / SCALE < HEIGHT))
			{
				// if (data->map[(int)(src.y + 1) / SQUARE_SIZE][(int)(src.x) / SQUARE_SIZE] == '1'
				// || data->map[(int)src.y / SQUARE_SIZE][(int)(src.x + 1) / SQUARE_SIZE] == '1'
				// || data->map[(int)(src.y - 1) / SQUARE_SIZE][(int)(src.x) / SQUARE_SIZE] == '1'
				// || data->map[(int)src.y / SQUARE_SIZE][(int)(src.x - 1) / SQUARE_SIZE] == '1')
					// break;
				mlx_put_pixel(data->game->img_2d, src.x / SCALE,
					src.y / SCALE, 0xFF0000FF);
			}
		src.x += (d.x) / step;
		src.y += (d.y) / step;
	}
}