/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:23:51 by jgravalo          #+#    #+#             */
/*   Updated: 2024/01/16 11:31:57 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	count_list(t_map *map)
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

size_t	ft_padcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	c;

	c = 0;
	i = 0;
	while (src[c] != '\0')
		++c;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			++i;
		}
		while (i < (dstsize - 1))
		{
			dst[i] = '\0';
			i++;
		}
		dst[i] = '\0';
	}
	return (c);
}

int	pos_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}
