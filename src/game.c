/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:43 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/12/19 09:44:27 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	game(t_cub *cub)
{
	cub->mlx = malloc(sizeof(t_mlx));
	cub->mlx->mlx = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->mlx, W, H, "cub3D");
	init_game(cub, cub->mlx);
	mlx_loop_hook(cub->mlx->mlx, render_loop, cub);
	mlx_hook(cub->mlx->win, 2, 1L<<0, key_press, cub);
	//mlx_hook(cub->mlx->win, 2, 02, key_press, cub);
	mlx_hook(cub->mlx->win, 17, 0, x_press, game);
	mlx_loop(cub->mlx->mlx);
}
