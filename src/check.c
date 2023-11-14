/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:51:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:51:29 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check(t_cub *cub)
{
	if (check_color(cub, cub->ceiling_color, "ceiling")
		|| check_color(cub, cub->floor_color, "floor"))
		return (1);
	cub->c_color = create_trgb(0, ft_atoi(cub->c_rgb[0]),
			ft_atoi(cub->c_rgb[1]), ft_atoi(cub->c_rgb[2]));
	cub->f_color = create_trgb(0, ft_atoi(cub->f_rgb[0]),
			ft_atoi(cub->f_rgb[1]), ft_atoi(cub->f_rgb[2]));
	if (check_map(cub->map, cub->line_len))
		return (1);
	if (check_textures(cub))
		return (1);
	return (0);
}
