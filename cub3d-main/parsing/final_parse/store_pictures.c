/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pictures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:45:33 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/21 18:43:21 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	store_pictures(t_all *all)
{
	char	*tmp;

	all->pics = malloc(sizeof(char *) * 5);
	if (!all->pics)
	{
		free(all->line);
		free_map(all);
		exit (1);
	}
	all->i = 0;
	all->count = 0;
	while (all->map[all->i] && all->count < 6)
	{
		if (!string_empty(all->map[all->i]))
		{
			tmp = ft_strtrim(all->map[all->i], " \t");
			if (!ft_strncmp(tmp, "NO", 2))
				all->pics[0] = tmp + 2;
			else if (!ft_strncmp(tmp, "EA", 2))
				all->pics[1] = tmp + 2;
			else if (!ft_strncmp(tmp, "SO", 2))
				all->pics[2] = tmp + 2;
			else if (!ft_strncmp(tmp, "WE", 2))
				all->pics[3] = tmp + 2;
			all->count++;
			free(tmp);
			tmp = NULL;
		}
		all->i++;
	}
	all->pics[4] = NULL;
}
