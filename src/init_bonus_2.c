/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:38:35 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/13 23:38:35 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	init_hero(t_data *data)
{
	data->hero.u1 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile000.xpm", &data->hero.width, &data->hero.height);
	data->hero.u2 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile001.xpm", &data->hero.width, &data->hero.height);
	data->hero.d1 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile005.xpm", &data->hero.width, &data->hero.height);
	data->hero.d2 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile006.xpm", &data->hero.width, &data->hero.height);
	data->hero.l1 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile010.xpm", &data->hero.width, &data->hero.height);
	data->hero.l2 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile011.xpm", &data->hero.width, &data->hero.height);
	data->hero.r1 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile015.xpm", &data->hero.width, &data->hero.height);
	data->hero.r2 = mlx_xpm_file_to_image(data->ptr,
			"asset/player/tile016.xpm", &data->hero.width, &data->hero.height);
	data->hero.pos_x = find_posx_hero(data->map) * CELL;
	data->hero.pos_y = find_posy_hero(data->map) * CELL;
	data->hero.move = 0;
	data->hero.state = 1;
}

void	init_patrol(t_data *data)
{
	data->ptrl.d1 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile000.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.d2 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile001.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.u1 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile006.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.u2 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile007.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.r1 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile012.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.r2 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile013.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.l1 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile018.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.l2 = mlx_xpm_file_to_image(data->ptr,
			"asset/patrol/tile019.xpm", &data->ptrl.width, &data->ptrl.height);
	data->ptrl.state = 1;
}

void	init_cliff(t_data *data)
{
	data->clff.t = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile016.xpm", &data->clff.width, &data->clff.height);
	data->clff.b = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile026.xpm", &data->clff.width, &data->clff.height);
	data->clff.l = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile020.xpm", &data->clff.width, &data->clff.height);
	data->clff.r = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile022.xpm", &data->clff.width, &data->clff.height);
	data->clff.tl = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile015.xpm", &data->clff.width, &data->clff.height);
	data->clff.tr = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile017.xpm", &data->clff.width, &data->clff.height);
	data->clff.bl = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile025.xpm", &data->clff.width, &data->clff.height);
	data->clff.br = mlx_xpm_file_to_image(data->ptr,
			"asset/cliff/tile027.xpm", &data->clff.width, &data->clff.height);
}

void	init_asset(t_data *data)
{
	data->bord.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/border.xpm", &data->bord.width, &data->bord.height);
	data->coll.i1 = mlx_xpm_file_to_image(data->ptr,
			"asset/collectible/tile009.xpm",
			&data->coll.width, &data->coll.height);
	data->coll.i2 = mlx_xpm_file_to_image(data->ptr,
			"asset/collectible/tile010.xpm",
			&data->coll.width, &data->coll.height);
	data->exit.i1 = mlx_xpm_file_to_image(data->ptr,
			"asset/exit/tile012.xpm", &data->exit.width, &data->exit.height);
	data->exit.i2 = mlx_xpm_file_to_image(data->ptr,
			"asset/exit/tile013.xpm", &data->exit.width, &data->exit.height);
	data->empt.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/empt.xpm", &data->empt.width, &data->empt.height);
	data->ovrl.ptr = mlx_xpm_file_to_image(data->ptr,
			"asset/overlay.xpm", &data->ovrl.width, &data->ovrl.height);
}
