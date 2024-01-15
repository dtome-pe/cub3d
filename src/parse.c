/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:11 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:59 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	element_aux(char **path, char **split,
	int *flag, int color)//, int type)
{
	int		i;
	char	*tmp;

	if (!(*path))
	{
		(*flag)--;
		if (!color || (color && !split[2]))
			*path = ft_strdup(split[1]);
		else
		{
			i = 3;
			*path = ft_strjoin(split[1], split[2]);
			while (split[i])
			{
				tmp = ft_strjoin(*path, split[i]);
				*path = ft_strdup(tmp);
				free(tmp);
				i++;
			}
		}
		printf("path = <%s>\n", *path);
		return ;
	}
	*flag = 2;
}

static int	get_element(t_cub *cub, char *line)
{
	char	**split;
	int		flag;

	flag = 1;
	split = ft_splitchr(line, " \t\n");
	if (ft_strcmp(split[0], "NO") == 0)
		element_aux(&cub->n_p, split, &flag, 0);
	else if (ft_strcmp(split[0], "SO") == 0)
		element_aux(&cub->s_p, split, &flag, 0);
	else if (ft_strcmp(split[0], "WE") == 0)
		element_aux(&cub->w_p, split, &flag, 0);
	else if (ft_strcmp(split[0], "EA") == 0)
		element_aux(&cub->e_p, split, &flag, 0);
	else if (ft_strcmp(split[0], "C") == 0)
		element_aux(&cub->ceiling_color, split, &flag, 1);
	else if (ft_strcmp(split[0], "F") == 0)
		element_aux(&cub->floor_color, split, &flag, 1);
	ft_free_m(split);
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
		ft_printf(2, "duplicated element\n");
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
	//ft_printf(1, "longest es %d\n", cub->longest);
	//cub->line_len = malloc(sizeof (int) * (count_list(cub->map_list)));
	ptr = cub->map_list;
	i = 0;
	while (ptr)
	{
		//cub->map[i] = ft_strdup(ptr->line);
		cub->map[i] = malloc(cub->longest + 1);
		ft_padcpy(cub->map[i], ptr->line, cub->longest);
		//cub->line_len[i] = ft_strlen(ptr->line);
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
