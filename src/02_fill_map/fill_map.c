/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:51:51 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/20 17:56:47 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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

void	fill_outer_walls(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 1 + y;
	x /= x + data->map.line_length;
}

void	fill_map(t_data *data)
{
	// Start mlx
	data->mlx = mlx_init(
			(SIZE * data->map.line_length),
			(SIZE * data->map.line_count),
			"Test", true);
	if (!data->mlx)
        	error();

	load_assets(data);
	// Display the image
	printf("about to display lin %d, col %zu\n",
			data->map.line_count,
			data->map.line_length);
	/*
	int	lin;
	int	col = 0;
	while (col < ((int)data->map.line_count))
	{
		lin = 0;
		while (lin < ((int)data->map.line_length))
		{
			if (data->map.map_v[col][lin] == 49)
			{
				mlx_image_to_window(
						data->mlx,
						data->img.wall_1,
						(lin * SIZE),
						(col * SIZE));
			}
			else
			{
				mlx_image_to_window(
						data->mlx,
						data->img.wall_1,
						(lin * SIZE),
						(col * SIZE));
			}
			lin++;
		}
		col++;
	}
	printf("lin %d, col %d\n", lin, col);
*/
	fill_floor(data);
	mlx_loop(data->mlx);


	mlx_delete_image(data->mlx, data->img.floor_1);
	mlx_delete_image(data->mlx, data->img.wall_1);
    // Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(data->mlx);
}
