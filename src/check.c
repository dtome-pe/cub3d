#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	check(t_cub *cub)
{
	if (check_color(cub->ceiling_color) || check_color(cub->floor_color))
		return (1);
	if (check_map(cub->map, cub->line_len))
		return (1);
	return (0);
}
