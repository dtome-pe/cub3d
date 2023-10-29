#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int	check_elements(t_cub *cub)
{
	if (!cub->no_texture || !cub->so_texture
		|| !cub->we_texture || !cub->ea_texture
		|| !cub->ceiling_color || !cub->floor_color)
	{
		ft_printf(2, "Wrong element order. (Map is not the last element,");
		ft_printf(2, " or there are missing elements\n");
		return (1);
	}
	else
		return (0);
}

static void	bounce_map(t_cub *cub, char *line, int fd)
{
	while (line)
	{
		ft_mapback(&cub->map, ft_mapnew(line));
		free(line);
		line = get_next_line(fd);
	}
}

int	get_map(t_cub *cub, char *line, int fd)
{
	if (check_elements(cub))
	{
		free(line);
		return (1);
	}
	bounce_map(cub, line, fd);
	return (0);
}
