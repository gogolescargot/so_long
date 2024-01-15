/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:55:06 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	size_t	cprint;
	size_t	i;
	size_t	temp;
	va_list	argptr;

	if (!s)
		return (-1);
	i = -1;
	cprint = 0;
	va_start(argptr, s);
	while (++i < ft_strlen(s))
	{
		if (s[i] == '%' && ++i)
		{
			if (ft_strchr("cspdiuxX", s[i]))
				temp = va_arg(argptr, size_t);
			if (ft_percent_put(s, i, temp) == -1)
				return (va_end(argptr), -1);
			cprint += ft_percent_count(s, i, temp);
		}
		else
			if (++cprint && ft_putchar(s[i]) == -1)
				return (va_end(argptr), -1);
	}
	return (va_end(argptr), cprint);
}
