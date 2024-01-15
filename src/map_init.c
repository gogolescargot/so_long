/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:25:34 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 19:37:20 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

ssize_t	get_map_width(char *str_map)
{
	ssize_t	i;

	i = 0;
	while (str_map[i] && str_map[i] != '\n')
		i++;
	if (!str_map[i])
		return (-1);
	return (i);
}

ssize_t	get_map_height(char *str_map, ssize_t width)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	height;

	i = width;
	height = 1;
	j = 0;
	while (str_map[++i])
	{
		if ((str_map[i] == '\n') && j != width)
			return (-1);
		else if ((str_map[i] == '\n') && j == width)
		{
			j = -1;
			height++;
		}
		j++;
	}
	if (j == width)
		return (height + 1);
	return (-1);
}

t_map	init_map(char *file)
{
	t_map	map;

	map.str_map = get_str_map(file);
	if (!map.str_map)
		return (map);
	map.width = get_map_width(map.str_map);
	map.height = get_map_height(map.str_map, map.width);
	map.map = ft_split(map.str_map, '\n');
	if (!map.map)
		return (map);
	return (map);
}

char	*get_str_map(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	fd = open(file, O_RDONLY);
	map = "";
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map;
		map = ft_strjoin(map, line);
		if (temp[0])
			free(temp);
		free(line);
	}
	close(fd);
	if (!map[0])
		return (NULL);
	return (map);
}
