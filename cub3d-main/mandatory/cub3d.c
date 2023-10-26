/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:15:14 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/26 14:50:28 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
	{
		printf("Error\nTwo arguments is requirred\n");
		return (1);
	}
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
