#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_map
{
	char			*line;
	struct s_map	*next;

}				t_map;

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
	t_map	*map;

}			t_cub;

int		check_argv(int argc, char **argv);
void	init(t_cub *cub, char **argv);
int		scene_parse(t_cub *cub);
int		get_map(t_cub *cub, char *line, int fd);
void	free_cub(t_cub *cub);

/*map utils*/

void	print_map(t_map *map);
t_map	*ft_mapnew(char *content);
void	ft_mapback(t_map **lst, t_map *new);
t_map	*ft_maplast(t_map *lst);
void	ft_mapclear(t_map **lst);

#endif