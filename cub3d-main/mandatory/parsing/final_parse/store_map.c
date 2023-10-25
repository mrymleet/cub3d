/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:53:40 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:54:58 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	store_map(t_all *all)
{
	int	i;
	int	j;
	int	len;

	i = identify_the_start(all) - 1;
	j = 0;
	len = 0;
	while (all->map[++i])
		len++;
	all->final = malloc(sizeof(char *) * (len + 1));
	if (!all->final)
	{
		free_map(all);
		free(all->line);
		exit (1);
	}
	i = identify_the_start(all);
	while (all->map[i++])
		all->final[j++] = ft_strdup(all->map[i - 1]);
	all->final[j] = NULL;
}
