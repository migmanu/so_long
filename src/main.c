/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/26 19:24:42 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdint.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;

	argc = argc * 0;
	build_map(&data, argv[1]);
	check_map(&data);
	if (flood_map(data) == -1)
		handle_error(&data, NOPATH);
	data.mlx = mlx_init(
			(SIZE * data.map.line_length),
			(SIZE * data.map.line_count),
			"Dora la aspiradora", true);
	if (!data.mlx)
		handle_error(&data, UNXERR);
	fill_map(&data);
	mlx_key_hook(data.mlx, move_hook, &data);
	mlx_loop(data.mlx);
	ft_free_vec(data.map.map_v);
	mlx_terminate(data.mlx);
	if (data.mlx != NULL)
		free(data.mlx);
	return (0);
}
