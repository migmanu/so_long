/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:33:11 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/22 22:58:26 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_moves(t_data *data)
{
	printf("%d\n", data->moves); // change for my ft_printf
}

void	check_game_status(t_data *data)
{
	if (data->map.coll == 0)
	{
		printf("end game\n");
		handle_error(data, "Game end!\n"); // correct end message
	}
}

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

void	move_hook(mlx_key_data_t keydata, void *data)
{
	if (mlx_is_key_down(((t_data *)data)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(((t_data *)data)->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(data);
}
