/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:32 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/21 17:41:37 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
