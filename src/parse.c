#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int	get_element(t_cub *cub, char *line)
{
	char	**split;
	int		flag;

	flag = 0;
	split = ft_split(line, ' ');
	if (ft_strcmp(split[0], "NO") == 0 && ++flag)
		cub->no_texture = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "SO") == 0 && ++flag)
		cub->so_texture = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "WE" ) == 0 && ++flag)
		cub->we_texture = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "EA") == 0 && ++flag)
		cub->ea_texture = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "C") == 0 && ++flag)
		cub->ceiling_color = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "F") == 0 && ++flag)
		cub->floor_color = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	ft_free_m(split);
	if (flag)
		return (0);
	else
		return (1);
}

static int	check_line(t_cub *cub, char *line, int fd)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		return (0);
	}
	if (get_element(cub, line) == 0)
	{
		free(line);
		return (0);
	}
	if (get_map(cub, line, fd) == 0)
		return (0);
	return (1);
}

int	parse(t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(cub->path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(cub, line, fd))
			return (1);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
