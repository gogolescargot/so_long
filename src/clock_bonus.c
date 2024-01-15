/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:28:20 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/11 11:28:20 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	update_patrol(t_data *data, ssize_t i, ssize_t j)
{
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->empt.ptr, CELL * j, CELL * i);
	if (data->map.map[i][j] == 'U')
		update_patrol_up(data, i, j);
	else if (data->map.map[i][j] == 'D')
		update_patrol_down(data, i, j);
	else if (data->map.map[i][j] == 'L')
		update_patrol_left(data, i, j);
	else if (data->map.map[i][j] == 'R')
		update_patrol_right(data, i, j);
}

void	updated_patrol(t_data *data)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (data->map.map[++i])
	{
		while (data->map.map[i][++j] && data->map.map[i][j] != '\n')
		{
			if (ft_strchr("udlr", data->map.map[i][j]))
				data->map.map[i][j] -= 32;
		}
		j = -1;
	}
}

void	update(t_data *data)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	draw_hero(data);
	while (data->map.map[++i])
	{
		while (data->map.map[i][++j] && data->map.map[i][j] != '\n')
		{
			if (data->map.map[i][j] == 'E')
				draw_exit(data, i, j);
			else if (data->map.map[i][j] == 'C')
				draw_collectible(data, i, j);
			else if (ft_strchr("UDLR", data->map.map[i][j]))
				update_patrol(data, i, j);
		}
		j = -1;
	}
	updated_patrol(data);
}

int	clock(t_data *data)
{
	if (data->tick++ > 100000)
	{
		update(data);
		data->tick = 0;
	}
	return (0);
}
