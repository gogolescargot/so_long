/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countptrnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:19:40 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:45:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t	ft_countptrnbr(void *p)
{
	size_t	i;

	i = 2;
	if (!p)
		return (5);
	while ((size_t)p > 0)
	{
		p = (void *)((size_t)p / 16);
		i++;
	}
	return (i);
}
