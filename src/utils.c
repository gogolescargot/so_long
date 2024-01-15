/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:50:15 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 20:27:54 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

bool	check_end(t_data *data)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (data->map.map[++i])
	{
		while (data->map.map[i][++j] && data->map.map[i][j] != '\n')
		{
			if (data->map.map[i][j] == 'C')
				return (false);
		}
		j = -1;
	}
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->ovrl.ptr, 0, 0);
	mlx_string_put(data->ptr, data->win.ptr,
		5, 12, 0xFFFFFF, "You Win !");
	return (true);
}

int	check_move(int keycode, t_data *data)
{
	char	*cell;

	cell = get_cell(keycode, data);
	if (!cell || data->end)
		return (1);
	if (*cell == 'C')
		return (*cell = '0', 0);
	if (ft_strchr("E", *cell) && check_end(data))
		return (2);
	if (ft_strchr("1", *cell) || ft_strchr("E", *cell))
		return (1);
	return (0);
}

void	move(t_data *data, int keycode)
{
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->empt.ptr, data->hero.pos_x, data->hero.pos_y);
	if (keycode == 97)
		data->hero.pos_x -= CELL;
	else if (keycode == 119)
		data->hero.pos_y -= CELL;
	else if (keycode == 100)
		data->hero.pos_x += CELL;
	else if (keycode == 115)
		data->hero.pos_y += CELL;
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->hero.ptr, data->hero.pos_x, data->hero.pos_y);
	data->hero.move += 1;
	ft_printf("Total movements : %d\n", data->hero.move);
}

void	draw_map_utils(t_data data, ssize_t i, ssize_t j)
{
	if (data.map.map[i][j] == '1')
		mlx_put_image_to_window(data.ptr, data.win.ptr,
			data.bord.ptr, CELL * j, CELL * i);
	else if (data.map.map[i][j] == 'E')
		mlx_put_image_to_window(data.ptr, data.win.ptr,
			data.exit.ptr, CELL * j, CELL * i);
	else if (data.map.map[i][j] == 'C')
		mlx_put_image_to_window(data.ptr, data.win.ptr,
			data.coll.ptr, CELL * j, CELL * i);
	else if (data.map.map[i][j] == 'P')
		mlx_put_image_to_window(data.ptr, data.win.ptr,
			data.hero.ptr, CELL * j, CELL * i);
	else if (data.map.map[i][j] == '0')
		mlx_put_image_to_window(data.ptr, data.win.ptr,
			data.empt.ptr, CELL * j, CELL * i);
}
