/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:58:33 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/11 21:29:59 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_chars(t_data *data)
{
	int	i;
	int	c;

	i = 0;
	printf("line count: %d\n", data->map.line_count);
	while (i < data->map.line_count)
	{
		c = 0;
		while (data->map.map_v[i][c] != '\0')
		{
			check_char_type(data->map.map_v[i][c]);
		}
		i++;
	}
}

static void	check_walls(t_data *data)
{
	int	i;
	int	c;

	i = 0;
	while (data->map.map_v[0][i] != '\0')
	{
		if (data->map.map_v[0][i++] != '1')
			handle_error(data, WRGWALL);
	}
	c = 1;
	i = 0;
	while (c < data->map.line_count)
	{
		if (data->map.map_v[c][0] != '1')
			handle_error(data, WRGWALL);
		if (data->map.map_v[c++][data->map.line_length - 1] != '1')
			handle_error(data, WRGWALL);
	}
	i = 0;
	while (data->map.map_v[data->map.line_count - 1][i] != '\0')
	{
		if (data->map.map_v[data->map.line_count - 1][i++] != '1')
			handle_error(data, WRGWALL);
	}
}

int	parse_map(t_data *data)
{
	if (data->map.map_v == NULL)
		return (1); // manage error
	check_walls(data);
	return (0);
}
