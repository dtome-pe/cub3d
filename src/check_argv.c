/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:52:23 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/21 17:39:12 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_extension(char *file)
{
	file = ft_strrchr(file, '.');
	if (!file)
		return (1);
	if (ft_strcmp(file, ".cub"))
		return (1);
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_printf(2, "No scene file specified.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_printf(2, "Wrong number of arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "File could not be found or opened.\n");
		return (1);
	}
	close(fd);
	if (check_extension(argv[1]))
	{
		ft_printf(2, "Wrong file extension.\n");
		return (1);
	}
	return (0);
}
