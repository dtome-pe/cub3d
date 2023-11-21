/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:16 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/21 17:41:25 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_floor_ceiling(t_cub *cub, t_img *frame)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < H)
	{
		while (x < W)
		{
			my_mlx_pixel_put(frame, x, y, cub->f_color);
			my_mlx_pixel_put(frame, x, H - y - 1, cub->c_color);
			x++;
		}
		x = 0;
		y++;
	}
}
