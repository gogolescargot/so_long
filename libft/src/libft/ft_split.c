/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:53:45 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/11 18:33:07 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	ft_freearray(char **array, size_t size)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*ft_strndup(char const *src, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	if (!s)
		return (words);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (words);
		while (s[i] && s[i] != c)
			i++;
		words++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**split_str;

	i = 0;
	j = 0;
	k = 0;
	split_str = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split_str || !s)
		return (ft_freearray(split_str, 0), NULL);
	while (i < ft_strlen(s))
	{
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
		{
			split_str[k] = ft_strndup(&s[i], j);
			if (!split_str[k++])
				return (ft_freearray(split_str, k - 1), NULL);
		}
		i += j + 1;
		j = 0;
	}
	return (split_str[k] = 0, split_str);
}
