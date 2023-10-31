#include "../inc/cub3D.h"
#include "../libft/libft.h"

static int	check_north(char **map, int width, int *line_len)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (width)
	{
		while (map[row] && map[row][col] != '0' &&
			map[row + 1] && line_len[row + 1] >= col)
			row++;
		if (map[row] && map[row][col] == '0')
		{
			if (row == 0)
				return (1);
			if (map[row - 1][col] != '1')
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
	row = 0;
	row = height;
	while (width)
	{
		while (map[row] && map[row][col] != '0' &&
				map[row - 1] && line_len[row - 1] >= col)
			row--;
		if (map[row] && map[row][col] == '0')
		{
			if (row == height)
				return (1);
			if (map[row + 1][col] != '1')
				return (1);
		}
		width--;
		row = height;
		col++;
	}
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
		while (map[row][col] != '\0' && map[row][col] != '0')
			col++;
		if (map[row] && map[row][col] == '0')
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

int	check_map(char **map, int *line_len)
{
	int	flag;
	int	width;
	int	height;

	flag = 0;
	width = get_length(map);
	height = get_height(map);
	flag += check_north(map, width, line_len);
	flag += check_south(map, width, height, line_len);
	flag += check_west(map);
	if (flag)
		ft_printf(2, "Map error.\n");
	return (flag);
}
