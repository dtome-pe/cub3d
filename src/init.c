#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>

void	init_parse(t_cub *cub, char **argv)
{
	cub->path = ft_strdup(argv[1]);
	cub->n_p = NULL;
	cub->s_p = NULL;
	cub->w_p = NULL;
	cub->e_p = NULL;
	cub->ceiling_color = NULL;
	cub->floor_color = NULL;
	cub->map_list = NULL;
	cub->map = NULL;
	cub->line_len = NULL;
}

static char	set_pos(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cub->map[x])
	{
		while (cub->map[x][y])
		{
			if (is_pos(cub->map[x][y]))
			{
				vector(&cub->pos, x, y);
				return (cub->map[x][y]);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

void	set_dir(t_vec *dir, char c)
{
	if (c == 'N')
		vector(dir, -1, 0);
	else if (c == 'S')
		vector(dir, 1, 0);
	else if (c == 'W')
		vector(dir, 0, -1);
	else if (c == 'E')
		vector(dir, 0, 1);
}
/*
static void	sl_image_data(t_game *g)
{
	g->img[0].data = (int *)mlx_get_data_addr(g->img[0].img_ptr,
			&g->img[0].bpp, &g->img[0].size_l, &g->img[0].endian);
	g->img[1].data = (int *)mlx_get_data_addr(g->img[1].img_ptr,
			&g->img[1].bpp, &g->img[1].size_l, &g->img[1].endian);
	g->img[2].data = (int *)mlx_get_data_addr(g->img[2].img_ptr,
			&g->img[2].bpp, &g->img[2].size_l, &g->img[2].endian);
	g->img[3].data = (int *)mlx_get_data_addr(g->img[3].img_ptr,
			&g->img[3].bpp, &g->img[3].size_l, &g->img[3].endian);
	
}
*/

void	init_game(t_cub *cub, t_mlx *mlx)
{
	char	pos;

	pos = set_pos(cub);
	set_dir(&cub->dir, pos);
	vector(&cub->plane, 0, 0.66);
	cub->move_speed = 0.20;
	cub->rot_speed = 0.20;
	cub->n = mlx_xpm_file_to_image(mlx->mlx, cub->n_p, &cub->n_w, &cub->n_h);
	cub->s = mlx_xpm_file_to_image(mlx->mlx, cub->s_p, &cub->s_w, &cub->s_h);
	cub->w = mlx_xpm_file_to_image(mlx->mlx, cub->w_p, &cub->w_w, &cub->w_h);
	cub->e = mlx_xpm_file_to_image(mlx->mlx, cub->e_p, &cub->e_w, &cub->e_h);
	//sl_image_data(g);
}
