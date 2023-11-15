/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/15 09:55:46 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void	move_left_right(t_cub *cub, int direction)
{
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

	old_dir_x = cub->dir.x;
	old_plane_x = cub->pl.x;
	if (direction == ROTLEFT)
	{
		cub->dir.x = cub->dir.x * cos(cub->r) - cub->dir.y * sin(cub->r);
		cub->dir.y = old_dir_x * sin(cub->r) + cub->dir.y * cos(cub->r);
		cub->pl.x = cub->pl.x * cos(cub->r) - cub->pl.y * sin(cub->r);
		cub->pl.y = old_plane_x * sin(cub->r) + cub->pl.y * cos(cub->r);
	}
	if (direction == ROTRIGHT)
	{
		cub->dir.x = cub->dir.x * cos(-cub->r) - cub->dir.y * sin(-cub->r);
		cub->dir.y = old_dir_x * sin(-cub->r) + cub->dir.y * cos(-cub->r);
		cub->pl.x = cub->pl.x * cos(-cub->r) - cub->pl.y * sin(-cub->r);
		cub->pl.y = old_plane_x * sin(-cub->r) + cub->pl.y * cos(-cub->r);
	}
}

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
	if (key == UP)
		move_up_down(cub, UP);
	if (key == DOWN)
		move_up_down(cub, DOWN);
	if (key == LEFT)
		move_left_right(cub, LEFT);
	if (key == RIGHT)
		move_left_right(cub, RIGHT);
	if (key == ROTLEFT)
		rotate(cub, ROTLEFT);
	if (key == ROTRIGHT)
		rotate(cub, ROTRIGHT);
	return (0);
}

int	x_press(void)
{
	exit(0);
}
