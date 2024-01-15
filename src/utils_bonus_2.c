/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:43:23 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/13 23:43:23 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	end(t_data *data, bool state)
{
	if (data->end == true)
		return ;
	data->end = true;
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->ovrl.ptr, 0, 0);
	if (state)
		mlx_string_put(data->ptr, data->win.ptr,
			5, 12, 0xFFFFFF, "You Win !");
	else
		mlx_string_put(data->ptr, data->win.ptr,
			5, 12, 0xFFFFFF, "You Lose.");
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
	end(data, true);
	return (true);
}

void	move(t_data *data, int keycode)
{
	char	*str;

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
	update_hero(data, keycode);
	data->hero.move += 1;
	if (data->end)
		return ;
	mlx_put_image_to_window(data->ptr, data->win.ptr,
		data->ovrl.ptr, 0, 0);
	str = ft_itoa(data->hero.move);
	mlx_string_put(data->ptr, data->win.ptr,
		5, 12, 0xFFFFFF, str);
	free(str);
}

int	check_move(int keycode, t_data *data)
{
	char	*cell;

	cell = get_cell(keycode, data);
	if (!cell || data->end)
		return (1);
	if (*cell == 'C')
		return (*cell = '0', 0);
	else if (ft_strchr("UDLRudlr", *cell))
		return (3);
	if (ft_strchr("E", *cell) && check_end(data))
		return (*cell = '0', 2);
	if (ft_strchr("1", *cell) || ft_strchr("E", *cell))
		return (1);
	return (0);
}

void	replace_x(char **map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'X')
				map[i][j] = 'x';
		}
		j = -1;
	}
}
