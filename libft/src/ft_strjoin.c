/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:34:00 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/27 09:45:32 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 || ft_strcmp("", s1) == 0)
		return (ft_strdup(s2));
	if (!s2 || ft_strcmp("", s2) == 0)
		return (ft_strdup(s1));
	new = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	check_malloc_error(new);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			new[i] = s1[i];
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (new);
}
