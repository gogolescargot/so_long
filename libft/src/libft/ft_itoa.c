/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:06:26 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/09 14:20:40 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_numbersize(int nb)
{
	size_t	i;
	size_t	unb;

	i = 1;
	if (nb < 0)
	{
		i++;
		unb = (size_t)nb * -1;
	}
	else
		unb = (size_t)nb;
	while (unb >= 10)
	{
		i++;
		unb /= 10;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*strnumber;
	size_t	unb;
	size_t	i;

	strnumber = malloc((ft_numbersize(nb) + 1) * sizeof(char));
	if (!strnumber)
		return (NULL);
	if (nb == 0)
		strnumber[0] = '0';
	if (nb < 0)
	{
		strnumber[0] = '-';
		unb = (size_t)nb * -1;
	}
	else
		unb = (size_t)nb;
	i = ft_numbersize(nb);
	strnumber[i--] = 0;
	while (unb != 0)
	{
		strnumber[i] = unb % 10 + '0';
		unb /= 10;
		i--;
	}
	return (strnumber);
}
