/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/17 14:21:46 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdint.h>
#include <stdlib.h>
#define WIDTH 256
#define HEIGHT 256
#define BPP sizeof(int32_t)

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static mlx_image_t	*g_img;
// Print the window width and height.
static void ft_hook(void* param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);
	for (int x = 0; x < (int)g_img->width; x++)
		for (int y = 0; y < (int)g_img->height; y++)
			mlx_put_pixel(g_img, x, y, rand() % RAND_MAX);

}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	(void )param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		puts("Hola mundo!");
}

int	main(int argc, char **argv)
{
	t_data	data;

	printf("argc %d", argc);
	build_map(&data, argv[1]);
	check_map(&data);
	if (flood_map(data) == -1)
		handle_error(&data, NOPATH);

// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 100, 100, 0xFF0000FF);
	// memset(img->pixels, 255, img->width * img->height * BPP);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_key_hook(mlx, &keyhook, NULL);
	g_img = mlx_new_image(mlx, 128, 128);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	ft_free_vec(data.map.map_v);
	return (0);
}
