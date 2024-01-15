/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:44:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/14 00:44:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	draw_patrol(t_data *data, ssize_t i, ssize_t j, int direction)
{
	void	*temp;

	if (direction == 1 && data->ptrl.state == 1)
		temp = data->ptrl.u1;
	else if (direction == 2 && data->ptrl.state == 1)
		temp = data->ptrl.d1;
	else if (direction == 3 && data->ptrl.state == 1)
		temp = data->ptrl.l1;
	else if (direction == 4 && data->ptrl.state == 1)
		temp = data->ptrl.r1;
	else if (direction == 1 && data->ptrl.state == -1)
		temp = data->ptrl.u1;
	else if (direction == 2 && data->ptrl.state == -1)
		temp = data->ptrl.d1;
	else if (direction == 3 && data->ptrl.state == -1)
		temp = data->ptrl.l1;
	else if (direction == 4 && data->ptrl.state == -1)
		temp = data->ptrl.r1;
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		temp, CELL * j, CELL * i);
}

void	draw_hero(t_data *data)
{
	void	*temp;

	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->empt.ptr, data->hero.pos_x, data->hero.pos_y);
	if (data->hero.state == 1)
		temp = data->hero.u2;
	else if (data->hero.state == -1)
		temp = data->hero.u1;
	else if (data->hero.state == 2)
		temp = data->hero.d2;
	else if (data->hero.state == -2)
		temp = data->hero.d1;
	else if (data->hero.state == 3)
		temp = data->hero.l2;
	else if (data->hero.state == -3)
		temp = data->hero.l1;
	else if (data->hero.state == 4)
		temp = data->hero.r2;
	else if (data->hero.state == -4)
		temp = data->hero.r1;
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		temp, data->hero.pos_x, data->hero.pos_y);
	data->hero.state *= -1;
}

void	draw_collectible(t_data *data, ssize_t i, ssize_t j)
{
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->empt.ptr, CELL * j, CELL * i);
	if (data->coll.state == 1)
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->coll.i2, CELL * j, CELL * i);
	else if (data->coll.state == -1)
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->coll.i1, CELL * j, CELL * i);
}

void	draw_exit(t_data *data, ssize_t i, ssize_t j)
{
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->empt.ptr, CELL * j, CELL * i);
	if (data->exit.state == 1)
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->exit.i2, CELL * j, CELL * i);
	else if (data->exit.state == -1)
		mlx_put_image_to_window(data->ptr, data->win.ptr,
			data->exit.i1, CELL * j, CELL * i);
}

void	draw_map(t_data data)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (data.map.map[++i])
	{
		while (data.map.map[i][++j] && data.map.map[i][j] != '\n')
			draw_map_utils(data, i, j);
		j = -1;
	}
}
