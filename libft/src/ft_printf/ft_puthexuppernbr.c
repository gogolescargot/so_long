/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexuppernbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:59:52 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_puthexuppernbr(unsigned int nb)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		if (ft_puthexuppernbr(nb / 16) == -1)
			return (-1);
		if (ft_putchar(base[nb % 16]) == -1)
			return (-1);
	}
	else
		if (ft_putchar(base [nb]) == -1)
			return (-1);
	return (0);
}
