/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:37 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/22 19:32:11 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (check_argv(argc, argv))
		return (1);
	init_parse(&cub, argv);
	if (parse(&cub) || check(&cub))
	{
		free_cub(&cub);
		return (1);
	}
	game(&cub);
	free_cub(&cub);
}

/*
#include<stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put2(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win = NULL;
	t_data	img;
	t_data	texture;
	int x = 1920 / 2;
	int y = 1080 / 2;
	int x2 = x / 2;
	int y2 = y / 2;
	void	*relative_path = "textures/colorstone.xpm";
	int color;
	float i;
	float j;
	float i2;
	float j2;
	float	sp = 4;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x, y, "Cub3D");
	texture.img = mlx_xpm_file_to_image(mlx, relative_path, &x2, &y2);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel, &texture.line_length, &texture.endian);
//	printf("len = %zu\n", ft_strlen(texture.addr));
//	for (i = 0; i < 170; i += 1)
//		printf("texture[%d] = <<%s>>\n", i, texture.addr + i);

	color = create_trgb(0, texture.addr[0], texture.addr[1], texture.addr[2]);
//	printf("line = %d\n", texture.line_length);
	printf("endian = %d\n", texture.endian);
	printf("color = %x\n", color);
//	printf("color = %x\n", 0x00FFFFFF);
//	printf("aqui\n");

	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (j = 0; j < texture.line_length / 4; j++)
		for (i = 0; i < texture.line_length / 4; i++)
		{
			color = create_trgb(texture.addr[3], texture.addr[0], texture.addr[1], texture.addr[2]);
			for (j2 = 0; j2 < sp; j2++)
				for (i2 = 0; i2 < sp; i2++)
					my_mlx_pixel_put2(&img, 20 + ((i * sp) + i2), 20 + ((j * sp) + j2), color);
			texture.addr += 4;
		}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_put_image_to_window(mlx, mlx_win, texture.img, 120, 120);
	mlx_loop(mlx);
	return (0);
}

//char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
*/