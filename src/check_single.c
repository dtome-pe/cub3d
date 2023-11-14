/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:53:49 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:54:00 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

static	char	**map_cpy(char **map)
{
	char	**rtn;
	int		i;

	rtn = (char **)malloc(sizeof (char *) * (ft_count_arr(map) + 1));
	i = 0;
	while (map[i])
	{
		rtn[i] = ft_strdup(map[i]);
		i++;
	}
	rtn[i] = NULL;
	return (rtn);
}

static int	check_visited(char **new)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (new[row])
	{
		while (new[row][col])
		{
			if (new[row][col] != ' ' && new[row][col] != 'V')
			{
				ft_printf(2, "Map is not continuous.\n");
				return (1);
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

static void	dfs(char **new, int row, int col, int *line_len)
{
	if (col < 0 || row < 0 || row + 1 > ft_count_arr(new)
		|| col > line_len[row] || new[row][col] == '\0'
		|| new[row][col] == 'V' || new[row][col] == ' ')
		return ;
	new[row][col] = 'V';
	dfs(new, row, col + 1, line_len);
	dfs(new, row, col - 1, line_len);
	dfs(new, row + 1, col, line_len);
	dfs(new, row - 1, col, line_len);
}

int	check_single(char **map, int *line_len)
{
	char	**new;
	int		row;
	int		col;
	int		rtn;

	new = map_cpy(map);
	row = 0;
	col = 0;
	while (map[row][col] == ' ')
		col++;
	dfs(new, row, col, line_len);
	rtn = check_visited(new);
	ft_free_m(new);
	return (rtn);
}
