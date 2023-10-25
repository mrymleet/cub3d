/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:42:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 17:38:13 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	parsing(t_all *all)
{
	store_player(all);
	store_colors(all);
	store_pictures(all);
	store_map(all);
	free(all->line);
	all->line = NULL;
	free_map(all);
}
