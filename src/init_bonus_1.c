/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:48:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 20:24:08 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

bool	init_window(t_data *data)
{
	data->win.width = get_map_width(data->map.str_map) * CELL;
	data->win.height = get_map_height(data->map.str_map,
			data->win.width / CELL) * CELL;
	data->win.ptr = mlx_new_window(data->ptr,
			data->win.width, data->win.height, "ggalon - so_long");
	if (!data->win.ptr)
		return (false);
	return (true);
}

bool	init_data(t_data *data, char *file)
{
	data->map = init_map(file);
	if (!check_map(data->map))
		return (false);
	data->ptr = mlx_init();
	data->end = false;
	if (!data->ptr)
		return (false);
	if (!init_window(data))
		return (free(data->ptr), false);
	data->tick = 0;
	init_hero(data);
	init_patrol(data);
	init_cliff(data);
	init_asset(data);
	data->coll.state = 1;
	data->exit.state = 1;
	return (true);
}
