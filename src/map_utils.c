/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:25:39 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 15:25:39 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_map map)
{
	if (map.map)
		ft_arrayclear(map.map);
	if (map.str_map)
		free(map.str_map);
}

void	error_map(t_map map, int code)
{
	if (code == 0)
		return (ft_putstr_fd("Error\nNot found\n", 2));
	else if (code == 1)
		ft_putstr_fd("Error\nIncorrect shape\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error\nIncorrect border\n", 2);
	else if (code == 3)
		ft_putstr_fd("Error\nIncorrect entity number\n", 2);
	else if (code == 4)
		ft_putstr_fd("Error\nForbidden entity\n", 2);
	else if (code == 5)
		ft_putstr_fd("Error\nNot realizable\n", 2);
	free_map(map);
}

ssize_t	find_posx_hero(t_map map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (map.map[++i])
	{
		while (map.map[i][++j] && map.map[i][j] != '\n')
		{
			if (map.map[i][j] == 'P')
				return (j);
		}
		j = -1;
	}
	return (-1);
}

ssize_t	find_posy_hero(t_map map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (map.map[++i])
	{
		while (map.map[i][++j] && map.map[i][j] != '\n')
		{
			if (map.map[i][j] == 'P')
				return (i);
		}
		j = -1;
	}
	return (-1);
}
