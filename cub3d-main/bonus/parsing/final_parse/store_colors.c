/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:44:02 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/26 14:52:43 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	store_colors(t_all *all)
{
	char	*tmp;

	all->i = 0;
	all->count = 0;
	tmp = NULL;
	while (all->map[all->i] && all->count < 2)
	{
		tmp = ft_strtrim(all->map[all->i], " \t");
		if (!ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
		{
			exact_color(all, tmp);
			all->count++;
		}
		free(tmp);
		tmp = NULL;
		all->i++;
	}
}

void	exact_color(t_all *all, char *tmp)
{
	all->cc = NULL;
	all->cc1 = NULL;
	all->cc = ft_split(&tmp[1], ',');
	if (!all->cc)
	{
		free(all->line);
		free_map(all);
		exit(1);
	}
	all->cc1 = malloc(sizeof(char *) * 4);
	if (!all->cc1)
	{
		free_map(all);
		free(all->line);
		free_all_ccs(all);
		exit (1);
	}
	store_colors_again(0, tmp, all);
}

void	store_colors_again(int i, char *tmp, t_all *all)
{
	while (i < 3)
	{
		all->cc1[i] = ft_strtrim(all->cc[i], " \t");
		i++;
	}
	all->cc1[i] = NULL;
	i = 0;
	if (tmp[0] == 'F')
	{
		while (i < 3)
		{
			all->floor[i] = ft_atoi(all->cc1[i]);
			i++;
		}
	}
	else
	{
		while (i < 3)
		{
			all->ciel[i] = ft_atoi(all->cc1[i]);
			i++;
		}
	}
	free_all_ccs(all);
}
