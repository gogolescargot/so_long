/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:48:34 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/01 22:48:34 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

long	ft_findnline(const char *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (-1);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *src, size_t start, size_t end)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((end - start + 1) * sizeof(char));
	if (!dest || !src)
		return (NULL);
	while (src[start] && start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}

void	ft_clear_all_stash(char **stash)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (stash[i])
			free(stash[i]);
		stash[i] = NULL;
		i++;
	}
	return ;
}
