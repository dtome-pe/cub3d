#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

void	draw_floor_ceiling(t_cub *cub, t_img *frame)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < H)
	{
		while (x < W)
		{
			my_mlx_pixel_put(frame, x, y, cub->f_color);
			my_mlx_pixel_put(frame, x, H - y - 1, cub->c_color);
			x++;
		}
		x = 0;
		y++;
	}
}
