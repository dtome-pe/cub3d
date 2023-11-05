#include "../inc/cub3D.h"
#include "../libft/libft.h"

int	get_length(char **map)
{
	int		i;
	int		len;
	int		rtn;

	i = 0;
	len = 0;
	rtn = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > rtn)
			rtn = len;
		i++;
	}
	return (rtn);
}

int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
