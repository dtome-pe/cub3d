#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void	rotate(t_cub *cub, int direction)
{	
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cub->dir.x;
	old_plane_x = cub->plane.x;
	if (direction == ROTLEFT)
	{
      cub->dir.x = cub->dir.x * cos(-cub->rot_speed) - cub->dir.y * sin(-cub->rot_speed);
      cub->dir.y = old_dir_x * sin(-cub->rot_speed) + cub->dir.y * cos(-cub->rot_speed);
      cub->plane.x = cub->plane.x * cos(-cub->rot_speed) - cub->plane.y * sin(-cub->rot_speed);
      cub->plane.y = old_plane_x * sin(-cub->rot_speed) + cub->plane.y * cos(-cub->rot_speed);
	}
	if (direction == ROTRIGHT)
	{
      cub->dir.x = cub->dir.x * cos(cub->rot_speed) - cub->dir.y * sin(cub->rot_speed);
      cub->dir.y = old_dir_x * sin(cub->rot_speed) + cub->dir.y * cos(cub->rot_speed);
      cub->plane.x = cub->plane.x * cos(cub->rot_speed) - cub->plane.y * sin(cub->rot_speed);
      cub->plane.y = old_plane_x * sin(cub->rot_speed) + cub->plane.y * cos(cub->rot_speed);
	}
}

int	key_press(int key, t_cub *cub)
{
	printf("key is %d\n", key);
	if (key == ESC)
		exit(0);
	if (key == UP)
	{
		if (cub->map[ (int) (cub->pos.x + cub->dir.x * cub->move_speed)][(int) (cub->pos.y)] != '1') 
			cub->pos.x += cub->dir.x * cub->move_speed;
    	if(cub->map[(int) (cub->pos.x)][(int) (cub->pos.y + cub->dir.y * cub->move_speed)] != '1') 
			cub->pos.y += cub->dir.y * cub->move_speed;
	}
	if (key == DOWN)
	{
		if (cub->map[ (int) (cub->pos.x - cub->dir.x * cub->move_speed)][(int) (cub->pos.y)] != '1') 
			cub->pos.x -= cub->dir.x * cub->move_speed;
    	if(cub->map[(int) (cub->pos.x)][(int) (cub->pos.y - cub->dir.y * cub->move_speed)] != '1') 
			cub->pos.y -= cub->dir.y * cub->move_speed;
	}
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
