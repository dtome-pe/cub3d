/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/12/19 09:39:47 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	move_left_right(t_cub *cub, int direction)
{
	print_vector(&cub->pos);
	if (direction == LEFT)
	{
		if (cub->map[(int)(cub->pos.x - cub->dir.y * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x -= cub->dir.y * cub->m;
		if (cub->map[(int)(cub->pos.x)]
		[(int)(cub->pos.y + cub->dir.x * cub->m)] != '1')
			cub->pos.y += cub->dir.x * cub->m;
	}
	else if (direction == RIGHT)
	{
		if (cub->map[(int)(cub->pos.x + cub->dir.y * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x += cub->dir.y * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y - cub->dir.x * cub->m)] != '1')
			cub->pos.y -= cub->dir.x * cub->m;
	}
}

static void	move_up_down(t_cub *cub, int direction)
{
	print_vector(&cub->pos);
	if (direction == UP)
	{
		if (cub->map[(int)(cub->pos.x + cub->dir.x * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x += cub->dir.x * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y + cub->dir.y * cub->m)] != '1')
			cub->pos.y += cub->dir.y * cub->m;
	}
	else if (direction == DOWN)
	{
		if (cub->map[(int)(cub->pos.x - cub->dir.x * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x -= cub->dir.x * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y - cub->dir.y * cub->m)] != '1')
			cub->pos.y -= cub->dir.y * cub->m;
	}
}

static void	rotate(t_cub *cub, int direction)
{
	double	old_dir_x;
	double	old_plane_x;

	if (direction == ROTLEFT)
	{
		old_dir_x = cub->dir.x;
		old_plane_x = cub->pl.x;
		cub->dir.x = cub->dir.x * cos(cub->r) - cub->dir.y * sin(cub->r);
		cub->dir.y = old_dir_x * sin(cub->r) + cub->dir.y * cos(cub->r);
		cub->pl.x = cub->pl.x * cos(cub->r) - cub->pl.y * sin(cub->r);
		cub->pl.y = old_plane_x * sin(cub->r) + cub->pl.y * cos(cub->r);
	}
	else if (direction == ROTRIGHT)
	{
		old_dir_x = cub->dir.x;
		old_plane_x = cub->pl.x;
		cub->dir.x = cub->dir.x * cos(-cub->r) - cub->dir.y * sin(-cub->r);
		cub->dir.y = old_dir_x * sin(-cub->r) + cub->dir.y * cos(-cub->r);
		cub->pl.x = cub->pl.x * cos(-cub->r) - cub->pl.y * sin(-cub->r);
		cub->pl.y = old_plane_x * sin(-cub->r) + cub->pl.y * cos(-cub->r);
	}
}

int	key_press(int key, t_cub *cub)
{	
	printf("key is %d\n", key);
	if (key == ESC)
		exit(0);
	if (key == UP || key == DOWN)
		move_up_down(cub, key);
	if (key == LEFT || key == RIGHT)
		move_left_right(cub, key);
	if (key == ROTLEFT || key == ROTRIGHT)
		rotate(cub, key);
	return (0);
}

int	x_press(void)
{
	exit(0);
}
