#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int	check_number(int number)
{
	if (number >= 0 && number <= 255)
		return (0);
	else
		return (1);
}

static int	count_m(char **m)
{
	int	i;

	i = 0;
	while (m[i])
		i++;
	return (i);
}

static int	contains_value_charset(char *number)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (number[i])
	{
		if (number[i] >= '0' && number[i] <= '9')
			i++;
		else if (number[i] == ',')
		{
			i++;
			commas++;
		}
		else
			return (1);
	}
	if (commas != 2)
		return (1);
	else
		return (0);
}

int	check_color(char *color)
{
	char	**split;
	int		i;
	int		flag;

	flag = 0;
	if (contains_value_charset(color))
	{
		ft_printf(2, "Wrong characters in color values.\n");
		return (1);
	}
	split = ft_split(color, ',');
	if (count_m(split) != 3)
	{
		ft_printf(2, "Wrong number of color values.\n");
		return (1);
	}
	i = 0;
	while (split[i] && !flag)
	{
		if (check_number(ft_atoi(split[i])) && ++flag)
			ft_printf(2, "Wrong color value inserted.\n");
		i++;
	}
	ft_free_m(split);
	return (flag);
}
