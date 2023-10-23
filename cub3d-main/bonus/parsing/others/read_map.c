/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:23:42 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 12:43:21 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	read_map(char *str, t_all *all)
{
	int		fd;
	char	*tmp;

	all->line = NULL;
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4) != 0)
		map_error(1, all);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		map_error(2, all);
	tmp = get_next_line(fd);
	if (!tmp)
		map_error(3, all);
	while (tmp)
	{
		all->line = ft_strjoin(all->line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
}

void	map_error(int err, t_all *all)
{
	if (err == 1)
		printf("Error\nFile's map must be .cub\n");
	else if (err == 2)
		printf("Error\nPlease check the permission && existance\n");
	else
		printf("Error\nNo map is found\n");
	free(all->line);
	exit (1);
}

int	is_map_valid(t_all *all)
{
	all->map = ft_split(all->line, '\n');
	if (!all->map)
	{
		free(all->line);
		exit (1);
	}
	if (all_characters_exits(all) || names_correct(all) \
	|| check_path(all) || colors(all))
	{
		free_map(all);
		free(all->line);
		return (1);
	}
	if (check_map_characters(all) || check_newlines(all) \
	|| surronded(all) || check_empty(all) || last_line(all))
	{
		free_map(all);
		free(all->line);
		return (1);
	}
	return (0);
}
