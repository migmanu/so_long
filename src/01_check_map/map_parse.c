/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:58:33 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/15 17:28:24 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// check chars are valid
void	check_char_type(t_data *data, char c, int y, int x)
{
	if (c == 'C')
	{
		data->map.coll++;
	}
	else if (c == 'E')
	{
		data->map.exit++;
	}
	else if (c == 'P')
	{
		data->map.player++;
		data->map.player_pos[0] = y;
		data->map.player_pos[1] = x;
	}
	else if (c == '1' || c == '0')
	{
		return ;
	}
	else
	{
		handle_error(data, WRGMAP);
	}
}

// calls check_char_type for each character and handles
// most errors
static void	check_chars(t_data *data)
{
	int	i;
	int	c;

	i = 0;
	while (i < data->map.line_count)
	{
		c = 0;
		while (data->map.map_v[i][c] != '\0')
		{
			check_char_type(data, data->map.map_v[i][c], i, c);
			c++;
		}
		i++;
	}
	if (data->map.coll < 1 || data->map.exit != 1 || data->map.player != 1)
	{
		handle_error(data, WRGMAP);
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

int	check_map(t_data *data)
{
	if (data->map.map_v == NULL)
		handle_error(data, UNXERR);
	check_walls(data);
	check_chars(data);
	return (0);
}
