#include "cub3d.h"

int is_map_valid(t_all *all)
{
	all->map = ft_split(all->line, '\n');
	if (!all->map)
		exit (1);
	if (all_characters_exits(all) || names_correct(all)\
	|| check_path(all) || colors(all))
		return (1);
	if (check_map_characters(all) || check_newlines(all)
	|| surronded(all) || check_empty(all))
		return (1);
	
	return (0);
}

// void	build_window(t_all all)
// {
// 	int		i;

// 	i = 0;
// 	mlx_clear_window(all.mlx, all.win);
// 	while (all.map[i])
// 	{
// 		loop_ligne(all, i);
// 		i++;
// 	}
// }

// void	loop_ligne(t_all all, int i)
// {
// 	int		j;

// 	j = 0;
// 	while (all.map[i][j])
// 	{
// 		if (all.map[i][j] == '1')
// 			mlx_put_image_to_window
// 			(all.mlx, all.win, all.img.w, j * 50, i * 50);
// 		else if (all.map[i][j] == 'P')
// 			mlx_put_image_to_window
// 			(all.mlx, all.win, map.img.p, j * 50, i * 50);
// 		else if (all.map[i][j] == 'E')
// 			mlx_put_image_to_window
// 			(all.mlx, all.win, all.img.e, j * 50, i * 50);
// 		else if (all.map[i][j] == 'C')
// 			mlx_put_image_to_window
// 			(all.mlx, all.win, all.img.c, j * 50, i * 50);
// 		else if (all.map[i][j] == '0')
// 			mlx_put_image_to_window
// 			(all.mlx, all.win, all.img.em, j * 50, i * 50);
// 		j++;
// 	}
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

void	free_2_dimensions(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int main(int ac, char **av)
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
	// all.height = ft_get_height(all.map);
	// all.width = ft_get_width(all.map) - 1;
	// all.mlx = mlx_init();
	// all.win = mlx_new_window(all.mlx, all.width * 50, all.height * 50, "cub3D");
	// all.map = read_map_1(all, av[1]);
	// free_2_dimensions(all.map);
	all.map = read_map_1(all, av[1]);
	int		i = 0;
	while (all.map[i])
	{
		printf("%s", all.map[i]);
		i++;
	}
}
