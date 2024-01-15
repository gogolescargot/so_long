/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:40:42 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/11 17:40:25 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	e;
	size_t	i;

	e = ft_strlen(dst);
	i = 0;
	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	while (i < size - e - 1 && src[i])
	{
		dst[e + i] = src[i];
		i++;
	}
	dst[e + i] = '\0';
	return (e + ft_strlen(src));
}
