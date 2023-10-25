/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:01:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/25 16:22:55 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_floor(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.line_count)
	{
		x = 0;
		while (x < (int)data->map.line_length)
		{
			mlx_image_to_window(
				data->mlx,
				data->img.floor_1,
				(x * SIZE),
				(y * SIZE));
			x++;
		}
		y++;
	}
}

void	fill_corners(t_data *data)
{
	mlx_image_to_window(data->mlx, data->img.corner_nw, (0), (0));
	mlx_image_to_window(data->mlx, data->img.corner_ne,
		((data->map.line_length - 1) * SIZE), (0));
	mlx_image_to_window(data->mlx, data->img.corner_se,
		((data->map.line_length - 1) * SIZE),
		((data->map.line_count - 1) * SIZE));
	mlx_image_to_window(data->mlx, data->img.corner_sw,
		(0), ((data->map.line_count - 1) * SIZE));
}

// Chooses different textures for the inner walls and sends
// them to the image
void	chose_inner_wall(t_data *data, int x, int y)
{
	int	r;

	r = x + y * (int)data->map.line_length * data->map.line_count * 11;
	if (r % 2 == 1)
	{
		mlx_image_to_window(data->mlx,
			data->img.plan_1, (x * SIZE), (y * SIZE));
	}
	else if (r % 3 == 1)
	{
		mlx_image_to_window(data->mlx,
			data->img.chair, (x * SIZE), (y * SIZE));
	}
	else
	{
		mlx_image_to_window(data->mlx,
			data->img.books, (x * SIZE), (y * SIZE));
	}
}

void	fill_inner_walls(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->map.line_count - 1)
	{
		x = 1;
		while (x < (int)data->map.line_length - 1)
		{
			if (data->map.map_v[y][x] == '1')
				chose_inner_wall(data, x, y);
			x++;
		}
		y++;
	}
}
