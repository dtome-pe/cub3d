/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:49:33 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/09 16:51:26 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_charcmp(char str, char *charset)
{
	int	i;

	i = 0;
	while (*charset)
	{
		if (str == *charset)
			return (0);
		charset++;
	}
	return (1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size, int *pos)
{
	unsigned int	i;
	unsigned int	c;

	c = 0;
	i = 0;
	while (src[c] != '\0')
		++c;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[*pos];
			++i;
			(*pos)++;
		}
		dest[i] = '\0';
	}
	return (c);
}

int	words(char *str, char *charset)
{
	int	chars;
	int	c;

	chars = 0;
	c = 0;
	while (*str != '\0')
	{
		if (ft_charcmp(*str, charset) == 0 && chars > 0)
		{
			c++;
			chars = 0;
		}
		if (ft_charcmp(*str, charset) == 1)
			chars++;
		str++;
	}
	if (chars > 0)
		c++;
	return (c);
}

int	ft_strlen_charset(char *str, char *charset, int *i)
{
	int	c;
	int	j;

	j = 0;
	c = 0;
	while (str[*i] != '\0')
	{
		while (charset[j] != '\0')
		{
			if (ft_charcmp(str[*i], charset) == 0)
				return (c);
			j++;
		}
		c++;
		j = 0;
		(*i)++;
	}
	return (c);
}

char	**ft_splitchr(char *str, char *charset)
{
	int		pos;
	int		cpy;
	int		n;
	char	**split;
	int		len;

	n = 0;
	pos = 0;
	len = 0;
	cpy = 0;
	split = (char **) malloc(sizeof (char *) * (words(str, charset) + 1));
	while (n < words(str, charset))
	{
		while (ft_charcmp(str[pos], charset) == 0)
		{
			pos++;
			cpy++;
		}
		len = ft_strlen_charset(str, charset, &pos);
		split[n] = (char *) malloc(sizeof (char) * len + 1);
		ft_strlcpy(split[n], str, len + 1, &cpy);
		n++;
	}
	split[n] = NULL;
	return (split);
}
