#include "../inc/cub3D.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (check_argv(argc, argv))
		return (1);
	init(&cub, argv);
	if (parse(&cub) || check(&cub))
	{
		free_cub(&cub);
		return (1);
	}
	game(&cub);
	free_cub(&cub);
}
