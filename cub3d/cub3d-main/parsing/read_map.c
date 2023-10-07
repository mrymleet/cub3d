/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:14:29 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/07 19:14:30 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    map_error(int err)
{
    if (err == 1)
        printf("Error\nFile's map must be .cub\n");
    else if (err == 2)
        printf("Error\nPlease give us the right file\n");
    else
        printf("Error\nNo map is found\n");
    exit (1);
}
void    read_map(char *str, t_all *all)
{
    int     fd;
    char   *tmp;

    if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4) != 0)
        map_error(1);
    fd = open(str, O_RDONLY);
    if (fd < 0)
        map_error(2);
    tmp = get_next_line(fd);
    if (!tmp)
        map_error(3);
    all->line = NULL;
    while (tmp)
    {
        all->line = ft_strjoin(all->line, tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
}

int names_correct(t_all *all)
{
    all->i = 0;
    while (all->line[all->i])
    {
        if ((!ft_strncmp(&all->line[all->i], "NO", 2) 
        || !ft_strncmp(&all->line[all->i], "SO", 2)
        || !ft_strncmp(&all->line[all->i], "EA", 2)
        || !ft_strncmp(&all->line[all->i], "WE", 2))
        && (all->line[all->i + 2] != 32 &&  all->line[all->i + 2] != '\t'))
            return (1);
        if ((!ft_strncmp(&all->line[all->i], "F", 1)
        || !ft_strncmp(&all->line[all->i], "C", 1))
        && (all->line[all->i + 1] != 32 &&  all->line[all->i + 1] != '\t'))
            return (1);
        all->i++;
    }
    return (0);
}

void initialize_vars(t_all *all)
{
    all->i = 0;
    all->count = 0;
    all->NO = 0;
    all->SO = 0;
    all->EA = 0;
    all->WE = 0;
    all->F = 0;
    all->C = 0;
    all->wid = 0;
}
int all_characters_exits(t_all *all)
{
    initialize_vars(all);
    while (all->map[all->i] && all->count < 6)
    {
        if (!string_empty(all->map[all->i]))
        {
            if (ft_strnstr(all->map[all->i], "NO", ft_strlen(all->map[all->i])))
                all->NO++;
            if (ft_strnstr(all->map[all->i], "SO", ft_strlen(all->map[all->i])))
                all->SO++;
            if (ft_strnstr(all->map[all->i], "EA", ft_strlen(all->map[all->i])))
                all->EA++;
            if (ft_strnstr(all->map[all->i], "WE", ft_strlen(all->map[all->i])))
                all->WE++;
            if (ft_strnstr(all->map[all->i], "F", ft_strlen(all->map[all->i])))
                all->F++;
            if (ft_strnstr(all->map[all->i], "C", ft_strlen(all->map[all->i])))
                all->C++;
            all->count++;
        }
        all->i++;
    }
    if (all->NO != 1 || all->SO != 1 || all->EA != 1 || all->WE != 1 || all->F != 1 || all->C != 1)
        return (1);
    return (0);
}
