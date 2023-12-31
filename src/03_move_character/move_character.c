/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:33:11 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/26 16:39:24 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->moves);
	ft_putendl_fd(moves, 1);
	free(moves);
}

void	remove_coll(t_data *data, int x, int y)
{
	data->map.map_v[y][x] = '0';
	mlx_image_to_window(
		data->mlx,
		data->img.floor_1,
		(x * SIZE),
		(y * SIZE));
}

void	check_game_status(t_data *data)
{
	if (data->map.map_v[data->player_pos_y][data->player_pos_x] == 'C')
		remove_coll(data, data->player_pos_x, data->player_pos_y);
	if (data->map.coll == 0)
	{
		data->img.charger_w->enabled = false;
		data->img.charger_r->enabled = true;
	}
	if (data->map.coll == 0
		&& data->map.map_v[data->player_pos_y][data->player_pos_x] == 'E')
		handle_error(data, "end\n");
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	if (mlx_is_key_down(((t_data *)data)->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(((t_data *)data)->mlx);
		handle_error(data, "end");
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(data);
}
