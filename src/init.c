/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:06:26 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/09 17:22:33 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
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
	cub->longest = 0;
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
				vector(&cub->pos, x + 0.5f, y + 0.5f);
				return (cub->map[x][y]);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

void	set_dir(t_vec *dir, char c, t_cub *cub)
{
	if (c == 'N')
	{
		vector(dir, -1, 0);
		vector(&cub->pl, 0, 0.66);
	}
	else if (c == 'S')
	{
		vector(dir, 1, 0);
		vector(&cub->pl, 0, -0.66);
	}
	else if (c == 'W')
	{
		vector(dir, 0, -1);
		vector(&cub->pl, -0.66, 0);
	}
	else if (c == 'E')
	{
		vector(dir, 0, 1);
		vector(&cub->pl, 0.66, 0);
	}
}

static void	set_h_w(t_img *img, int w, int h)
{
	img->w = w;
	img->h = h;
}

void	init_game(t_cub *cub, t_mlx *mlx)
{
	char	pos;

	pos = set_pos(cub);
	cub->pos_char = pos;
	set_dir(&cub->dir, pos, cub);
	cub->m = 0.10;
	cub->r = 0.05;
	cub->n = mlx_xpm_file_to_image(mlx->mlx, cub->n_p, &cub->n_w, &cub->n_h);
	set_h_w(cub->n, cub->n_w, cub->n_h);
	cub->s = mlx_xpm_file_to_image(mlx->mlx, cub->s_p, &cub->s_w, &cub->s_h);
	set_h_w(cub->s, cub->s_w, cub->s_h);
	cub->w = mlx_xpm_file_to_image(mlx->mlx, cub->w_p, &cub->w_w, &cub->w_h);
	set_h_w(cub->w, cub->w_w, cub->w_h);
	cub->e = mlx_xpm_file_to_image(mlx->mlx, cub->e_p, &cub->e_w, &cub->e_h);
	set_h_w(cub->e, cub->e_w, cub->e_h);
	cub->n->addr = mlx_get_data_addr(cub->n,
			&cub->n->bpp, &cub->n->line, &cub->n->endian);
	cub->s->addr = mlx_get_data_addr(cub->s,
			&cub->s->bpp, &cub->s->line, &cub->s->endian);
	cub->w->addr = mlx_get_data_addr(cub->w,
			&cub->w->bpp, &cub->w->line, &cub->w->endian);
	cub->e->addr = mlx_get_data_addr(cub->e,
			&cub->e->bpp, &cub->e->line, &cub->e->endian);
}
