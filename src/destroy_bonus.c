/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:44:54 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/13 23:44:54 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	destroy_hero(t_data *data)
{
	mlx_destroy_image(data->ptr, data->hero.u1);
	mlx_destroy_image(data->ptr, data->hero.u2);
	mlx_destroy_image(data->ptr, data->hero.d1);
	mlx_destroy_image(data->ptr, data->hero.d2);
	mlx_destroy_image(data->ptr, data->hero.l1);
	mlx_destroy_image(data->ptr, data->hero.l2);
	mlx_destroy_image(data->ptr, data->hero.r1);
	mlx_destroy_image(data->ptr, data->hero.r2);
}

void	destroy_cliff(t_data *data)
{
	mlx_destroy_image(data->ptr, data->clff.t);
	mlx_destroy_image(data->ptr, data->clff.b);
	mlx_destroy_image(data->ptr, data->clff.l);
	mlx_destroy_image(data->ptr, data->clff.r);
	mlx_destroy_image(data->ptr, data->clff.tl);
	mlx_destroy_image(data->ptr, data->clff.tr);
	mlx_destroy_image(data->ptr, data->clff.bl);
	mlx_destroy_image(data->ptr, data->clff.br);
}

void	destroy_patrol(t_data *data)
{
	mlx_destroy_image(data->ptr, data->ptrl.u1);
	mlx_destroy_image(data->ptr, data->ptrl.u2);
	mlx_destroy_image(data->ptr, data->ptrl.d1);
	mlx_destroy_image(data->ptr, data->ptrl.d2);
	mlx_destroy_image(data->ptr, data->ptrl.l1);
	mlx_destroy_image(data->ptr, data->ptrl.l2);
	mlx_destroy_image(data->ptr, data->ptrl.r1);
	mlx_destroy_image(data->ptr, data->ptrl.r2);
}
