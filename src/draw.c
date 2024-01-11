/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:39:16 by jgravalo          #+#    #+#             */
/*   Updated: 2024/01/11 16:05:07 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	char_to_int(unsigned char t,
	unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	set_texture(char *addr, t_img *dir, t_cub *cub)
{
	int	color;

	color = 0;
	if (cub->text_y <= 62)
	{
		addr += (dir->h * cub->text_y + cub->text_x) * 4;
		color = char_to_int(addr[3], addr[2], addr[1], addr[0]);
	}
	return (color);
}

static void	draw_line(t_cub *cub, int w, t_img *frame, t_img *dir)
{
	int	color;
	int	y;

	cub->text_x = (int)(cub->wall_x * (double)(dir->w));
	if (cub->hit_side == 0 && cub->ray.x > 0)
		cub->text_x = dir->w + cub->text_x - 1;
	if (cub->hit_side == 1 && cub->ray.y < 0)
		cub->text_x = dir->w - cub->text_x - 1;
	cub->step = 1.0 * dir->h / cub->line_height;
	cub->text_pos = (cub->draw_start - H / 2
			+ cub->line_height / 2) * cub->step;
	y = cub->draw_start;
	while (y < cub->draw_end)
	{
		cub->text_y = (int)cub->text_pos & (dir->h - 1);
		cub->text_pos += cub->step;
		color = set_texture(dir->addr, dir, cub);
		my_mlx_pixel_put(frame, w, y, color);
		y++;
	}
}

void	draw(t_cub *cub, int w, t_img *frame)
{
	if (cub->hit_direction == NORTH)
		draw_line(cub, w, frame, cub->s);
	else if (cub->hit_direction == SOUTH)
		draw_line(cub, w, frame, cub->n);
	else if (cub->hit_direction == WEST)
		draw_line(cub, w, frame, cub->e);
	else if (cub->hit_direction == EAST)
		draw_line(cub, w, frame, cub->w);
}
