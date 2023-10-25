/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:25:54 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/25 16:26:20 by jmigoya-         ###   ########.fr       */
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
