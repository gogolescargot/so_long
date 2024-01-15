/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:12:34 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/14 01:04:25 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	destroy(t_data *data)
{
	destroy_hero(data);
	destroy_cliff(data);
	destroy_patrol(data);
	mlx_destroy_image(data->ptr, data->bord.ptr);
	mlx_destroy_image(data->ptr, data->coll.i1);
	mlx_destroy_image(data->ptr, data->coll.i2);
	mlx_destroy_image(data->ptr, data->exit.i1);
	mlx_destroy_image(data->ptr, data->exit.i2);
	mlx_destroy_image(data->ptr, data->empt.ptr);
	mlx_destroy_image(data->ptr, data->ovrl.ptr);
	mlx_destroy_window(data->ptr, data->win.ptr);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free_map(data->map);
	exit(0);
}

int	keypress(int keycode, t_data *data)
{
	int	state;

	if (keycode == 65307)
		destroy(data);
	state = check_move(keycode, data);
	if (state == 1)
		return (0);
	move(data, keycode);
	if (state == 2)
		end(data, true);
	else if (state == 3)
		end(data, false);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (errno = 1, perror("Bad number of parameters"), 1);
	if (!check_map_extension(argv[1], ".ber"))
		return (ft_putstr_fd("Error\nWrong file extension", 2), 1);
	if (!init_data(&data, argv[1]))
		return (1);
	draw_map(data);
	mlx_hook(data.win.ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win.ptr,
		DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_loop_hook(data.ptr, &clock, &data);
	mlx_loop(data.ptr);
	return (0);
}
