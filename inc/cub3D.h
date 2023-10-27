#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_cub
{
	/*minilibx*/
	void	*mlx_ptr;
	void	*win_ptr;

	/*map parsing*/
	char	*map;

}			t_cub;

int		check_argv(int argc, char **argv);
void	scene_parse(t_cub *cub, int argc, char **argv);

#endif