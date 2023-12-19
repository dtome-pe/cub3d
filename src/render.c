/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:19:01 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:58 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	get_draw(t_cub *cub)
{
	if (cub->hit_side == 0)
		cub->wall_dist = cub->dist.x - cub->delta_dist.x;
	else
		cub->wall_dist = cub->dist.y - cub->delta_dist.y;
	cub->line_height = (int)(H / cub->wall_dist);
	cub->draw_start = -cub->line_height / 2 + H / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + H / 2;
	if (cub->draw_end >= H)
		cub->draw_end = H - 1;
	if (cub->hit_side == 0)
		cub->wall_x = cub->pos.y + cub->wall_dist * cub->ray.y;
	else
		cub->wall_x = cub->pos.x + cub->wall_dist * cub->ray.x;
	cub->wall_x -= floor((cub->wall_x));
}

static void	initial_calc(t_cub *cub)
{
	vector(&cub->ray, cub->dir.x + cub->pl.x * cub->camera,
		cub->dir.y + cub->pl.y * cub->camera);
	vector(&cub->ray_map, (int) cub->pos.x, (int) cub->pos.y);
	vector(&cub->delta_dist, fabs(1 / cub->ray.x), fabs(1 / cub->ray.y));
	if (cub->ray.x < 0)
	{
		cub->step_x = -1;
		cub->dist.x = (cub->pos.x - cub->ray_map.x) * cub->delta_dist.x;
	}
	else
	{
		cub->step_x = 1;
		cub->dist.x = (cub->ray_map.x + 1.0 - cub->pos.x) * cub->delta_dist.x;
	}
	if (cub->ray.y < 0)
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

static void	dda_aux(t_cub *cub)
{
	if (cub->hit_side == 0)
	{
		if (cub->step_x > 0)
			cub->hit_direction = SOUTH;
		else
			cub->hit_direction = NORTH;
	}
	else
	{
		if (cub->step_y > 0)
			cub->hit_direction = EAST;
		else
			cub->hit_direction = WEST;
	}
}

static void	dda(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if (cub->dist.x < cub->dist.y)
		{
			cub->dist.x += cub->delta_dist.x;
			cub->ray_map.x += cub->step_x;
			cub->hit_side = 0;
		}
		else
		{
			cub->dist.y += cub->delta_dist.y;
			cub->ray_map.y += cub->step_y;
			cub->hit_side = 1;
		}
		if (cub->map[(int) cub->ray_map.x][(int) cub->ray_map.y] == '1')
		{
			cub->hit = 1;
			dda_aux(cub);
		}
	}
}

int	render_loop(t_cub *cub)
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
		cub->camera = 2 * i / (double) W - 1;
		initial_calc(cub);
		dda(cub);
		get_draw(cub);
		draw(cub, i, &frame);
		i++;
	}
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->win, frame.ptr, 0, 0);
	mlx_destroy_image(cub->mlx->mlx, frame.ptr);
	return (0);
}
