/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:53:08 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:27 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	get_length(char **map)
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

int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}
