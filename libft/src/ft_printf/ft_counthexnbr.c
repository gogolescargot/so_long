/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counthexnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:42:40 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:45:45 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t	ft_counthexnbr(unsigned int nb)
{
	size_t	i;

	i = 1;
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	return (i);
}