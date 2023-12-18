/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:39:16 by jgravalo          #+#    #+#             */
/*   Updated: 2023/12/18 13:50:01 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int i = 0;

int	char_to_int(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	/* printf("<%c><%c><%c><%c>\n", b, g, r, t);
	printf("dentro\n"); */
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	set_texture(char *addr, int line, int w, t_frame *data, t_img *dir, t_cub *cub)
{
	int	color;
	int sum;

	if (!addr)
		return (0);
	(void) line;
	(void) w;
	(void) data;
 	//printf("addr: <%s>, line: %d, j: %d\n", addr, line, j);
	dir->h = 64;
	sum = (dir->h * cub->text_y + cub->text_x) * 4;
	addr += sum; // ajustamos addr para la coordenada vertical
	//printf("h = %d, text_y = %d, text_x = %d\n", dir->h, cub->text_y, cub->text_x);
	//printf("%d\n", sum);
	/*data->sp = (float)data->r / (float)(line / 4);
	if ((float)data->r < (float)(line / 4))
		data->w = w * 4;
	else if ((float)data->r > (float)(line / 4))
		data->w = w / 4;
	else
		data->w = w;
	addr += data->w * 4; // ajustamos addr para la coordenada horizontal
	//printf("r = %f, line = %d, sp = %f ", data->r, line, data->sp); */
	//printf("<<%s>>\n", addr);
	
	/* printf("antes\n");
	printf("res = %d\n", (dir->h * cub->text_y + cub->text_x) * 4); */
	color = 0;
	/* if (sum >= 0)
	{ */
		//printf("<%s>\n", addr);
		color = char_to_int(addr[3], addr[2], addr[1], addr[0]);
	//}
	//printf("despues\n");
	return (color);
}

static void	draw_line(t_cub *cub, int w, t_img *frame, t_img *dir)
{
	//float	j;
	t_frame	data;
	int		color;
	int	y;
	//float	j2;
	//int		i;

	//if (cub->draw_start == 0) j = {} ; //para ajustar la vista cerca del muro
	
	/*nuevos calculos de iodev*/
	dir->w = 64;
	dir->h = 64;
	cub->text_x = (int) (cub->wall_x * (double)(dir->w));
	if (cub->hit_side == 0 && cub->ray.x > 0)
		cub->text_x = dir->w + cub->text_x - 1;
	if (cub->hit_side == 1 && cub->ray.y < 0)
		cub->text_x = dir->w - cub->text_x - 1;
	cub->step = 1.0 * dir->h / cub->line_height;
	cub->text_pos = (cub->draw_start - H / 2 + cub->line_height / 2) * cub->step;
	y = cub->draw_start;
	/*nuevos calculos de iodev*/
	//j = 0;
	data.r = cub->draw_end - cub->draw_start; // calculamos tama
	while (y < cub->draw_end)
	{	
		cub->text_y = (int)cub->text_pos & (dir->h - 1);
		cub->text_pos += cub->step;
		//data.j = j;
		//printf("<%s>\n", dir->addr);
		color = set_texture(dir->addr, dir->line, w, &data, dir, cub);
 		/* if (direction == NORTH)
			color = 0xFF3333;
		if (direction == SOUTH)
			color = 0xE0FF33;
		if (direction == WEST)
			color = 0x9933FF;
		if (direction == EAST)
			color = 0x33FCFF; */
		//j2 = 0;
/*  		while (j2 < data.sp)*/
	//	{
			//printf("j = %f\n", j);
		//	y = cub->draw_start + j * data.sp;
			//printf("y = %f\n", y);
			//if (y < H) */ */
		my_mlx_pixel_put(frame, w, y, color);
/* 			j2++;
		}
		j += 0.1; */
		y++;
	}
}

void	draw(t_cub *cub, int w, t_img *frame)
{
	//if (cub->pos_char == 'N' || cub->pos_char == 'E')
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
	/* else
	{
		if (cub->hit_direction == NORTH)
			draw_line(cub, w, frame, cub->s);
		else if (cub->hit_direction == SOUTH)
			draw_line(cub, w, frame, cub->n);
		else if (cub->hit_direction == WEST)
			draw_line(cub, w, frame, cub->w);
		else if (cub->hit_direction == EAST)
			draw_line(cub, w, frame, cub->e);
	} */
}