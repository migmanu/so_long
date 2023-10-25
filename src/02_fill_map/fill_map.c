/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:51:51 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/25 16:22:42 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_outer_walls(t_data *data)
{
	int	i;

	i = 1;
	while (i < (int)data->map.line_length - 1)
	{
		mlx_image_to_window(data->mlx, data->img.wall_up, (i * SIZE), (0));
		mlx_image_to_window(data->mlx, data->img.wall_down,
			(i * SIZE), (data->map.line_count - 1) * SIZE);
		i++;
	}
	i = 1;
	while (i < data->map.line_count - 1)
	{
		mlx_image_to_window(data->mlx,
			data->img.wall_left,
			(0), (i * SIZE));
		mlx_image_to_window(data->mlx,
			data->img.wall_right,
			((data->map.line_length - 1) * SIZE), (i * SIZE));
		i++;
	}
}

void	fill_dirt(t_data *data, int x, int y)
{
	if ((x + y) % 2 == 0)
	{
		data->img.coll = data->img.dirt_1;
		mlx_image_to_window(data->mlx,
			data->img.coll, x * SIZE, y * SIZE);
	}
	else
	{
		data->img.coll = data->img.poop;
		mlx_image_to_window(data->mlx,
			data->img.coll, x * SIZE, y * SIZE);
	}
}

void	fill_dora(t_data *data, int x, int y)
{
	data->img.dora = data->img.dora_s_d;
	mlx_image_to_window(data->mlx,
		data->img.dora, x * SIZE, y * SIZE);
	data->player_pos_x = x;
	data->player_pos_y = y;
}

void	fill_others(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map.line_count)
	{
		x = 0;
		while (x < (int)data->map.line_length)
		{
			if (data->map.map_v[y][x] == 'P')
				fill_dora(data, x, y);
			else if (data->map.map_v[y][x] == 'C')
				fill_dirt(data, x, y);
			else if (data->map.map_v[y][x] == 'E')
			{
				mlx_image_to_window(data->mlx,
					data->img.charger_w, x * SIZE, y * SIZE);
				mlx_image_to_window(data->mlx,
					data->img.charger_r, x * SIZE, y * SIZE);
				data->img.charger_r->enabled = false;
			}
			x++;
		}
	}
}

void	fill_map(t_data *data)
{
	data->mlx = mlx_init(
			(SIZE * data->map.line_length),
			(SIZE * data->map.line_count),
			"Dora la aspiradora", true);
	if (!data->mlx)
		handle_error(data, UNXERR);
	load_assets(data);
	fill_floor(data);
	fill_outer_walls(data);
	fill_corners(data);
	fill_inner_walls(data);
	fill_others(data);
}
