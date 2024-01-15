/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:45:11 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	if (nb > 9)
	{
		if (ft_putunbr(nb / 10) == -1)
			return (-1);
		if (ft_putchar(nb % 10 + 48) == -1)
			return (-1);
	}
	else
		if (ft_putchar(nb + 48) == -1)
			return (-1);
	return (0);
}
