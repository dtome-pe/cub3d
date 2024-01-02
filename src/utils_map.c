/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:01 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/12/19 16:43:35 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_map2(char **map)
{
	int	width;
	int	height;
	int i;
	int j;
	
	width = get_length(map);
	height = get_height(map);
	for (j = 0; j < height; j++)
	{
		for (i = 0; i < width; i++)
		{
			if (map[j][i])
				printf("%c", map[j][i]);
			else
				printf(" ");
		}
		printf("\n");
	}
}

void	print_map(t_map *map)
{
	t_map	*ptr;

	ptr = map;
	ft_printf(1, "map is: \n");
	while (ptr)
	{
		ft_printf(1, "%s\n", ptr->line);
		ptr = ptr->next;
	}
}

t_map	*ft_mapnew(char *content)
{
	t_map	*node;

	node = (t_map *)malloc(sizeof (*node));
	if (!node)
		return (NULL);
	node->line = ft_substr(content, 0, ft_strlen(content) - 1);
	node->next = NULL;
	return (node);
}

void	ft_mapback(t_map **lst, t_map *new)
{
	t_map	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = ft_maplast(*lst);
	curr->next = new;
}

t_map	*ft_maplast(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_mapclear(t_map **lst)
{
	t_map	*curr;
	t_map	*next;

	if (*lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->line);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}
