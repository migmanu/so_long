/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:51:51 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/17 18:57:24 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	(void )param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		puts("Hola mundo!");
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	fill_map(t_data *data)
{
	// Start mlx
	data->mlx = mlx_init((WIDTH * data->map.line_length * 4), (HEIGHT * data->map.line_count * 4), "Test", true);
	if (!data->mlx)
        	error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png(FLOOR1);
	if (!texture)
        	error();

	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(data->mlx, texture);
	if (!img)
        	error();

	// Display the image
	printf("about to display lin %d, col %zu\n", data->map.line_count, data->map.line_length);
	int	lin = 0;
	int	col;
	while (lin < ((int)data->map.line_count * 4))
	{
		col = 0;
		while (col < ((int)data->map.line_length * 4))
		{
			mlx_image_to_window(data->mlx, img, (HEIGHT * col), (WIDTH * lin));
			col++;
		}
		lin++;
	}
	printf("lin %d, col %d\n", lin, col);

	mlx_loop(data->mlx);

	mlx_delete_image(data->mlx, img);
	mlx_delete_texture(texture);

        // Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(data->mlx);
}
