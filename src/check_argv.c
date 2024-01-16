/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:52:23 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/16 19:30:38 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_extension(char *file, char *extension)
{
	file = ft_strrchr(file, '.');
	if (!file)
		return (1);
	if (ft_strcmp(file, extension))
		return (1);
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_printf(2, "Error.\nNo scene file specified.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_printf(2, "Error.\nWrong number of arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "Error.\nFile could not be found or opened.\n");
		return (1);
	}
	close(fd);
	if (check_extension(argv[1], ".cub"))
	{
		ft_printf(2, "Error.\nWrong file extension.\n");
		return (1);
	}
	return (0);
}
