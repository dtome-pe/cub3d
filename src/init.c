#include "../inc/cub3D.h"
#include "../libft/libft.h"

void	init(t_cub *cub, char **argv)
{
	cub->path = ft_strdup(argv[1]);
	cub->no_texture = NULL;
	cub->so_texture = NULL;
	cub->we_texture = NULL;
	cub->ea_texture = NULL;
	cub->ceiling_color = NULL;
	cub->floor_color = NULL;
	cub->map = NULL;
}
