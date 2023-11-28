/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:43 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/28 15:57:26 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	get_draw(t_cub *cub)
{
	if (cub->hit_side == 0) // medimos distancia del rayo hasta la pared que gracias a como han ido escalando las distancias, es simplemente restar un delta al side, ya que hemos ido una de mas
		cub->wall_dist = cub->dist.x - cub->delta_dist.x;
	else
		cub->wall_dist = cub->dist.y - cub->delta_dist.y;
	/*cambiamos distancia en pixeles, y calculamos pixel mas bajo y mas alto*/
	cub->line_height = (int) (H / cub->wall_dist);
	cub->draw_start = -cub->line_height / 2 + H / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + H / 2;
	if (cub->draw_end >= H)
		cub->draw_end = H - 1;
}

static void	initial_calc(t_cub *cub)
{
	vector(&cub->ray, cub->dir.x + cub->pl.x * cub->camera,
		cub->dir.y + cub->pl.y * cub->camera); // direccion del rayo, que empieza en posicion de jugador.
	vector(&cub->ray_map, (int) cub->pos.x, (int) cub->pos.y); // coordenada del cuadrado donde estamos, en integros.
	vector(&cub->delta_dist, fabs(1 / cub->ray.x), fabs(1 / cub->ray.y)); // calculamos hipotenusa para calcular distancia para que siempre comprobemos si ha chocado en pared en cada limite de cuadrado
	if (cub->ray.x < 0)  //comprobamos si el rayo es x negativo o no, para ir pasando cuadrado a cuadrado por la izquierda o derecha
	{
		cub->step_x = -1;
		cub->dist.x = (cub->pos.x - cub->ray_map.x) * cub->delta_dist.x;
	}
	else
	{
		cub->step_x = 1;
		cub->dist.x = (cub->ray_map.x + 1.0 - cub->pos.x) * cub->delta_dist.x;
	}
	if (cub->ray.y < 0) // lo mismo con la y
	{
		cub->step_y = -1;
		cub->dist.y = (cub->pos.y - cub->ray_map.y) * cub->delta_dist.y;
	}
	else
	{
		cub->step_y = 1;
		cub->dist.y = (cub->ray_map.y + 1.0 - cub->pos.y) * cub->delta_dist.y;
	}
}

static void	dda(t_cub *cub)
{
	while (cub->hit == 0) // loop DDA hasta que encontremos pared
	{
		if (cub->dist.x < cub->dist.y)
		{
			cub->dist.x += cub->delta_dist.x;
			cub->ray_map.x += cub->step_x;
			cub->hit_side = 0; // pared Este o Oeste
		}
		else
		{
			cub->dist.y += cub->delta_dist.y;
			cub->ray_map.y += cub->step_y;
			cub->hit_side = 1; // pared Norte o Sud
		}
		if (cub->map[(int) cub->ray_map.x][(int) cub->ray_map.y] == '1')
		{
			cub->hit = 1;
			    // Determine the cardinal direction of the hit wall
    		if (cub->hit_side == 0) // Vertical wall
			{
				if (cub->step_x > 0)
					cub->hit_direction = SOUTH; //azul
				else
					cub->hit_direction = NORTH; //rojo
			}
    		else // Horizontal wall
			{
				if (cub->step_y > 0)
					cub->hit_direction = EAST; // blanco
				else
					cub->hit_direction = WEST; // verde
			}
		}
	}
}

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
	//data->sp = (float)line / (float)data->r;
	//printf("r = %f, line = %d, sp = %f ", data->r, line, data->sp);
	color = char_to_int(addr[3], addr[0], addr[1], addr[2]);
	return (color);
}

int	set_point(t_cub *cub, t_frame *data)
{
	int color;

	color = 0;
	//data->j = j;
	//data->w = w;
	if (cub->hit_direction == NORTH)
		color = set_texture(cub->n->addr, cub->n->line, data);
		//color = 0x00ff0000; //rojo
	else if (cub->hit_direction == SOUTH)
		color = set_texture(cub->s->addr, cub->s->line, data);
		//color = 0x000000ff; //azul
	else if (cub->hit_direction == WEST)
		color = set_texture(cub->w->addr, cub->w->line, data);
		//color = 0x0000ff00; //verde
	else if (cub->hit_direction == EAST)
		color = set_texture(cub->e->addr, cub->e->line, data);
		//color = 0x00ffffff; //blanco
	return (color);
}

static void	draw_line(t_cub *cub, int w, t_img *frame, int line)
{
	float	j;
	t_frame	data;
	int		color;
	float	y;
	float	j2;

	j = 0;
	data.r = cub->draw_end - cub->draw_start;
	while (j < line)
	//while (j < data.r)
	{
		data.j = j;
		data.w = w;
		color = set_point(cub, &data);
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

static void	draw(t_cub *cub, int w, t_img *frame)
{
	if (cub->hit_direction == NORTH)
		draw_line(cub, w, frame, cub->n->line / 4);
		//draw_line(cub, w, frame);
	else if (cub->hit_direction == SOUTH)
		draw_line(cub, w, frame, cub->s->line / 4);
		//draw_line(cub, w, frame);
	else if (cub->hit_direction == WEST)
		draw_line(cub, w, frame, cub->w->line / 4);
		//draw_line(cub, w, frame);
	else if (cub->hit_direction == EAST)
		draw_line(cub, w, frame, cub->e->line / 4);
		//draw_line(cub, w, frame);
}


static int	loop(t_cub *cub)
{
	int		i;
	t_img	frame;

	i = 0;
	frame.ptr = NULL;
	frame.ptr = mlx_new_image(cub->mlx->mlx, W, H);
	frame.addr = mlx_get_data_addr(frame.ptr, &frame.bpp,
			&frame.line, &frame.endian);
	draw_floor_ceiling(cub, &frame);
	while (i < W)
	{
		cub->hit = 0;
		cub->camera = 2 * i / (double) W - 1; // coordenada x del plano de camara que se renderiza.
		initial_calc(cub);
		dda(cub);
		get_draw(cub);
		draw(cub, i, &frame);
		i++;
	}
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->win, frame.ptr, 0, 0);
	return (0);
}

void	game(t_cub *cub)
{
	cub->mlx = malloc(sizeof(t_mlx));
	cub->mlx->mlx = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->mlx, W, H, "cub3D");
	init_game(cub, cub->mlx); // inicializamos posicion, direccion inicial del jugador y el plano de camara.
	mlx_loop_hook(cub->mlx->mlx, loop, cub);
	mlx_hook(cub->mlx->win, 2, 1L<<0, key_press, cub);
	mlx_hook(cub->mlx->win, 17, 0, x_press, game);
	mlx_loop(cub->mlx->mlx);
}