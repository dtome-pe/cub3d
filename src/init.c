#include "../inc/cub3D.h"
#include "../libft/libft.h"

void	init_parse(t_cub *cub, char **argv)
{
	cub->path = ft_strdup(argv[1]);
	cub->no_texture = NULL;
	cub->so_texture = NULL;
	cub->we_texture = NULL;
	cub->ea_texture = NULL;
	cub->ceiling_color = NULL;
	cub->floor_color = NULL;
	cub->map_list = NULL;
	cub->map = NULL;
	cub->line_len = NULL;
}

static char	set_pos(t_cub *cub)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (cub->map[row])
	{
		while (cub->map[row][col])
		{
			if (is_pos(cub->map[row][col]))
			{
				set_vector(&cub->pos, col, row);
				return (cub->map[row][col]);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (0);
}

void	set_dir(t_vec *dir, char c)
{
	if (c == 'N')
		set_vector(dir, 0, 1);
	else if (c == 'S')
		set_vector(dir, 0, -1);
	else if (c == 'W')
		set_vector(dir, -1, 0);
	else if (c == 'E')
		set_vector(dir, 1, 0);
}

void	init_game(t_cub *cub)
{
	char	pos;

	pos = set_pos(cub);
	set_dir(&cub->dir, pos);
	set_vector(&cub->plane, 0, 0.66);
}
