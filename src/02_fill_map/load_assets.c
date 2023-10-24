/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:10:31 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/24 18:20:55 by migmanu          ###   ########.fr       */
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
	texture = load_texture(data, DIRT_1);
	data->img.dirt_1 = texture_to_image(data, &texture);
	texture = load_texture(data, BOOKS);
	data->img.books = texture_to_image(data, &texture);
	texture = load_texture(data, CHAIR);
	data->img.chair = texture_to_image(data, &texture);
	texture = load_texture(data, FURNI_1);
	data->img.furni_1 = texture_to_image(data, &texture);
	texture = load_texture(data, TABLE);
	data->img.table = texture_to_image(data, &texture);
	texture = load_texture(data, POOP);
	data->img.poop = texture_to_image(data, &texture);
	texture = load_texture(data, PLANT_1);
	data->img.plan_1 = texture_to_image(data, &texture);
}

void	load_dora(t_data *data)
{
	mlx_texture_t	*texture;

	texture = load_texture(data, DORA_S_D);
	data->img.dora = texture_to_image(data, &texture);
	texture = load_texture(data, DORA_S_D);
	data->img.dora_s_d = texture_to_image(data, &texture);
	texture = load_texture(data, DORA_S_U);
	data->img.dora_s_u = texture_to_image(data, &texture);
	texture = load_texture(data, DORA_S_L);
	data->img.dora_s_l = texture_to_image(data, &texture);
	texture = load_texture(data, DORA_S_R);
	data->img.dora_s_r = texture_to_image(data, &texture);
	texture = load_texture(data, CHARGER_READY);
	data->img.charger_r = texture_to_image(data, &texture);
	texture = load_texture(data, CHARGER_WAITING);
	data->img.charger_w = texture_to_image(data, &texture);
}

void	load_assets(t_data *data)
{
	load_walls(data);
	load_dora(data);
	load_others(data);
}
