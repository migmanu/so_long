/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:51:51 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/22 18:12:18 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	fill_floor(t_data *data)
{
	printf("fill floor init\n");
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
	printf("fill corners init\n");
	mlx_image_to_window(data->mlx, data->img.corner_nw, (0), (0));
	mlx_image_to_window(data->mlx, data->img.corner_ne,
		((data->map.line_length - 1) * SIZE), (0));
	mlx_image_to_window(data->mlx, data->img.corner_se,
		((data->map.line_length - 1) * SIZE),
		((data->map.line_count - 1) * SIZE));
	mlx_image_to_window(data->mlx, data->img.corner_sw,
		(0), ((data->map.line_count - 1) * SIZE));
}

void	fill_outer_walls(t_data *data)
{
	printf("fill outer walls init\n");
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
	printf("fill dirt init\n");
	if ((x + y) % 2 == 0)
	{
		mlx_image_to_window(data->mlx,
			data->img.dirt_1, x * SIZE, y * SIZE);
	}
	else
	{
		mlx_image_to_window(data->mlx,
			data->img.poop, x * SIZE, y * SIZE);

	}
}

void	fill_others(t_data *data)
{
	printf("fill others init\n");
	int	y;
	int	x;

	y = 0;
	while (y < data->map.line_count)
	{
		x = 0;
		while (x < (int)data->map.line_length)
		{
			if (data->map.map_v[y][x] == 'P')
			{
				printf("player gonna b placed\n");
				mlx_image_to_window(data->mlx,
					data->img.dora_1, x * SIZE, y * SIZE);
				printf("player placed\n");
				data->player_pos_x = x;
				data->player_pos_y = y;
			}
			if (data->map.map_v[y][x] == 'C')
				fill_dirt(data, x, y);
			x++;
		}
		y++;
	}
}

void	fill_map(t_data *data)
{
	printf("fill map init\n");
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
	fill_floor(data);
	fill_outer_walls(data);
	fill_corners(data);
	fill_others(data);
	fill_inner_walls(data);
	printf("map filled\n");
}
