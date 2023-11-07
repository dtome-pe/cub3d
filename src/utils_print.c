#include "../inc/cub3D.h"
#include "../libft/libft.h"

void	print_cub(t_cub *cub)
{
	ft_printf(2, "path is: %s\n", cub->path);
	ft_printf(2, "north texture is: %s\n", cub->no_texture);
	ft_printf(2, "south texture is: %s\n", cub->so_texture);
	ft_printf(2, "west texture is: %s\n", cub->we_texture);
	ft_printf(2, "east texture is: %s\n", cub->ea_texture);
	ft_printf(2, "celing color is: %s\n", cub->ceiling_color);
	ft_printf(2, "floor color is: %s\n", cub->floor_color);
	ft_print_m(cub->map);
}

void	print_vector(t_vec *vec)
{
	ft_printf(1, "x is %d, y is %d\n", vec->x, vec->y);
}
