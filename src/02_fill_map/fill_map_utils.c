/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:01:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/21 21:34:52 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_inner_walls(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->map.line_count - 1)
	{
		x = 0;
		while (x < (int)data->map.line_length - 1)
		{
			if (data->map.map_v[y][x] == '1')
			{
				mlx_image_to_window(data->mlx,
						data->img.wall_left,
						(x *  SIZE), (y * SIZE));
			}
			x++;
		}
		y++;
	}
}
