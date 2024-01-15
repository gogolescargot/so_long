/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:45:35 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/21 11:45:35 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t	ft_percent_count(const char *s, size_t i, size_t p)
{
	if (s[i] == 'c')
		return (1);
	else if (s[i] == 's')
		return (ft_countstr((char *)p));
	else if (s[i] == 'p')
		return (ft_countptrnbr((void *)p));
	else if ((s[i] == 'd' || s[i] == 'i'))
		return (ft_countdecnbr((int)p));
	else if (s[i] == 'u')
		return (ft_countdecunbr(p));
	else if (s[i] == 'x')
		return (ft_counthexnbr(p));
	else if (s[i] == 'X')
		return (ft_counthexnbr(p));
	else if (s[i] == '%')
		return (1);
	return (2);
}
