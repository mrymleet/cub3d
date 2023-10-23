/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:15:14 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/23 12:59:47 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
		return (1);
	read_map(av[1], &all);
	if (is_map_valid(&all))
	{
		printf("Error\n");
		return (1);
	}
	parsing(&all);
	all.map = all.final;
	create_window_and_images(&all);
	init_data(&all);
	mlx_loop_hook(all.game->mlx, close_window, &all);
	mlx_loop_hook(all.game->mlx, moving_hook, &all);
	mlx_loop(all.game->mlx);
	mlx_terminate(all.game->mlx);
	return (EXIT_SUCCESS);
}
