/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:30:37 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/24 18:29:59 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <stdlib.h>

// Fills all non wall or already filled chars in the map copy
// with F
void	flood_fill(char ***map, int y, int x)
{
	if ((*map)[y] != NULL)
	{
		if ((*map)[y][x] != '1' && (*map)[y][x] != 'F')
		{
			if ((*map)[y][x] != '\0')
			{
				(*map)[y][x] = 'F';
				flood_fill(map, y, x + 1);
				flood_fill(map, y, x - 1);
				flood_fill(map, y + 1, x);
				flood_fill(map, y - 1, x);
			}
		}
	}
}

int	check_flood(t_data data, char **map_copy)
{
	int	i;
	int	c;

	i = 0;
	while (i < data.map.line_count)
	{
		c = 0;
		while (map_copy[i][c] != '\0')
		{
			if (map_copy[i][c] == 'E' || map_copy[i][c] == 'C')
			{
				return (-1);
			}
			c++;
		}
		i++;
	}
	return (0);
}

char	**copy_map(t_data data)
{
	char	**map_copy;
	int		i;
	int		c;

	map_copy = malloc((data.map.line_count + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < data.map.line_count)
	{
		c = 0;
		map_copy[i] = malloc((data.map.line_length + 1) * sizeof(char));
		if (!map_copy[i])
			break ;
		while (c < (int)data.map.line_length)
		{
			map_copy[i][c] = data.map.map_v[i][c];
			c++;
		}
		map_copy[i][c] = '\0';
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

// Takes a copy of the map, floods it and check that all collectables
// and the exit are replaced. If not, returns error.
int	flood_map(t_data data)
{
	char	**map_copy;

	map_copy = copy_map(data);
	flood_fill(&map_copy, data.player_pos_y, data.player_pos_x);
	if (check_flood(data, map_copy) == -1)
	{
		ft_free_vec(map_copy);
		return (-1);
	}
	ft_free_vec(map_copy);
	return (0);
}
