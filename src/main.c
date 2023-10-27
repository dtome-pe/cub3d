#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	ft_printf(1, "soy un main\n");

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 400, "window");
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
}
