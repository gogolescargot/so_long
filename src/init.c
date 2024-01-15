/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:48:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/14 17:22:26 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_hero(t_data *data)
{
	data->hero.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile000.xpm", &data->hero.width, &data->hero.height);
	data->hero.pos_x = find_posx_hero(data->map) * CELL;
	data->hero.pos_y = find_posy_hero(data->map) * CELL;
	data->hero.move = 0;
}

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
	init_hero(data);
	data->bord.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/border.xpm", &data->bord.width, &data->bord.height);
	data->coll.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/collectible/tile009.xpm",
			&data->coll.width, &data->coll.height);
	data->exit.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/exit/tile012.xpm", &data->exit.width, &data->exit.height);
	data->empt.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/empt.xpm", &data->empt.width, &data->empt.height);
	data->ovrl.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/overlay.xpm", &data->ovrl.width, &data->ovrl.height);
	return (true);
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
