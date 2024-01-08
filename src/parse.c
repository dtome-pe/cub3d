/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:11 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/08 13:32:11 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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

static void	element_aux(char **path, char **split, int *flag, int type)
{
	printf("type = %d, %s\n", type, *path);
	if (!(*path))
	{	
		(*flag)--;
		*path = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
		return ;
	}
	*flag = 2;
	//printf("dup\n");
}

static int	get_element(t_cub *cub, char *line)
{
	char	**split;
	int		flag;
	//int		rep;

	flag = 1;
	//rep = 0;
	split = ft_split(line, ' ');
	if (ft_strcmp(split[0], "NO") == 0)
		element_aux(&cub->n_p, split, &flag, 0);
	else if (ft_strcmp(split[0], "SO") == 0)
		element_aux(&cub->s_p, split, &flag, 1);
	else if (ft_strcmp(split[0], "WE") == 0)
		element_aux(&cub->w_p, split, &flag, 2);
	else if (ft_strcmp(split[0], "EA") == 0)
		element_aux(&cub->e_p, split, &flag, 3);
	else if (ft_strcmp(split[0], "C") == 0)
		element_aux(&cub->ceiling_color, split, &flag, 4);
	else if (ft_strcmp(split[0], "F") == 0)
		element_aux(&cub->floor_color, split, &flag, 5);
	ft_free_m(split);
	//printf("flag es %d\n", flag);
	return (flag);
}

static int	check_line(t_cub *cub, char *line, int fd)
{
	int	ret;
	if (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		return (0);
	}
	ret = get_element(cub, line);
	if (!ret)
	{
		free(line);
		return (0);
	}
	if (ret == 2)
	{
		printf("duplicado\n");
		free(line);
		return (1);
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
