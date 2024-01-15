/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlowernbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:44:19 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_puthexlowernbr(unsigned int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
	{
		if (ft_puthexlowernbr(nb / 16) == -1)
			return (-1);
		if (ft_putchar(base[nb % 16]) == -1)
			return (-1);
	}
	else
		if (ft_putchar(base[nb]) == -1)
			return (-1);
	return (0);
}
