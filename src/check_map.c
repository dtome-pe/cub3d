/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:53:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/09 18:19:45 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
/*
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
			if ((row == 0)
				|| (line_len[row - 1] < col || map[row - 1][col] != '1'))
			{
				printf("map[%d][%d]\n", row, col);
				printf("norte mal\n");
				return (1);
			}
		width--;
		row = 0;
		col++;
	}
	return (0);
}


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
			if ((row == height) || (map[row + 1][col] != '1'))
			{
				printf("sur mal\n");
				return (1);
			}
		width--;
		row = height;
		col++;
	}
	printf("sur bien\n");
	return (0);
}

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
			if ((col == 0) || (map[row][col - 1] != '1'))
			{
				printf("oeste mal\n");
				return (1);
			}
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
			if ((col == line_len[row]) || (map[row][col + 1] != '1'))
			{
				printf("este mal\n");
				return (1);
			}
		}
		++row;
		if (map[row])
			col = line_len[row];
	}
	return (0);
} */


static int	check_south(char **map, int height, int width)
{
	int	i;

	i = 0;
	printf("witdh = %d\n", width);
	height--;
	printf("last line = %s\n", map[height - 1]);
	printf("last line = %s\n", map[height]);
	while (i < width)
	{
		if (map[height][i] == '0' || is_pos(map[height][i]))
		{
			printf("sur mal\n");
			return (1);
		}
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
		{
			printf("map[%d][%d] = <%c>\n", 0, i, map[0][i]);
			printf("oeste mal\n");
			return (1);
		}
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
		{
			printf("map[%d][%d] = <%c>\n", 0, i, map[0][i]);
			printf("este mal\n");
			return (1);
		}
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
		{
			printf("map[%d][%d] = <%c>\n", 0, i, map[0][i]);
			printf("norte mal\n");
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

	(void)line_len;
	ft_print_m(map);
	width = get_length(map);
	height = get_height(map);
	if (check_north(map, height, width)
		|| check_south(map, height, width) || check_west(map, height, width)
		|| check_east(map, height, width) || check_gaps(map))
	{
		ft_printf(2, "Map is not enclosed by walls.\n");
		return (1);
	}
	return (0);
}
