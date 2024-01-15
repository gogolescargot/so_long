/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:47:51 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/13 23:47:51 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	update_patrol_up(t_data *data, ssize_t i, ssize_t j)
{
	if (i - 1 == data->hero.pos_y / CELL && j == data->hero.pos_x / CELL)
		end(data, false);
	else if (ft_strchr("1CEUDLRudlr", data->map.map[i - 1][j]))
	{
		data->map.map[i][j] = 'd';
		draw_patrol(data, i, j, 2);
	}
	else
	{
		data->map.map[i - 1][j] = 'u';
		data->map.map[i][j] = '0';
		draw_patrol(data, i - 1, j, 1);
	}
}

void	update_patrol_down(t_data *data, ssize_t i, ssize_t j)
{
	if (i + 1 == data->hero.pos_y / CELL && j == data->hero.pos_x / CELL)
		end(data, false);
	else if (ft_strchr("1CEUDLRudlr", data->map.map[i + 1][j]))
	{
		data->map.map[i][j] = 'u';
		draw_patrol(data, i, j, 1);
	}
	else
	{
		data->map.map[i + 1][j] = 'd';
		data->map.map[i][j] = '0';
		draw_patrol(data, i + 1, j, 2);
	}
}

void	update_patrol_left(t_data *data, ssize_t i, ssize_t j)
{
	if (i == data->hero.pos_y / CELL && j - 1 == data->hero.pos_x / CELL)
		end(data, false);
	else if (ft_strchr("1CEUDLRudlr", data->map.map[i][j - 1]))
	{
		data->map.map[i][j] = 'r';
		draw_patrol(data, i, j, 4);
	}
	else
	{
		data->map.map[i][j - 1] = 'l';
		data->map.map[i][j] = '0';
		draw_patrol(data, i, j - 1, 3);
	}
}

void	update_patrol_right(t_data *data, ssize_t i, ssize_t j)
{
	if (i == data->hero.pos_y / CELL && j + 1 == data->hero.pos_x / CELL)
		end(data, false);
	else if (ft_strchr("1CEUDLRudlr", data->map.map[i][j + 1]))
	{
		data->map.map[i][j] = 'l';
		draw_patrol(data, i, j, 3);
	}
	else
	{
		data->map.map[i][j + 1] = 'r';
		data->map.map[i][j] = '0';
		draw_patrol(data, i, j + 1, 4);
	}
}
