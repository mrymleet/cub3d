/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:36:49 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/26 18:32:32 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	check_newlines(t_all *all)
{
	int	k;

	all->i = identify_the_start(all);
	all->str = ft_strnstr(all->line, all->map[all->i], ft_strlen(all->line));
	if (!all->str)
		return (1);
	k = 0;
	while (all->str[k])
	{
		if (all->str[k] == '\n' && all->str[k + 1] == '\n')
			return (1);
		k++;
	}
	return (0);
}
