#ifndef CUB3D_H
# define CUB3D_H

# define W 640
# define H 480
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define ESC (53) //mac
//# define ESC (65307) linux
//# define UP 119 linux
// # define DOWN 115 linux
// # define LEFT 97 linux
// # define RIGHT 100 linux
//# define ROTLEFT 65361 linux
//# define ROTRIGHT 65363 linux
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ROTLEFT 123
# define ROTRIGHT 124


typedef struct s_map
{
	char			*line;
	struct s_map	*next;

}				t_map;

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct		s_img
{
	void		*ptr;
	char		*addr;		// In my code I changed this to int *, which I will explain in a second
	int			bpp;	//when using ARGB this value is always 32
	int			line;	//This value represents (your image width) * 4 which I will also explain after
	int			endian;		//This value can be either 0 or 1 and will indicate how the ARGB bytes are organized (from front to back or back to front)
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;


typedef struct s_cub
{
	/*minilibx*/
	t_mlx	*mlx;

	/*map parsing - checking*/
	char	*path;
	char	*n_p;
	char	*s_p;
	char	*w_p;
	char	*e_p;
	char	*ceiling_color;
	char	*floor_color;
	t_map	*map_list;
	char	**map;
	int		*line_len;
	int		char_pos;

	/*raycasting calculations*/
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	t_vec	ray;
	t_vec	ray_map;
	t_vec	dist;
	t_vec	delta_dist;
	double	camera;
	int		step_x;
	int		step_y;
	int		hit;
	int		hit_side;
	int		hit_direction;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	move_speed;
	double	rot_speed;

	/*game images*/
	t_img	*n;
	int		n_w;
	int		n_h;
	t_img	*s;
	int		s_w;
	int		s_h;
	t_img	*w;
	int		w_w;
	int		w_h;
	t_img	*e;
	int		e_w;
	int		e_h;
}			t_cub;

/*parse - check*/
void	init_parse(t_cub *cub, char **argv);

int		check_argv(int argc, char **argv);
int		parse(t_cub *cub);
int		get_map(t_cub *cub, char *line, int fd);
int		check(t_cub *cub);
int		check_color(char *color);
int		check_map(char **map, int *line_len);
int		check_single(char **map, int *line_len);
int		check_textures(t_cub *cub);
int		get_length(char **map);
int		get_height(char **map);
int		is_pos(char c);

/*game - raycasting*/
void	init_game(t_cub *cub, t_mlx *mlx);
void	game(t_cub *cub);

void	free_cub(t_cub *cub);

/*keys*/
int		key_press(int key, t_cub *cub);
int		x_press(void);

/*map utils*/

void	print_map(t_map *map);
t_map	*ft_mapnew(char *content);
void	ft_mapback(t_map **lst, t_map *new);
t_map	*ft_maplast(t_map *lst);
void	ft_mapclear(t_map **lst);

/*print utils*/
void	print_cub(t_cub *cub);
void	print_vector(t_vec *vec);

/*vector utils*/
void	vector(t_vec *vec, double x, double y);

/*mlx utils*/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif