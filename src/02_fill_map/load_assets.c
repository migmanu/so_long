/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:10:31 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/20 17:52:44 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_walls(t_data *data)
{
	printf("%d", data->map.line_count);
}

void	load_assets(t_data *data)
{
	// Try to load the file
	mlx_texture_t* texture = mlx_load_png(WALL1);
	if (!texture)
        	return ; // handle error
	// Convert texture to a displayable image
	data->img.wall_1 = mlx_texture_to_image(data->mlx, texture);
	if (!data->img.wall_1)
        	return ; // handle error
	mlx_delete_texture(texture);
	texture = mlx_load_png(FLOOR1);
	if (!texture)
        	return ; // handle error
	data->img.floor_1 = mlx_texture_to_image(data->mlx, texture);
	if (!data->img.floor_1)
        	return ; // handle error
	mlx_delete_texture(texture);
}
