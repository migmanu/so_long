/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:10:31 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/21 00:34:43 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

mlx_texture_t	*load_texture(t_data *data, char str[])
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(str);
	if (!texture)
		handle_error(data, TEXTERR);
	return (texture);
}

mlx_image_t	*texture_to_image(t_data *data, mlx_texture_t **texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(data->mlx, *texture);
	mlx_delete_texture(*texture);
	if (!image)
		handle_error(data, IMGERR);
	return (image);
}

void	load_walls(t_data *data)
{
	mlx_texture_t	*texture;

	texture = load_texture(data, WALL_LEFT);
	data->img.wall_left = texture_to_image(data, &texture);
	texture = load_texture(data, WALL_RIGHT);
	data->img.wall_right = texture_to_image(data, &texture);
	texture = load_texture(data, WALL_UP);
	data->img.wall_up = texture_to_image(data, &texture);
	texture = load_texture(data, WALL_DOWN);
	data->img.wall_down = texture_to_image(data, &texture);
	texture = load_texture(data, CORNER_NW);
	data->img.corner_nw = texture_to_image(data, &texture);
	texture = load_texture(data, CORNER_NE);
	data->img.corner_ne = texture_to_image(data, &texture);
	texture = load_texture(data, CORNER_SW);
	data->img.corner_sw = texture_to_image(data, &texture);
	texture = load_texture(data, CORNER_SE);
	data->img.corner_se = texture_to_image(data, &texture);
}

void	load_others(t_data *data)
{
	mlx_texture_t	*texture;

	texture = load_texture(data, FLOOR1);
	data->img.floor_1 = texture_to_image(data, &texture);
	texture = load_texture(data, DORA_1);
	data->img.dora_1 = texture_to_image(data, &texture);
}

void	load_assets(t_data *data)
{
	printf("load assets init\n");
	load_walls(data);
	load_others(data);
	printf("load assets end\n");
}
