/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:32 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:54:33 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	free_cub(t_cub *cub)
{
	free(cub->path);
	free(cub->n_p);
	free(cub->s_p);
	free(cub->w_p);
	free(cub->e_p);
	free(cub->ceiling_color);
	free(cub->floor_color);
	ft_mapclear(&cub->map_list);
	ft_free_m(cub->map);
	ft_free_m(cub->f_rgb);
	ft_free_m(cub->c_rgb);
	free(cub->line_len);
}
