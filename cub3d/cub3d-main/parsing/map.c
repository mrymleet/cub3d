/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:14:05 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/07 19:14:06 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int identify_the_start(t_all *all)
{
    int i;

    i = 0;
    while (all->map[i] && (string_empty(all->map[i]) 
    || (ft_strnstr(all->map[i], "NO", ft_strlen(all->map[i]))
    || ft_strnstr(all->map[i], "SO", ft_strlen(all->map[i]))
    || ft_strnstr(all->map[i], "WE", ft_strlen(all->map[i]))
    || ft_strnstr(all->map[i], "EA", ft_strlen(all->map[i]))
    || ft_strnstr(all->map[i], "F", ft_strlen(all->map[i]))
    || ft_strnstr(all->map[i], "C", ft_strlen(all->map[i])))))
    {
        i++;
    }
    return (i);
}

int identify_the_end(t_all *all)
{
    int i;

    i = 0;
    while (all->str[i])
        i++;
    i--;
    while (all->str[i] == '\n' || all->str[i] == '\t'\
    || all->str[i] == 32)
        i--;
    return (i);
}
int count_chars(t_all *all)
{
    while (all->str[all->i])
    {
        if (all->str[all->i] == 'N')
            all->NO++;
        else if (all->str[all->i] == 'S')
            all->SO++;
        else if (all->str[all->i] == 'E')
            all->EA++;
        else if (all->str[all->i] == 'W')
            all->WE++;
        else if (all->str[all->i] != 'W' && all->str[all->i] != 'E'\
        && all->str[all->i] != 'S' && all->str[all->i] != 'N'\
        && all->str[all->i] != '\n' && all->str[all->i] != '1'\
        && all->str[all->i] != '0' && all->str[all->i] != '\t' \
        && all->str[all->i] != 32)
            return (1);
        all->i++;
    }
    return (0);
}
int check_map_characters(t_all *all)
{
    initialize_vars(all);
    all->i = identify_the_start(all);
    if (!all->map[all->i])
        return (1);
    all->str = ft_strnstr(all->line, all->map[all->i], ft_strlen(all->line));
    all->i = 0;
    while (all->str[all->i])
    {
        if (all->str[all->i] == 'N')
            all->NO++;
        else if (all->str[all->i] == 'S')
            all->SO++;
        else if (all->str[all->i] == 'E')
            all->EA++;
        else if (all->str[all->i] == 'W')
            all->WE++;
        else if (count_chars(all))
            return (1);
        all->i++;
    }
    if ((all->NO == 1 || all->SO == 1 || all->EA == 1 || all->WE == 1)
    && (all->NO + all->SO + all->EA + all->WE == 1))
        return (0);
    return (1);
}

int check_newlines(t_all *all)
{
    int j;
    int k;

    all->i = identify_the_start(all);
    all->str = ft_strnstr(all->line, all->map[all->i], ft_strlen(all->line));
    j = identify_the_end(all);
    k = 0;
    while (k < j)
    {
        if (all->str[k] == '\n' && all->str[k + 1] == '\n')
            return (1);
        k++;
    }
    return (0);
}
int empty(t_all *all, char c)
{
    if (all->map[all->i][all->j + 1] == c\
    || all->map[all->i][all->j - 1] == c\
    || all->map[all->i - 1][all->j] == c\
    || all->map[all->i + 1][all->j] == c)
        return (1);
    return (0);
}
int check_empty(t_all *all)
{
    all->i = identify_the_start(all);
    all->j = 0;
    while (all->map[all->i])
    {
        while (all->map[all->i][all->j])
        {
            if (all->map[all->i][all->j] == '0'\
            || all->map[all->i][all->j] == 'N'\
            || all->map[all->i][all->j] == 'W'\
            || all->map[all->i][all->j] == 'E'\
            || all->map[all->i][all->j] == 'S')
            {
                if (empty(all, 32) || empty(all, '\t')\
                || empty(all, '\0'))
                    return (1);
            }
            all->j++;
        }
        all->j = 0;
        all->i++;
    }
    return (0);
}

int surronded(t_all *all)
{
    initialize_vars(all);
    all->i = identify_the_start(all);
    all->count = identify_the_start(all);
    while (all->map[all->i++])
        all->wid++;
    all->i = identify_the_start(all);
    while (all->map[all->i])
    {
        if (all->i == all->count
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
 //check for the last one
int up_down(t_all *all, int i)
{
    int j;

    j = 0;
    while (all->map[i][j])
    {
        if (all->map[i][j] != 32 && all->map[i][j] != '\t'\
        && all->map[i][j] != '1')
            return (1);
        j++;
    }
    if (all->map[i][j - 1] != '1')
        return (1);
    return (0);
}

int right_left(t_all *all, int i)
{
    int j;

    j = 0;
    while (all->map[i][j] == 32 || all->map[i][j] == '\t')
        j++;
    if (all->map[i][j] != '1')
        return (1);
    if (all->map[i][ft_strlen(all->map[i]) - 1] != '1')
        return (1);
    return (0);
}
