/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:37:14 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/10 14:54:30 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		m;
	long	r;

	i = 0;
	r = 0;
	m = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
	{
		m = -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		r = nptr[i++] - 48 + (r * 10);
		if (r < 0)
			return (-1 * (m == 1));
	}
	return (r * m);
}
