/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:32:58 by jgravalo          #+#    #+#             */
/*   Updated: 2024/01/08 12:39:09 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_out(char **map, int i, int j)
{
	if (map[j][i] != ' ')
	{
		if ((!map[j][i - 1] || map[j][i - 1] == ' ')
			|| (!map[j][i + 1] || map[j][i + 1] == ' ')
			|| (!map[j - 1][i] || map[j - 1][i] == ' ')
			|| (!map[j + 1][i] || map[j + 1][i] == ' '))
		{
			if (map[j][i] != '1')
				return (1);
		}
	}
	return (0);
}

int	check_gaps(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j + 1])
	{
		i = 1;
		while (map[j][i])
		{
			if (is_out(map, i, j))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
