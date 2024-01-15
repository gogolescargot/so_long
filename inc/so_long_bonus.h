/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:13:07 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/10 20:25:08 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/inc/libft.h"

# define CELL 16

typedef struct s_hero
{
	void	*u1;
	void	*u2;
	void	*d1;
	void	*d2;
	void	*l1;
	void	*l2;
	void	*r1;
	void	*r2;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		move;
	int		state;
}	t_hero;

typedef struct s_bord
{
	void	*ptr;
	int		width;
	int		height;
}	t_bord;

typedef struct s_exit
{
	void	*i1;
	void	*i2;
	int		width;
	int		height;
	int		state;
}	t_exit;

typedef struct s_coll
{
	void	*i1;
	void	*i2;
	int		width;
	int		height;
	int		state;
}	t_coll;

typedef struct s_map
{
	char	**map;
	char	*str_map;
	ssize_t	width;
	ssize_t	height;
}	t_map;

typedef struct s_empt
{
	void	*ptr;
	int		width;
	int		height;
}	t_empt;

typedef struct s_ovrl
{
	void	*ptr;
	int		width;
	int		height;
}	t_ovrl;

typedef struct s_clff
{
	void	*t;
	void	*b;
	void	*l;
	void	*r;
	void	*tl;
	void	*tr;
	void	*bl;
	void	*br;
	int		width;
	int		height;
}	t_clff;

typedef struct s_ptrl
{
	void	*u1;
	void	*u2;
	void	*d1;
	void	*d2;
	void	*l1;
	void	*l2;
	void	*r1;
	void	*r2;
	int		width;
	int		height;
	int		state;
}	t_ptrl;

typedef struct s_win
{
	void	*ptr;
	ssize_t	width;
	ssize_t	height;
}	t_win;

typedef struct s_data
{
	void	*ptr;
	t_win	win;
	t_hero	hero;
	t_map	map;
	t_bord	bord;
	t_coll	coll;
	t_exit	exit;
	t_empt	empt;
	t_ovrl	ovrl;
	t_clff	clff;
	t_ptrl	ptrl;
	size_t	tick;
	bool	end;

}	t_data;

t_map	init_map(char *file);
bool	init_data(t_data *data, char *file);
bool	init_window(t_data *data);
void	init_hero(t_data *data);
void	init_asset(t_data *data);
void	init_patrol(t_data *data);
void	init_cliff(t_data *data);

char	*get_cell(int keycode, t_data *data);
int		check_move(int keycode, t_data *data);
void	move(t_data *data, int keycode);
bool	check_end(t_data *data);
void	end(t_data *data, bool state);
int		clock(t_data *data);

void	destroy_hero(t_data *data);
void	destroy_cliff(t_data *data);
void	destroy_patrol(t_data *data);

void	draw_map(t_data data);
void	draw_map_utils(t_data data, ssize_t i, ssize_t j);
void	draw_exit(t_data *data, ssize_t i, ssize_t j);
void	draw_collectible(t_data *data, ssize_t i, ssize_t j);
void	draw_hero(t_data *data);
void	draw_patrol(t_data *data, ssize_t i, ssize_t j, int direction);

void	update_hero(t_data *data, int keycode);
void	update_patrol_up(t_data *data, ssize_t i, ssize_t j);
void	update_patrol_down(t_data *data, ssize_t i, ssize_t j);
void	update_patrol_left(t_data *data, ssize_t i, ssize_t j);
void	update_patrol_right(t_data *data, ssize_t i, ssize_t j);

bool	check_map(t_map	map);
bool	check_map_shape(t_map map);
bool	check_map_borders(t_map map);
bool	check_map_entities(t_map map);
bool	check_map_allowed(t_map map);
bool	check_map_validate(char *str_map);
bool	check_map_extension(char *file, char *extension);

char	*get_str_map(char *file);
void	error_map(t_map map, int code);
void	free_map(t_map map);

ssize_t	find_posx_hero(t_map map);
ssize_t	find_posy_hero(t_map map);
ssize_t	get_map_width(char *str_map);
ssize_t	get_map_height(char *str_map, ssize_t width);

#endif