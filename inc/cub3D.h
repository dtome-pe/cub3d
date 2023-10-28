#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_cub
{
	/*minilibx*/
	void	*mlx_ptr;
	void	*win_ptr;

	/*map parsing*/
	char	*path;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*ceiling_color;
	char	*floor_color;
	char	**map;


}			t_cub;

int		check_argv(int argc, char **argv);
void	init(t_cub *cub, char **argv);
void	scene_parse(t_cub *cub, int argc, char **argv);

#endif