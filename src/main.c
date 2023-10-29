#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

static void	ft_print_cub(t_cub *cub)
{
	ft_printf(2, "path is: %s\n", cub->path);
	ft_printf(2, "north texture is: %s\n", cub->no_texture);
	ft_printf(2, "south texture is: %s\n", cub->so_texture);
	ft_printf(2, "west texture is: %s\n", cub->we_texture);
	ft_printf(2, "east texture is: %s\n", cub->ea_texture);
	ft_printf(2, "celing color is: %s\n", cub->ceiling_color);
	ft_printf(2, "floor color is: %s\n", cub->floor_color);
	print_map(cub->map);

}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (check_argv(argc, argv))
		return (1);
	init(&cub, argv);
	scene_parse(&cub);
	ft_print_cub(&cub);
	free_cub(&cub);
}
