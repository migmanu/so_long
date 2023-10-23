/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:59:41 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/23 19:50:07 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_up(t_data *data)
{
	size_t	c;

	if (data->map.map_v[data->player_pos_y - 1][data->player_pos_x] != '1')
	{
		data->player_pos_y -= 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
			data->map.coll -= 1;
		check_game_status(data);
		c = 0;
		while (c < data->img.dora->count)
			data->img.dora->instances[c++].enabled = false;
		mlx_image_to_window(data->mlx,
			data->img.dora_s_u, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		data->img.dora = data->img.dora_s_u;
	}
}

void	move_down(t_data *data)
{
	size_t	c;

	if (data->map.map_v[data->player_pos_y + 1][data->player_pos_x] != '1')
	{
		data->player_pos_y += 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		mlx_image_to_window(data->mlx,
			data->img.dora, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		check_game_status(data);
		c = 0;
		while (c < data->img.dora->count)
			data->img.dora->instances[c++].enabled = false;
		mlx_image_to_window(data->mlx,
			data->img.dora_s_d, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		data->img.dora = data->img.dora_s_d;
	}
}

void	move_right(t_data *data)
{
	size_t	c;

	if (data->map.map_v[data->player_pos_y][data->player_pos_x + 1] != '1')
	{
		data->player_pos_x += 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		mlx_image_to_window(data->mlx,
			data->img.dora, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		check_game_status(data);
		c = 0;
		while (c < data->img.dora->count)
			data->img.dora->instances[c++].enabled = false;
		mlx_image_to_window(data->mlx,
			data->img.dora_s_r, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		data->img.dora = data->img.dora_s_r;
	}
}

void	move_left(t_data *data)
{
	size_t	c;

	if (data->map.map_v[data->player_pos_y][data->player_pos_x - 1] != '1')
	{
		data->player_pos_x -= 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		mlx_image_to_window(data->mlx,
			data->img.dora, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		check_game_status(data);
		c = 0;
		while (c < data->img.dora->count)
			data->img.dora->instances[c++].enabled = false;
		mlx_image_to_window(data->mlx,
			data->img.dora_s_l, data->player_pos_x * SIZE,
			data->player_pos_y * SIZE);
		data->img.dora = data->img.dora_s_l;
	}
}
