/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:16 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:54:17 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

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
