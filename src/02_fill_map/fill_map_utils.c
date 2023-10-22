/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:01:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/22 18:11:10 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Chooses different textures for the inner walls and sends
// them to the image
void	chose_inner_wall(t_data *data, int x, int y)
{
	printf("fill inner walls init\n");
	int	r;

	r = x + y * (int)data->map.line_length * data->map.line_count * 11;
	if (r % 2 == 0)
	{
		mlx_image_to_window(data->mlx,
				data->img.plan_1,
				(x *  SIZE), (y * SIZE));
	}
	else
	{
		mlx_image_to_window(data->mlx,
				data->img.table,
				(x *  SIZE), (y * SIZE));
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
