/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:45:05 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/28 08:45:15 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_strarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf(1, "%s\n", arr[i]);
		i++;
	}
}
