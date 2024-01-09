/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:55:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/09 19:44:27 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_cub(t_cub *cub)
{
	ft_printf(2, "path is: %s\n", cub->path);
	ft_printf(2, "north texture is: %s\n", cub->n_p);
	ft_printf(2, "south texture is: %s\n", cub->s_p);
	ft_printf(2, "west texture is: %s\n", cub->w_p);
	ft_printf(2, "east texture is: %s\n", cub->e_p);
	ft_printf(2, "celing color is: %s\n", cub->ceiling_color);
	ft_printf(2, "floor color is: %s\n", cub->floor_color);
	ft_print_m(cub->map);
}

void	print_img_info(t_cub *cub)
{
	ft_printf(2, "north: w %d, h %d, bpp %d, line h %d, endian %d\n",
		cub->n->w, cub->n->h, cub->n->bpp, cub->n->line, cub->n->endian);
	ft_printf(2, "south: w %d, h %d, bpp %d, line h %d, endian %d\n",
		cub->s->w, cub->s->h, cub->s->bpp, cub->s->line, cub->s->endian);
	ft_printf(2, "west w %d, h %d, bpp %d, line h %d, endian %d\n",
		cub->w->w, cub->w->h, cub->w->bpp, cub->w->line, cub->w->endian);
	ft_printf(2, "east w %d, h %d, bpp %d, line h %d, endian %d\n",
		cub->e->w, cub->e->h, cub->e->bpp, cub->e->line, cub->e->endian);
}

void	print_vector(t_vec *vec)
{
	printf("x is %f, y is %f\n", vec->x, vec->y);
}

int	print_error(char *str)
{
	ft_printf(2, "%s\n", str);
	return (1);
}
