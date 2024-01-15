/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:25:50 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 15:25:52 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_map(t_map	map)
{
	if (!map.str_map)
		return (error_map(map, 0), false);
	if (!check_map_shape(map))
		return (error_map(map, 1), false);
	if (!check_map_borders(map))
		return (error_map(map, 2), false);
	if (!check_map_entities(map))
		return (error_map(map, 3), false);
	if (!check_map_allowed(map))
		return (error_map(map, 4), false);
	if (!check_map_validate(map.str_map))
		return (error_map(map, 5), false);
	return (true);
}

bool	check_map_shape(t_map map)
{
	if (map.height < 2 || map.width < 2)
		return (false);
	return (true);
}

bool	check_map_borders(t_map map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (map.map[++i])
	{
		while (map.map[i][++j])
		{
			if ((i == 0 || i == map.height - 1) && map.map[i][j] != '1')
				return (false);
			if ((j == 0 || j == map.width - 1) && map.map[i][j] != '1')
				return (false);
		}
		j = -1;
	}
	return (true);
}

bool	check_map_entities(t_map map)
{
	ssize_t	c_coll;
	ssize_t	c_exit;
	ssize_t	c_play;
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	c_coll = 0;
	c_exit = 0;
	c_play = 0;
	while (map.map[++i])
	{
		while (map.map[i][++j])
		{
			if (map.map[i][j] == 'E')
				c_exit++;
			if (map.map[i][j] == 'C')
				c_coll++;
			if (map.map[i][j] == 'P')
				c_play++;
		}
		j = -1;
	}
	return (c_coll >= 1 && c_exit == 1 && c_play == 1);
}

bool	check_map_allowed(t_map map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (map.map[++i])
	{
		while (map.map[i][++j])
		{
			if (!ft_strchr("01CEPUDLR", map.map[i][j]))
				return (false);
		}
		j = -1;
	}
	return (true);
}
