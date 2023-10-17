/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/17 17:18:30 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdint.h>
#include <stdlib.h>
#define WIDTH 32
#define HEIGHT 32
#define BPP sizeof(int32_t)

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

int	main(int argc, char **argv)
{
	t_data	data;

	printf("argc %d", argc);
	build_map(&data, argv[1]);
	check_map(&data);
	if (flood_map(data) == -1)
		handle_error(&data, NOPATH);

	// Start mlx
	mlx_t* mlx = mlx_init((WIDTH * data.map.line_length), (HEIGHT * data.map.line_count), "Test", true);
	if (!mlx)
        	error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./assets/StoneBrickFloor.png");
	if (!texture)
        	error();

	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        	error();

	// Display the image
	printf("about to display lin %d, col %zu\n", data.map.line_count, data.map.line_length);
	int	lin = 0;
	int	col;
	while (lin < (int)data.map.line_count)
	{
		col = 0;
		while (col < (int)data.map.line_length)
		{
			mlx_image_to_window(mlx, img, (HEIGHT *col), (WIDTH *lin));
			col++;
		}
		lin++;
	}
	printf("lin %d, col %d\n", lin, col);

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);

        // Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
