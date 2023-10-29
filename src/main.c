#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (check_argv(argc, argv))
		return (1);
	init(&cub, argv);
	if (parse(&cub) || check(&cub))
		return (1);
	free_cub(&cub);
}
