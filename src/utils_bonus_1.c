/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:12:31 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 20:28:14 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

char	*get_cell(int keycode, t_data *data)
{
	if (keycode == 97)
		return (&data->map.map
			[data->hero.pos_y / CELL][(data->hero.pos_x - CELL) / CELL]);
	if (keycode == 119)
		return (&data->map.map
			[(data->hero.pos_y - CELL) / CELL][data->hero.pos_x / CELL]);
	if (keycode == 100)
		return (&data->map.map
			[data->hero.pos_y / CELL][(data->hero.pos_x + CELL) / CELL]);
	if (keycode == 115)
		return (&data->map.map
			[(data->hero.pos_y + CELL) / CELL][data->hero.pos_x / CELL]);
	return (0);
}

void	update_hero(t_data *data, int keycode)
{
	if (keycode == 97)
	{
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->hero.r1, data->hero.pos_x, data->hero.pos_y);
		data->hero.state = 4;
	}
	else if (keycode == 119)
	{
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->hero.d1, data->hero.pos_x, data->hero.pos_y);
		data->hero.state = 2;
	}
	else if (keycode == 100)
	{
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->hero.l1, data->hero.pos_x, data->hero.pos_y);
		data->hero.state = 3;
	}
	else if (keycode == 115)
	{
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->hero.u1, data->hero.pos_x, data->hero.pos_y);
		data->hero.state = 1;
	}
}

void	*draw_map_cliff(t_data data, ssize_t i, ssize_t j)
{
	void	*temp;

	if (i == 0 && j != 0 && j != data.map.width - 1)
		temp = data.clff.t;
	else if (i == data.map.height - 1 && j != 0 && j != data.map.width - 1)
		temp = data.clff.b;
	else if (j == 0 && i != 0 && i != data.map.height - 1)
		temp = data.clff.l;
	else if (j == data.map.width - 1 && i != 0 && i != data.map.height - 1)
		temp = data.clff.r;
	else if (i == 0 && j == 0)
		temp = data.clff.tl;
	else if (i == 0 && j == data.map.width - 1)
		temp = data.clff.tr;
	else if (i == data.map.height - 1 && j == 0)
		temp = data.clff.bl;
	else if (i == data.map.height - 1 && j == data.map.width - 1)
		temp = data.clff.br;
	else
		return (NULL);
	return (temp);
}

void	draw_map_utils(t_data data, ssize_t i, ssize_t j)
{
	void	*temp;

	if (data.map.map[i][j] == '1' && !draw_map_cliff(data, i, j))
		temp = data.bord.ptr;
	else if (data.map.map[i][j] == '1')
		temp = draw_map_cliff(data, i, j);
	else if (data.map.map[i][j] == 'E')
		temp = data.exit.i1;
	else if (data.map.map[i][j] == 'C')
		temp = data.coll.i1;
	else if (data.map.map[i][j] == 'P')
		temp = data.hero.u1;
	else if (data.map.map[i][j] == '0')
		temp = data.empt.ptr;
	else if (data.map.map[i][j] == 'L')
		temp = data.ptrl.l1;
	else if (data.map.map[i][j] == 'R')
		temp = data.ptrl.r1;
	else if (data.map.map[i][j] == 'U')
		temp = data.ptrl.u1;
	else if (data.map.map[i][j] == 'D')
		temp = data.ptrl.d1;
	mlx_put_image_to_window(data.ptr, data.win.ptr,
		temp, CELL * j, CELL * i);
}
