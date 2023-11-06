#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>

static int	key_press(int key)
{
	if (key == ESC)
	{
		exit(0);
	}
	return (0);
}

void	game(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	mlx_hook(cub->win_ptr, 2, 1L << 0, key_press, game);
	mlx_loop(cub->mlx_ptr);
}
