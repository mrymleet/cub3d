/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:53:40 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/21 18:43:18 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	store_map(t_all *all)
{
	int	i;
	int	j;
	int	len;

	i = identify_the_start(all);
	j = 0;
	len = 0;
	while (all->map[i])
	{
		i++;
		len++;
	}
	all->final = malloc(sizeof(char *) * (len + 1));
	if (!all->final)
	{
		free_map(all);
		free(all->line); // i should free pics here
		exit (1);
	}
	i = identify_the_start(all);
	while (all->map[i])
	{
		all->final[j] = ft_strdup(all->map[i]);
		i++;
		j++;
	}
	all->final[j] = NULL;
}
