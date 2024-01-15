/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:56:17 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putptr(void *p, size_t i)
{
	char	*base;

	base = "0123456789abcdef";
	if (p == NULL && i == 0)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (0);
	}
	if ((size_t)p > 0)
	{
		if (i++ == 0)
			if (ft_putstr("0x") == -1)
				return (-1);
		if (ft_putptr((void *)((size_t)p / 16), i) == -1)
			return (-1);
		if (ft_putchar(base[(size_t)p % 16]) == -1)
			return (-1);
	}
	return (0);
}
