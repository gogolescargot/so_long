/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:24:02 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:54 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_percent_put(const char *s, size_t i, size_t p)
{
	if (s[i] == 'c' && ft_putchar((char)p) != -1)
		return (1);
	else if (s[i] == 's' && ft_putstr((char *)p) != -1)
		return (1);
	else if (s[i] == 'p' && ft_putptr((void *)p, 0) != -1)
		return (1);
	else if (((s[i] == 'd' || s[i] == 'i') && ft_putnbr((int)p) != -1))
		return (1);
	else if (s[i] == 'u' && ft_putunbr(p) != -1)
		return (1);
	else if (s[i] == 'x' && ft_puthexlowernbr(p) != -1)
		return (1);
	else if (s[i] == 'X' && ft_puthexuppernbr(p) != -1)
		return (1);
	else if (s[i] == '%' && ft_putchar('%') != -1)
		return (1);
	else if (s[i] && ft_putchar('%') != -1 && ft_putchar(s[i]) != -1)
		return (1);
	return (-1);
}
