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

static void	save_values(t_cub *cub, char **split, char *type)
{	
	int	i;

	i = 0;
	if (ft_strcmp(type, "ceiling") == 0)
	{
		cub->c_rgb = malloc(sizeof(char *) * 4);
		while (split[i])
		{
			cub->c_rgb[i] = ft_strdup(split[i]);
			i++;
		}
		cub->c_rgb[i] = NULL;
	}
	else if (ft_strcmp(type, "floor") == 0)
	{
		cub->f_rgb = malloc(sizeof(char *) * 4);
		while (split[i])
		{
			cub->f_rgb[i] = ft_strdup(split[i]);
			i++;
		}
		cub->f_rgb[i] = NULL;
	}
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

int	check_color(t_cub *cub, char *color, char *type)
{
	char	**split;
	int		i;
	int		flag;

	flag = 0;
	if (contains_value_charset(color))
		return (print_error("Wrong characters in color values."));
	split = ft_split(color, ',');
	if (count_m(split) != 3)
		return (print_error("Wrong number of color values."));
	i = 0;
	while (split[i] && !flag)
	{
		if (check_number(ft_atoi(split[i])) && ++flag)
			ft_printf(2, "Wrong color value inserted.\n");
		i++;
	}
	save_values(cub, split, type);
	ft_free_m(split);
	return (flag);
}
