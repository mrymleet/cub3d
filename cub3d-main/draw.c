#include "cub3d.h"

void    draw_block(mlx_image_t *canvas, double point[2], long color)
{
	int            col;
	int            row;
	t_point    location;

	location.x = point[0];
	location.y = point[1];
	row = -1;
	while (++row < SQUARE_SIZE)
	{
		col = -1;
		while (++col < SQUARE_SIZE)
		{
			if (!col || !row)
			{
				if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
					&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
					mlx_put_pixel(canvas, (location.x + col) / SCALE, (location.y + row) / SCALE, 841372671);
			}
			else
			{
				if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
					&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
					mlx_put_pixel(canvas, (location.x + col) / SCALE, (location.y + row) / SCALE, color);
			}
		}
	}
}

void    draw_play(mlx_image_t *canva, t_point position, long color)
{
	int            col;
	int            row;
	t_point    location;
printf("-->%f | %f\n", position.x, position.y);
	location.x = position.x;
	location.y = position.y;
	row = -1;
	while (++row < PLAYER_SIZE)
	{
		col = -1;
		while (++col < PLAYER_SIZE)
		{
			if ((location.x + col) / SCALE > 0 && (location.x + col) / SCALE < WIDTH
					&& (location.y + row) / SCALE > 0 && (location.y + row) / SCALE < HEIGHT)
					mlx_put_pixel(canva, (location.x + col) / SCALE, (location.y + row) / SCALE, color);
		}
	}
}

void    draw_line(t_all *data)
{
    float        step;
    int            i;
    t_point    p1;
    t_point    p2;
    t_point    d;
printf("-->%f\n", data->game->player_ang);
    p1.x = (data->game->position.y + 5);
    p1.y = (data->game->position.x + 5);
    p2.x = p1.x + sin(data->game->player_ang * (M_PI / 180)) * SQUARE_SIZE;
    p2.y = p1.y + cos(data->game->player_ang * (M_PI / 180)) * SQUARE_SIZE;
    d.x = p2.x - p1.x;
    d.y = p2.y - p1.y;
    step = fabs(d.y);
    if (fabs(d.x) > fabs(d.y))
        step = fabs(d.x);
    i = -1;
    while (++i < step && step < INT_MAX)
    {
        if ((p1.x / SCALE >= 0 && p1.x / SCALE < WIDTH)
            && (p1.y / SCALE >= 0 && p1.y / SCALE < HEIGHT))
            mlx_put_pixel(data->game->img_2d, p1.y / SCALE,
                p1.x / SCALE, 0xFF0000FF);
        p1.x += (d.x) / step;
        p1.y += (d.y) / step;
    }
}

void	draw_direction(t_all *all, float x0, float y0, float x1, float y1)
{
	float		dx;
	float		dy;
	int 		steps;
	float		varX;
	float		varY;
	float x,y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	varX = dx / (float)steps;
	varY = dy / (float)steps;
	i	= 0;
	x = x0;
	y = y0;
	while (i <= steps)
	{
		mlx_put_pixel(all->game->img_2d, y, x, 0xFF0000FF);
		x += varX;
		y += varY;
		i++;
	}
}

long    specify_color(char c)
{
	if (c == '0' || c == 'N')
		return (0xFFFFFF);
	else if(c == '1')
		return (0x0000FF);
	else if (c == ' ')
		return (0x000000);
	return (-1);
}


int ft_abs(float n)
{
	if (n > 0)
		return (n);
	else
		return (n * (-1));
}