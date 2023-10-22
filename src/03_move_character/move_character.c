/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:33:11 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/22 18:32:02 by migmanu          ###   ########.fr       */
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
		if (data->map.map_v[data->player_pos_y][data->player_pos_x] == '1')
		{
			data->map.coll -= 1;
		}
	}
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	if (mlx_is_key_down(((t_data *)data)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(((t_data *)data)->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(data);
}

