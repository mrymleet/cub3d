/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:14:33 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/07 19:14:34 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	numwords(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == 32 || s[i] == '\t') && s[i] != '\0')
			i++;
		if (s[i] != 32 && s[i] != '\t' && s[i] != '\0')
			count++;
		while (s[i] != 32 && s[i] != '\t' && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**splitpath(char *s, char **p,  int i)
{
	int		j;
	int		k;
	int		len;

	j = 0;
	k = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == '\t' || s[i] == 32)
			i++;
		j = i - 1;
		while (s[++j] != '\t' && s[j] != 32 && s[j] != '\0')
			len++;
		if (s[i] == '\0')
		{
			p[k] = 0;
			break ;
		}
		p[k++] = ft_substr(s, i, len);
		len = 0;
		i = j;
	}
	return (p);
}

char	**split_two(char *s)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	p = (char **) ft_calloc ((numwords(s) + 1), sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (splitpath(s, p, i));
}

int string_empty(char *str)
{
	int i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i])
		return (0);
	return (1);
}

int string_empty_one(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i])
		return (0);
	return (1);
}