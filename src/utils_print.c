#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdio.h>

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

void	print_vector(t_vec *vec)
{
	printf("x is %f, y is %f\n", vec->x, vec->y);
}
