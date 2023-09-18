#include "cub3d.h"

int is_map_valid(t_all *all)
{
    all->map = ft_split(all->line, '\n');
    if (!all->map)
        exit (1);
    if (all_characters_exits(all) || names_correct(all)\
    || check_path(all) || colors(all))
        return (1);
    if (check_map_characters(all) || check_newlines(all)
    || surronded(all) || check_empty(all))
        return (1);
    
    return (0);
}

int main(int ac, char **av)
{
    t_all all;

    if (ac != 2)
        return (1);
    read_map(av[1], &all);
    if (is_map_valid(&all))
    {
        printf("Error\n");
        return (1);
    }
}
