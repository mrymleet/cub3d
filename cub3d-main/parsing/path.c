#include "../cub3d.h"

void    free_tmp(t_all *all)
{
    int i;

    i = 0;
    while (all->tmp[i])
    {
        free(all->tmp[i]);
        i++;
    }
    free(all->tmp);
    all->tmp = NULL;
}
int path(t_all *all)
{
    if (!ft_strncmp(all->tmp[0], "NO", 2) 
    || !ft_strncmp(all->tmp[0], "SO", 2)
    || !ft_strncmp(all->tmp[0], "EA", 2)
    || !ft_strncmp(all->tmp[0], "WE", 2))
    {
        if (all->tmp[2] != 0)
            return (1);
        if (ft_strncmp(all->tmp[1] + ft_strlen(all->tmp[1]) - 4, ".xpm", 4) != 0)
            return (1);
        if (access(all->tmp[1], F_OK | R_OK) != 0)
            return (1);
    }
    return (0);
}
int check_path(t_all *all)
{
    all->i = 0;
    all->count = 0;
    all->tmp = NULL;
    while (all->map[all->i] && all->count < 6)
    {
        all->tmp = split_two(all->map[all->i]);
        if (!all->tmp[0])
        {
            all->i++;
            continue;
        }
        if (!all->tmp[1])
            return (1);
        if (path(all))
            return (1);
        all->i++;
        all->count++;
        free_tmp(all);
    }
    return (0);
}

int count_virgules(char *str)
{
    int count;
    int i;

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

int only_num(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9')\
        && (str[i] != 32 && str[i] != '\t'))
            return (1);
        i++;
    }
    return (0);
}

int check_numbers(t_all *all, char *str)
{
    int i;
    int num;

    i = 0;
    all->tmp = ft_split(str, ',');
    if (!all->tmp)
        return (1);
    while (all->tmp[i])
    {
        if (only_num(all->tmp[i]))
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

int colors(t_all *all)
{
    char    c;

    all->i = 0;
    all->count = 0;
    while (all->map[all->i] && all->count < 6)
    {
        if (!string_empty(all->map[all->i]))
        {
            if (ft_strchr(all->map[all->i], 'F')\
            || ft_strchr(all->map[all->i], 'C'))
            {
                c = all->map[all->i][0];
                if (count_virgules(all->map[all->i]) != 2\
                || check_numbers(all, ft_strchr(all->map[all->i], c)))
                    return (1); 
            }
            all->count++;
        }
        all->i++;
    }
    return (0);
}
