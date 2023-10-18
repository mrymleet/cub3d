#include "../cub3d.h"

char	**read_map_1(t_all __unused *all, char *path)
{
	char	**res=NULL;
	int		fd;
	char	*line;
	int		i;
	int     count;

	i = 0;
	count = 0;
	fd = open(path, O_RDONLY);
	// if (fd < 0)
	// {
	// 	ft_printf("ERROR \n The file probably doesnt exist\n");
	// 	exit(1);
	// }
	while ((line = get_next_line(fd)))
	{
		if (!is_line_empty(line))
			count++;
		if (count == 6)
			break;
	}
	res = malloc((count_lines(path) + 1) * (sizeof(char *) + 1));
	if (!res)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		res[i] = ft_strdup(line);
		free(line);
		i++;
	}
	res[i] = 0;
	return (res);
}

int is_line_empty(char *line)
{
	int		index;

	index = 0;
	if (line[0] == '\n')
		return (1);
	while (line[index])
	{
		if (line[index] == '0' || line[index] == '1'
			|| line[index] == 'N' || line[index] == 'S'
				|| line[index] == 'W' || line[index] == 'E')
					return (0);
		index++;
	}
	return (1);
}

int	count_lines(char *path)
{
	int		count;
	int		fd;
	char	*line;
	int		count_lines;

	count = 0;
	count_lines = 0;
	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (!is_line_empty(line))
			count++;
		if (count == 6)
			break;
	}
	while ((line = get_next_line(fd)))
	{
		if (!is_line_empty(line))
			count_lines++;
	}
	close(fd);
	return (count_lines);
}