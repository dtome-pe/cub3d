/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:53:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/08 13:36:27 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_north(char **map, int width, int *line_len)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (width)
	{
		while (line_len[row] < col)
			row++;
		while (map[row] && (map[row][col] != '0' && !is_pos(map[row][col])) &&
			map[row + 1] && line_len[row + 1] >= col)
			row++;
		if (map[row] && (map[row][col] == '0' || is_pos(map[row][col])))
		{
			if (row == 0)
				return (1);
			if (line_len[row - 1] < col || map[row - 1][col] != '1')
				return (1);
		}
		width--;
		row = 0;
		col++;
	}
	return (0);
}

/*
static int	check_south(char **map, int width, int height, int *line_len)
{
	int	col;
	int	row;

	col = 0;
	row = height;
	while (width)
	{
		while (map[row] && (map[row][col] != '0' && !is_pos(map[row][col])) &&
				map[row - 1] && line_len[row - 1] >= col)
			row--;
		if (map[row] && (map[row][col] == '0' || is_pos(map[row][col])))
		{
			if (row == height)
			{
				printf("sur mal\n");
				return (1);
			}
			if (map[row + 1][col] != '1')
			{
				printf("sur mal\n");
				return (1);
			}
		}
		width--;
		row = height;
		col++;
	}
	printf("sur bien\n");
	return (0);
} */

static int	check_west(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		while (map[row][col] != '\0' && (map[row][col] != '0'
			&& !is_pos(map[row][col])))
			col++;
		if (map[row] && (map[row][col] == '0' || is_pos(map[row][col])))
		{
			if (col == 0)
				return (1);
			if (map[row][col - 1] != '1')
				return (1);
		}
		row++;
		col = 0;
	}
	return (0);
}

static int	check_east(char **map, int *line_len)
{
	int	row;
	int	col;

	row = 0;
	col = line_len[row];
	while (map[row])
	{
		while (col != 0 && (map[row][col] != '0' && !is_pos(map[row][col])))
			col--;
		if (map[row] && (map[row][col] == '0' || is_pos(map[row][col])))
		{
			if (col == line_len[row])
				return (1);
			if (map[row][col + 1] != '1')
				return (1);
		}
		++row;
		if (map[row])
			col = line_len[row];
	}
	return (0);
}

static int	check_south(char **map, int height, int width)
{
	int	i;

	i = 0;
	height--;
	while (i < width)
	{
		if ((map[height - 1][i] == '0')
			&& map[height][i] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map(char **map, int *line_len)
{
	int	width;
	int	height;

	width = get_length(map);
	height = get_height(map);
	if (check_north(map, width, line_len)
		|| check_south(map, height, width) || check_west(map)
		|| check_east(map, line_len) || check_gaps(map))
	{
		ft_printf(2, "Map is not enclosed by walls.\n");
		return (1);
	}
	return (0);
}
