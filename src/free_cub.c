#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	free_cub(t_cub *cub)
{
	free(cub->path);
	free(cub->no_texture);
	free(cub->so_texture);
	free(cub->we_texture);
	free(cub->ea_texture);
	free(cub->ceiling_color);
	free(cub->floor_color);
	ft_mapclear(&cub->map_list);
	ft_free_m(cub->map);
}
