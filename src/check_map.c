#include "../inc/cub3D.h"
#include "../libft/libft.h"

static int	get_length(char **map)
{
	int		i;
	int		len;
	int		rtn;

	i = 0;
	len = 0;
	rtn = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > rtn)
			rtn = len;
		i++;
	}
	return (rtn);
}

static int	check_north(char **map, int n, int *line_len)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (n)
	{
		while (map[row] && map[row][col] != '0' &&
			map[row + 1] && line_len[row + 1] >= col)
			row++;
		if (map[row] && map[row][col] == '0')
		{
			if (map[row - 1][col] != '1')
				return (1);
		}
		n--;
		row = 0;
		col++;
	}
	return (0);
}

static int	check_south(char **map, int n, int *line_len)
{
	int	col;
	int	row;
	int	save;

	col = 0;
	row = 0;
	while (map[row])
		row++;
	save = row;
	while (n)
	{
		while (map[row] && map[row][col] != '0' &&
				map[row - 1] && line_len[row - 1] >= col)
			row--;
		if (map[row] && map[row][col] == '0')
		{
			if (map[row + 1][col] != '1')
				return (1);
		}
		n--;
		row = save;
		col++;
	}
	return (0);
}

int	check_map(char **map, int *line_len)
{
	int	flag;
	int	len;

	len = get_length(map);
/* 	ft_print_m(map); */
	flag = check_north(map, len, line_len);
	flag = check_south(map, len, line_len);
	if (flag)
		ft_printf(2, "Map error.\n");
	return (flag);
}
