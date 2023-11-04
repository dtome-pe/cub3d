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
	{
		ft_printf(1, "Not Ok!\n");
		free_cub(&cub);
		return (1);
	}
	ft_printf(1, "Ok!\n");
	free_cub(&cub);
}
