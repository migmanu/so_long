/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:59:41 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/22 23:00:30 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_up(t_data *data)
{
	printf("move_up init\n");
	if (data->map.map_v[data->player_pos_y - 1][data->player_pos_x] != '1')
	{
		data->img.dora_1->instances[0].y -= 1 * SIZE;
		data->player_pos_y -= 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		check_game_status(data);
	}
}

void	move_down(t_data *data)
{
	printf("move_up init\n");
	if (data->map.map_v[data->player_pos_y + 1][data->player_pos_x] != '1')
	{
		data->img.dora_1->instances[0].y += 1 * SIZE;
		data->player_pos_y += 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		check_game_status(data);
	}
}

void	move_right(t_data *data)
{
	printf("move_up init\n");
	if (data->map.map_v[data->player_pos_y][data->player_pos_x + 1] != '1')
	{
		data->img.dora_1->instances[0].x += 1 * SIZE;
		data->player_pos_x += 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		check_game_status(data);
	}
}

void	move_left(t_data *data)
{
	printf("move_up init\n");
	if (data->map.map_v[data->player_pos_y][data->player_pos_x - 1] != '1')
	{
		data->img.dora_1->instances[0].x -= 1 * SIZE;
		data->player_pos_x -= 1;
		data->moves += 1;
		print_moves(data);
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		{
			data->map.coll -= 1;
		}
		check_game_status(data);
	}
}
