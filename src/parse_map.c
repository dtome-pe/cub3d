/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:31 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:56:32 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	map_charset(t_cub *cub, char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == ' ')
			i++;
		else if (pos_char(line[i]) && !cub->char_pos)
		{
			cub->char_pos = 1;
			i++;
		}
		else if (pos_char(line[i]) && cub->char_pos)
		{
			ft_printf(2, "Only one initial position accepted.\n");
			return (1);
		}
		else
		{
			ft_printf(2, "Wrong character in map: %c.\n", line[i]);
			return (1);
		}
	}
	return (0);
}

static int	check_elements(t_cub *cub)
{
	if (!cub->n_p || !cub->s_p
		|| !cub->w_p || !cub->e_p
		|| !cub->ceiling_color || !cub->floor_color)
	{
		ft_printf(2, "Wrong element order. (Map is not the last element,");
		ft_printf(2, " or there are missing elements)\n");
		return (1);
	}
	else
		return (0);
}

static int	bounce_map(t_cub *cub, char *line, int fd)
{
	char	*no_nl;

	cub->char_pos = 0;
	while (line && ft_strcmp(line, "\n") != 0)
	{
		no_nl = ft_substr(line, 0, ft_strlen(line) - 1);
		if (map_charset(cub, no_nl))
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
	if (!cub->char_pos)
	{
		ft_printf(2, "A initial position is required.\n");
		return (1);
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
