/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:55 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/24 18:29:08 by migmanu          ###   ########.fr       */
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
	fill_map(&data);
	mlx_key_hook(data.mlx, move_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_vec(data.map.map_v);
	return (0);
}
