#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
	if (key == UP)
	{
		if (cub->map[ (int) (cub->pos.x + cub->dir.x * cub->move_speed)][(int) (cub->pos.y)] != '1') 
			cub->pos.x += cub->dir.x * cub->move_speed;
    	if(cub->map[(int) (cub->pos.x)][(int) (cub->pos.y + cub->dir.y * cub->move_speed)] != '1') 
			cub->pos.y += cub->dir.y * cub->move_speed;
	}
	return (0);
}

int	x_press(void)
{
	exit(0);
}
