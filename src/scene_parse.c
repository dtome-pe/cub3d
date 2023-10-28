#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>

static int	check_correct(t_cub *cub)
{
	if (!cub->no_texture || !cub->so_texture
		|| !cub->we_texture || !cub->ea_texture
		|| !cub->ceiling_color || !cub->floor_color
		|| !cub->map)
		return (1);
	else
		return (0);
}

static int	get_element(t_cub *cub, char *line)
{
	char	**split;
	int		flag;

	flag = 0;
	split = ft_split(line, ' ');
	if (ft_strcmp(line, "NO") == 0 && flag++)
		cub->no_texture = ft_strdup(split[1]);
	else if (ft_strcmp(line, "SO") == 0 && flag++)
		cub->so_texture = ft_strdup(split[1]);
	else if (ft_strcmp(line, "WE" ) == 0 && flag++)
		cub->we_texture = ft_strdup(split[1]);
	else if (ft_strcmp(line, "EA") == 0 && flag++)
		cub->ea_texture = ft_strdup(split[1]);
	else if (ft_strcmp(line, "C") == 0 && flag++)
		cub->ceiling_color = ft_strdup(split[1]);
	else if (ft_strcmp(line, "F") == 0 && flag++)
		cub->floor_color = ft_strdup(split[1]);
	ft_free_m(split);
	if (flag)
		return (0);
	else
		return (1);
}

static int	check_line(t_cub *cub, char *line, int fd)
{
	if (ft_strcmp(line, "\n") == 0)
		return (0);
	if (get_element(cub, line) == 0)
		return (0);
}

void	scene_parse(t_cub *cub, int argc, char **argv)
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
	if (check_correct(cub))
		return (1);
	return (0);
}
