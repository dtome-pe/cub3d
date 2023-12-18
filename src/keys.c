/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/12/18 13:49:54 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	move_left(t_cub *cub)
{
	if (cub->pos_char == 'N' || cub->pos_char == 'E')
	{	
		printf("move left, pos char es n\n");
		if (cub->map[(int)(cub->pos.x - cub->dir.y * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x -= cub->dir.y * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y + cub->dir.x * cub->m)] != '1')
			cub->pos.y += cub->dir.x * cub->m;
	}
	else if (cub->pos_char == 'S' || cub->pos_char == 'W')
	{	
		printf("move left, pos char es s\n");
		if (cub->map[(int)(cub->pos.x + cub->dir.y * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x += cub->dir.y * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y - cub->dir.x * cub->m)] != '1')
			cub->pos.y -= cub->dir.x * cub->m;
	}
}

static void	move_right(t_cub *cub)
{
	if (cub->pos_char == 'N' || cub->pos_char == 'E')
	{	
		printf("move right, pos char es n\n");
		if (cub->map[(int)(cub->pos.x - cub->dir.y * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x += cub->dir.y * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y + cub->dir.x * cub->m)] != '1')
			cub->pos.y -= cub->dir.x * cub->m;
	}
	else if (cub->pos_char == 'S' || cub->pos_char == 'W')
	{	
		printf("move right, pos char es s\n");
		if (cub->map[(int)(cub->pos.x + cub->dir.y * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x -= cub->dir.y * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y - cub->dir.x * cub->m)] != '1')
			cub->pos.y += cub->dir.x * cub->m;
	}
}

static void	move_up_down(t_cub *cub, int direction)
{
	if (direction == UP)
	{	
		ft_printf(1, "up\n");
		if (cub->map[(int)(cub->pos.x + cub->dir.x * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x += cub->dir.x * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y + cub->dir.y * cub->m)] != '1')
			cub->pos.y += cub->dir.y * cub->m;
	}
	else if (direction == DOWN)
	{	
		ft_printf(1, "down\n");
		if (cub->map[(int)(cub->pos.x - cub->dir.x * cub->m)]
			[(int)(cub->pos.y)] != '1')
			cub->pos.x -= cub->dir.x * cub->m;
		if (cub->map[(int)(cub->pos.x)]
			[(int)(cub->pos.y - cub->dir.y * cub->m)] != '1')
			cub->pos.y -= cub->dir.y * cub->m;
	}
}

static void	rotate_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->dir.x;
	old_plane_x = cub->pl.x;
	if (cub->pos_char == 'N' || cub->pos_char == 'E')
	{	
		ft_printf(1, "rot left pos n\n");
		cub->dir.x = cub->dir.x * cos(cub->r) - cub->dir.y * sin(cub->r);
		cub->dir.y = old_dir_x * sin(cub->r) + cub->dir.y * cos(cub->r);
		cub->pl.x = cub->pl.x * cos(cub->r) - cub->pl.y * sin(cub->r);
		cub->pl.y = old_plane_x * sin(cub->r) + cub->pl.y * cos(cub->r);
	}
	else if (cub->pos_char == 'S' || cub->pos_char == 'W')
	{
		ft_printf(1, "rot left pos s\n");
		cub->dir.x = cub->dir.x * cos(-cub->r) - cub->dir.y * sin(-cub->r);
		cub->dir.y = old_dir_x * sin(-cub->r) + cub->dir.y * cos(-cub->r);
		cub->pl.x = cub->pl.x * cos(-cub->r) - cub->pl.y * sin(-cub->r);
		cub->pl.y = old_plane_x * sin(-cub->r) + cub->pl.y * cos(-cub->r);
	}
}

static void	rotate_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->dir.x;
	old_plane_x = cub->pl.x;
	if (cub->pos_char == 'N' || cub->pos_char == 'E')
	{	

		ft_printf(1, "rot right pos n\n");
		cub->dir.x = cub->dir.x * cos(-cub->r) - cub->dir.y * sin(-cub->r);
		cub->dir.y = old_dir_x * sin(-cub->r) + cub->dir.y * cos(-cub->r);
		cub->pl.x = cub->pl.x * cos(-cub->r) - cub->pl.y * sin(-cub->r);
		cub->pl.y = old_plane_x * sin(-cub->r) + cub->pl.y * cos(-cub->r);
	}
	else if (cub->pos_char == 'S' || cub->pos_char == 'W')
	{
		ft_printf(1, "rot right pos s\n");
		cub->dir.x = cub->dir.x * cos(cub->r) - cub->dir.y * sin(cub->r);
		cub->dir.y = old_dir_x * sin(cub->r) + cub->dir.y * cos(cub->r);
		cub->pl.x = cub->pl.x * cos(cub->r) - cub->pl.y * sin(cub->r);
		cub->pl.y = old_plane_x * sin(cub->r) + cub->pl.y * cos(cub->r);
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
		move_left(cub);
	if (key == RIGHT)
		move_right(cub);
	if (key == ROTLEFT)
		rotate_left(cub);
	if (key == ROTRIGHT)
		rotate_right(cub);
	return (0);
}

int	x_press(void)
{
	exit(0);
}
