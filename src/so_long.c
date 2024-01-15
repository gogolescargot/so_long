/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:12:19 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/06 14:37:26 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	destroy(t_data *data)
{
	mlx_destroy_image(data->ptr, data->hero.ptr);
	mlx_destroy_image(data->ptr, data->bord.ptr);
	mlx_destroy_image(data->ptr, data->coll.ptr);
	mlx_destroy_image(data->ptr, data->exit.ptr);
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
	if (!data->end)
		move(data, keycode);
	if (state == 2)
		data->end = true;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (errno = 1, perror("Bad number of parameters"), 1);
	if (!check_map_extension(argv[1], ".ber"))
		return (ft_putstr_fd("Error\nWrong file extension\n", 2), 1);
	if (!init_data(&data, argv[1]))
		return (1);
	draw_map(data);
	mlx_hook(data.win.ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win.ptr,
		DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_loop(data.ptr);
	return (0);
}
