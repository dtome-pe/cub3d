/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:11 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:56:12 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int	count_list(t_map *map)
{
	int		c;
	t_map	*ptr;

	ptr = map;
	c = 0;
	while (ptr)
	{
		c++;
		ptr = ptr->next;
	}
	return (c);
}

static int	get_element(t_cub *cub, char *line)
{
	char	**split;
	int		flag;

	flag = 0;
	split = ft_split(line, ' ');
	if (ft_strcmp(split[0], "NO") == 0 && ++flag)
		cub->n_p = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "SO") == 0 && ++flag)
		cub->s_p = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "WE" ) == 0 && ++flag)
		cub->w_p = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "EA") == 0 && ++flag)
		cub->e_p = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "C") == 0 && ++flag)
		cub->ceiling_color = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strcmp(split[0], "F") == 0 && ++flag)
		cub->floor_color = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	ft_free_m(split);
	if (flag)
		return (0);
	else
		return (1);
}

static int	check_line(t_cub *cub, char *line, int fd)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		return (0);
	}
	if (get_element(cub, line) == 0)
	{
		free(line);
		return (0);
	}
	if (get_map(cub, line, fd) == 0)
		return (0);
	return (1);
}

static	void	list_to_arr(t_cub *cub)
{
	t_map	*ptr;
	int		i;

	cub->map = malloc(sizeof (char *) * ((count_list(cub->map_list)) + 1));
	cub->line_len = malloc(sizeof (int) * (count_list(cub->map_list)));
	ptr = cub->map_list;
	i = 0;
	while (ptr)
	{
		cub->map[i] = ft_strdup(ptr->line);
		cub->line_len[i] = ft_strlen(ptr->line);
		ptr = ptr->next;
		i++;
	}
	cub->map[i] = NULL;
}

int	parse(t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(cub->path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(cub, line, fd))
			return (1);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	list_to_arr(cub);
	return (0);
}
