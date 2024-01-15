/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:25:44 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 20:10:36 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	exit_reachable(char **map, ssize_t x, ssize_t y)
{
	if (map[x][y] == 'E')
		return (true);
	if (ft_strchr("0CP", map[x][y]))
	{
		map[x][y] = 'v';
		if (exit_reachable(map, x + 1, y)
			|| exit_reachable(map, x - 1, y)
			|| exit_reachable(map, x, y + 1)
			|| exit_reachable(map, x, y - 1))
			return (true);
	}
	return (false);
}

bool	collectible_reachable(char **map, ssize_t x, ssize_t y)
{
	if (map[x][y] == 'v')
		return (true);
	if (ft_strchr("0CP", map[x][y]))
	{
		map[x][y] = 'V';
		if (collectible_reachable(map, x + 1, y)
			|| collectible_reachable(map, x - 1, y)
			|| collectible_reachable(map, x, y - 1))
			return (true);
	}
	return (false);
}

bool	all_collectibles_reachable(char **map, ssize_t i, ssize_t j)
{
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'C' && !collectible_reachable(map, i, j))
				return (false);
		}
		j = -1;
	}
	return (true);
}

bool	check_map_validate(char *str_map)
{
	ssize_t	i;
	ssize_t	j;
	char	**temp_map;

	i = -1;
	j = -1;
	temp_map = ft_split(str_map, '\n');
	if (!temp_map)
		return (false);
	while (temp_map[++i])
	{
		while (temp_map[i][++j])
		{
			if (ft_strchr("P", temp_map[i][j])
				&& exit_reachable(temp_map, i, j)
				&& all_collectibles_reachable(temp_map, i, j))
				return (ft_arrayclear(temp_map), true);
		}
		j = -1;
	}
	return (ft_arrayclear(temp_map), false);
}

bool	check_map_extension(char *file, char *extension)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		while (file[i + j] && extension[j] && file[i + j] == extension[j])
		{
			j++;
			if (j == ft_strlen(extension) && file[i + j] == extension[j])
				return (true);
		}
		i++;
		j = 0;
	}
	return (false);
}
