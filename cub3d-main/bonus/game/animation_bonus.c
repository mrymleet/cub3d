/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:20:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 10:38:04 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	load_animation(t_all *all)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 10)
	{
		path = ft_strjoin2("./textures/", ft_itoa(i));
		all->anim[i] = mlx_load_png(path);
		free(path);
		path = NULL;
		i++;
	}
}

void	animation(void *p)
{
	t_all				*all;
	static mlx_image_t	*im;
	static int			i;
	static int			s;

	all = p;
	mlx_delete_image(all->game->mlx, im);
	if (s % ANI_SPEED == 0)
		i++;
	if (i == ANI_NUM)
		i = 0;
	im = mlx_texture_to_image(all->game->mlx, all->anim[i]);
	mlx_image_to_window(all->game->mlx, im, 1100, 50);
	s++;
	if (s == ANI_SPEED * ANI_NUM)
		s = 0;
}
