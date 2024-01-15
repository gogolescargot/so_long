/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:55:18 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/09 14:21:36 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*sf;

	i = 0;
	sf = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!sf)
		return (NULL);
	while (s[i])
	{
		sf[i] = (*f)(i, s[i]);
		i++;
	}
	sf[i] = 0;
	return (sf);
}
