/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:53:31 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/23 12:42:41 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	bound_angle(float angle)
{
	if (angle < 0)
	{
		angle += 360;
	}
	if (angle > 360)
	{
		angle = fmod(angle, 360);
	}
	return (angle);
}

float	distace_two_points(t_point src, t_point dst)
{
	return (sqrt(pow((dst.x - src.x), 2) + pow((dst.y - src.y), 2)));
}

long	specify_color(char c)
{
	if (c == '0')
		return (0xFFFFFF);
	else if (c == '1')
		return (0x0000FF);
	else
		return (0x000000);
}

int	count_rows(char **str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	count_cols(char *str)
{
	int		count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}
