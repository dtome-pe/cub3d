#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int	key_press(int key)
{
	if (key == ESC)
	{
		exit(0);
	}
	return (0);
}

static void	initial_calc(t_cub *cub)
{
	vector(&cub->ray, cub->dir.x + cub->plane.x * cub->camera,
		cub->dir.y + cub->plane.y * cub->camera);
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
		cub->dist.y = (cub->pos.y - cub->ray_map.y * cub->delta_dist.y;
	}
	else
	{
		cub->step_y = 1;
		cub->dist.y = (cub->ray_map.y + 1.0 - cub->pos.y) * cub->delta_dist.y;
	}
}

static int	loop(t_cub *cub)
{
	int	i;

	i = 0;
	while (i <= W)
	{
		cub->camera = 2 * i / (double) W - 1;
		initial_calc(cub);
		i++;
	}
	return (0);
}

void	game(t_cub *cub)
{
	init_game(cub);
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, W, H, "cub3D");
	mlx_hook(cub->win_ptr, 2, 1L << 0, key_press, game);
	loop(cub);
	//mlx_loop_hook(cub->mlx_ptr, loop, cub);
	mlx_loop(cub->mlx_ptr);
}
