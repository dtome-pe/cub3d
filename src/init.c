/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:06:26 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/23 17:54:16 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
//#include "../libft/libft.h"
//#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

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

void	get_data_img(t_img *texture, t_mlx *mlx, char *path)
{
	texture = mlx_xpm_file_to_image(mlx->mlx, path, &texture->w, &texture->h);
	//texture->addr = mlx_get_data_addr(texture->ptr, &texture->bpp, &texture->line, &texture->endian);
}

void	init_game(t_cub *cub, t_mlx *mlx)
{
	char	pos;

	pos = set_pos(cub);
	set_dir(&cub->dir, pos);
	vector(&cub->pl, 0, 0.66);
	cub->m = 0.20;
	cub->r = 0.10;
	/*
	get_data_img(cub->n, mlx, cub->n_p);
	get_data_img(cub->s, mlx, cub->s_p);
	get_data_img(cub->w, mlx, cub->w_p);
	get_data_img(cub->e, mlx, cub->e_p);
	*/
	printf("n = %s\ns = %s\nw = %s\ne = %s\n", cub->n_p, cub->s_p, cub->w_p, cub->e_p);
	cub->n = mlx_xpm_file_to_image(mlx->mlx, cub->n_p, &cub->n_w, &cub->n_h);
	cub->s = mlx_xpm_file_to_image(mlx->mlx, cub->s_p, &cub->s_w, &cub->s_h);
	printf("aqui\n");
	cub->w= mlx_xpm_file_to_image(mlx->mlx, cub->w_p, &cub->w_w, &cub->w_h);
	cub->e = mlx_xpm_file_to_image(mlx->mlx, cub->e_p, &cub->e_w, &cub->e_h);

	cub->n->addr = mlx_get_data_addr(cub->n, &cub->n->bpp, &cub->n->line, &cub->n->endian);
	cub->s->addr = mlx_get_data_addr(cub->s, &cub->s->bpp, &cub->s->line, &cub->s->endian);
	cub->w->addr = mlx_get_data_addr(cub->w, &cub->w->bpp, &cub->w->line, &cub->w->endian);
	cub->e->addr = mlx_get_data_addr(cub->e, &cub->e->bpp, &cub->e->line, &cub->e->endian);
	
	printf("addr: <%s>, line: %d\n", cub->n->addr, cub->n->line);
}