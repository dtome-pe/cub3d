/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:53:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/16 19:30:12 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_south(char **map, int height, int width)
{
	int	i;

	i = 0;
	height--;
	while (i < width)
	{
		if (map[height][i] == '0' || is_pos(map[height][i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_west(char **map, int height, int width)
{
	int	i;

	i = 0;
	width--;
	while (i < height - 1)
	{
		if (map[i][0] == '0' || is_pos(map[i][0]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_east(char **map, int height, int width)
{
	int	i;

	i = 0;
	width--;
	while (i < height - 1)
	{
		if (map[i][width] == '0' || is_pos(map[i][width]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_north(char **map, int height, int width)
{
	int	i;

	i = 0;
	height--;
	while (i < width)
	{
		if ((map[0][i] == '0') || is_pos(map[0][i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char **map, int *line_len)
{
	int	width;
	int	height;

	(void)line_len;
	ft_print_m(map);
	width = get_length(map);
	height = get_height(map);
	if (check_north(map, height, width)
		|| check_south(map, height, width) || check_west(map, height, width)
		|| check_east(map, height, width))
	{
		ft_printf(2, "Error.\nMap is not enclosed by walls.\n");
		return (1);
	}
	if (check_gaps(map))
		return (1);
	return (0);
}
