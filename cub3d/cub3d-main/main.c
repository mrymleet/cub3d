/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:16:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/07 19:16:46 by mel-moun         ###   ########.fr       */
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




// int	ft_get_height(char **s)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_get_width(char **s)
// {
// 	int		i;

// 	i = 0;
// 	while (s[0][i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void	free_2_dimensions(char **str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

// int close_window(void *param) {
// 	(void)param;
//     exit(0);
//     return 0;
// }

void	close_window(void* param)
{
	t_all *all;
	
	all = param;
	if (mlx_is_key_down(all->game->mlx, MLX_KEY_ESCAPE))
	{
		printf("The window has been closed manually!\n");
		mlx_close_window(all->game->mlx);
	}
}



int main(int ac, char **av)
{
	t_all all;

	if (ac != 2)
		return (1);
	
	// read_map(av[1], &all);
	// if (is_map_valid(&all))
	// {
	// 	printf("Error\n");
	// 	return (1);
	// }
	// free_2_dimensions(all.map);
	all.i = 1;
	all.map = read_map_1(&all, av[1]);
	
	create_window_and_images(&all);
	all.game->position.x = -1;
	all.game->position.y = -1;
	all.game->player_ang = 90;
	// build_window(&all);
	mlx_loop_hook(all.game->mlx, close_window, &all);
	mlx_loop_hook(all.game->mlx, moving_hook, &all);
	mlx_loop(all.game->mlx);
	mlx_terminate(all.game->mlx);
	return (EXIT_SUCCESS);
}
