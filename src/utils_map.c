/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:01 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/14 18:56:02 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

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
