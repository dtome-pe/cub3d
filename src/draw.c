/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:39:16 by jgravalo          #+#    #+#             */
/*   Updated: 2023/11/28 19:10:13 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	char_to_int(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	set_texture(char *addr, int line, t_frame *data)
{
	int	color;

	//printf("addr: <%s>, line: %d, j: %d\n", addr, line, j);
	addr += line * data->j;
	addr += data->w * 4;
	line /= 4;
	data->sp = (float)data->r / (float)line;
	//printf("r = %f, line = %d, sp = %f ", data->r, line, data->sp);
	color = char_to_int(addr[3], addr[2], addr[1], addr[0]);
	return (color);
}

static void	draw_line(t_cub *cub, int w, t_img *frame, t_img *dir)
{
	float	j;
	t_frame	data;
	int		color;
	float	y;
	float	j2;

	j = 0;
	data.r = cub->draw_end - cub->draw_start;
	while (j < dir->line / 4)
	{
		data.j = j;
		data.w = w;
		color = set_texture(dir->addr, dir->line, &data);
		/**/for (j2 = 0; j2 < data.sp; j2++)/**/
		{
			//printf("j = %f\n", j);
			y = cub->draw_start + j * data.sp;
			//printf("y = %f\n", y);
			if (y < H)
				my_mlx_pixel_put(frame, w, y, color);
		}
		j++;
	}
}

void	draw(t_cub *cub, int w, t_img *frame)
{
	if (cub->hit_direction == NORTH)
		draw_line(cub, w, frame, cub->n);
	else if (cub->hit_direction == SOUTH)
		draw_line(cub, w, frame, cub->s);
	else if (cub->hit_direction == WEST)
		draw_line(cub, w, frame, cub->w);
	else if (cub->hit_direction == EAST)
		draw_line(cub, w, frame, cub->e);
}