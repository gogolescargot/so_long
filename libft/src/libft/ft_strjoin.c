/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:44:31 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/09 14:21:21 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*strjoin;
	size_t		i;
	size_t		e;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	e = i;
	i = 0;
	while (s2[i])
	{
		strjoin[e + i] = s2[i];
		i++;
	}
	return (strjoin[e + i] = 0, strjoin);
}
