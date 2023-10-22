/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:15:14 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/22 10:19:56 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int is_map_valid(t_all *all)
// {
// 	all->map = ft_split(all->line, '\n');
// 	if (!all->map)
// 		exit (1);
// 	if (all_characters_exits(all) || names_correct(all)\
// 	|| check_path(all) || colors(all))
// 		return (1);
// 	if (check_map_characters(all) || check_newlines(all)
// 	|| surronded(all) || check_empty(all))
// 		return (1);
	
// 	return (0);
// }



// void	mouse_hook(void* param)
// {
// 	t_all *all;
	
// 	all = param;
// 	if (mlx_is_mouse_down(all->game->mlx, MLe)
// }

int main(int ac, __unused char **av)
{
	t_all all;

	if (ac != 2)
		return (1);
	
	read_map(av[1], &all);
	if (is_map_valid(&all))
	{
		printf("Error\n");
		return (1);
	}
	// free_2_dimensions(all.map);
	// all.i = 1;
	all.map = read_map_1(&all, av[1]);

	// // }
	
	create_window_and_images(&all);
	// if (access("./textures/norh.png", F_OK))
	// 	printf("picture doesnt exist\n");
	// 	exit(0);

    all.textures[0] = mlx_load_png("./textures/north.png");
	// if (all.textures[0] == NULL)
	all.textures[1] = mlx_load_png("./textures/south.png");
	all.textures[2] = mlx_load_png("./textures/est.png");
	all.textures[3] = mlx_load_png("./textures/west.png");
	all.game->position.x = -1;
	all.game->position.y = -1;
	all.game->player_ang = 90;
	all.game->mouse_x = 0;
	all.game->mouse_y = 0;

	mlx_loop_hook(all.game->mlx, close_window, &all);
	mlx_loop_hook(all.game->mlx, moving_hook, &all);
	mlx_loop(all.game->mlx);
	mlx_terminate(all.game->mlx);
	return (EXIT_SUCCESS);
}
