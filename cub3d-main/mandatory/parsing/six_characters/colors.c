/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:32:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 18:12:37 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	store_colors_(t_all *all)
{
	char	*tmp;
	char	c;

	tmp = ft_strtrim(all->map[all->i], " \t");
	if (!tmp)
		return (1);
	if (!ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
	{
		c = tmp[0];
		if (count_virgules(tmp) != 2 \
		|| check_numbers(all, ft_strchr(tmp, c)))
		{
			free(tmp);
			tmp = NULL;
			return (1);
		}
	}
	free(tmp);
	tmp = NULL;
	all->count++;
	return (0);
}

int	colors(t_all *all)
{
	char	*tmp;

	all->i = 0;
	all->count = 0;
	tmp = NULL;
	while (all->map[all->i] && all->count < 6)
	{
		if (!string_empty(all->map[all->i]))
		{
			if (store_colors_(all))
				return (1);
		}
		all->i++;
	}
	return (0);
}

int	count_virgules(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	check_numbers(t_all *all, char *str)
{
	int	i;
	int	num;

	i = 0;
	all->tmp = ft_split(str, ',');
	if (!all->tmp)
		return (1);
	while (all->tmp[i])
	{
		if (only_num(all->tmp[i]) || check_num(all->tmp[i]))
			return (1);
		num = ft_atoi(all->tmp[i]);
		if (!(num >= 0 && num <= 255))
			return (1);
		i++;
	}
	if (i != 3)
		return (1);
	free_tmp(all);
	return (0);
}
