/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:18:06 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/15 16:42:51 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Counts the amount of lines in the map. Error if 
// if not all line same lenght
int	get_map_lines_nbr(t_data *data, char *file)
{
	char	*line;
	int		fd;
	int		r;
	size_t	l;

	fd = open(file, O_RDONLY);
	r = 0;
	if (fd < 0)
		exit_error(MAPNOPEN);
	else
	{
		line = get_next_line(fd);
		data->map.line_length = ft_strlen(line) - 1;
		while (line != NULL)
		{
			l = ft_strlen(line) - 1;
			free(line);
			if (l != data->map.line_length)
				exit_error(WRGMAP);
			r++;
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (r);
}

// Reads from input file and puts lines into the 
// map vector inside the structure map
void	fill_in_map_v(t_data *data)
{
	char	*line;
	int		i;
	int		w;

	line = get_next_line(data->map.fd);
	printf("line len %ld\n", ft_strlen(line));
	printf("line length in map %ld\n", data->map.line_length);
	i = 0;
	while (line != NULL)
	{
		data->map.map_v[i] = ft_calloc(ft_strlen(line), sizeof(char));
		if (data->map.map_v == NULL)
			handle_error(data, MALLERR);
		w = 0;
		while (w < (int) data->map.line_length)
		{
			data->map.map_v[i][w] = line[w];
			w++;
		}
		data->map.map_v[i][data->map.line_length] = '\0';
		free(line);
		line = NULL;
		line = get_next_line(data->map.fd);
		i++;
	}
	data->map.map_v[i] = NULL;
}

// Main function in charge of building the map from
// the .ber file
t_bool	build_map(t_data *data, char *file)
{
	data->map.line_count = get_map_lines_nbr(data, file);
	data->map.path = file;
	data->map.coll = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->map.map_v = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map_v))
		exit_error(MALLERR);
	data->map.fd = open(file, O_RDONLY);
	if (data->map.fd < 0)
	{
		exit_error(MAPNOPEN);
	}
	else
	{
		fill_in_map_v(data);
		close(data->map.fd);
	}
	return (true);
}
