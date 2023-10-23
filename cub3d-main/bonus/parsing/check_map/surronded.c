/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surronded.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:37:33 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 12:42:58 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	surronded(t_all *all)
{
	initialize_vars(all);
	all->i = identify_the_start(all);
	all->count = identify_the_start(all);
	while (all->map[all->i++])
		all->wid++;
	all->i = identify_the_start(all);
	while (all->map[all->i])
	{
		if (all->i == all->count \
		|| all->i == (all->wid + all->count - 1))
		{
			if (up_down(all, all->i))
				return (1);
		}
		else
		{
			if (right_left(all, all->i))
				return (1);
		}
		all->i++;
	}
	return (0);
}

//check tab, better \t to be with all vs config
int	up_down(t_all *all, int i)
{
	int		j;
	char	*str;

	j = 0;
	str = ft_strtrim(all->map[i], " \t");
	if (!str)
		return (1);
	while (str[j])
	{
		if (str[j] != 32 && str[j] != '\t'\
		&& str[j] != '1')
		{
			free(str);
			return (1);
		}
		j++;
	}
	free(str);
	return (0);
}

int	right_left(t_all *all, int i)
{
	char	*str;

	str = ft_strtrim(all->map[i], " \t");
	if (!str)
		return (1);
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
