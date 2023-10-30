#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int	pos_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

static int	map_charset(char *line)
{
	int			i;
	static int	pos;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == ' ')
			i++;
		else if (pos_char(line[i]) && !pos)
		{
			pos = 1;
			i++;
		}
		else if (pos_char(line[i]) && pos)
		{
			ft_printf(2, "Only one initial position accepted.\n");
			return (1);
		}
		else
		{
			ft_printf(2, "Wrong character in map.\n");
			return (1);
		}
	}
	return (0);
}

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

static int	bounce_map(t_cub *cub, char *line, int fd)
{
	char	*no_nl;

	while (line && ft_strcmp(line, "\n") != 0)
	{
		no_nl = ft_substr(line, 0, ft_strlen(line) - 1);
		if (map_charset(no_nl))
		{
			free(line);
			free(no_nl);
			return (1);
		}
		ft_mapback(&cub->map_list, ft_mapnew(line));
		free(line);
		free(no_nl);
		line = get_next_line(fd);
	}
	return (0);
}

int	get_map(t_cub *cub, char *line, int fd)
{
	static int	map;

	if (map)
	{
		ft_printf(2, "Wrong configuration in file.\n");
		return (1);
	}
	if (check_elements(cub))
	{
		free(line);
		return (1);
	}
	if (bounce_map(cub, line, fd))
		return (1);
	map++;
	return (0);
}
