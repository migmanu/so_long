/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:18:06 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/26 16:05:33 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Counts the amount of lines in the map. Also
// sets the line_length. Error if 
// if not all line same lenght. Lines count is later
// considered the y axis. Because of reasosns,
// coordinates will be given (y, x)
int	get_map_lines_nbr(t_data *data, char *file)
{
	char	*line;
	int		fd;
	int		r;

	fd = open(file, O_RDONLY);
	r = 0;
	if (fd < 0)
		handle_error(data, MAPNOPEN);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			free(line);
			line = NULL;
			r++;
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (r);
}

int	check_rec(t_data *data, char *file)
{
	char	*line;
	int		fd;
	int		i;
	int		r;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		handle_error(data, WRGMAP);
	i = 0;
	r = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	r = i;
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		free(line);
		if (i != r)
			return (-1);
		line = get_next_line(fd);
	}
	return (0);
}

// Reads from input file and puts lines into the 
// map vector inside the structure map
void	fill_in_map_v(t_data *data)
{
	char	*line;
	int		i;
	int		w;

	line = get_next_line(data->map.fd);
	data->map.line_length = ft_strlen(line) - 1;
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

void	fill_data(t_data *data, char *file)
{
	data->mlx = NULL;
	data->map.map_v = NULL;
	data->map.line_count = get_map_lines_nbr(data, file);
	data->map.map_v = ft_calloc(data->map.line_count + 1, sizeof(char *));
	data->map.path = file;
	data->map.coll = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->moves = 0;
}

// Main function in charge of building the map from
// the .ber file
int	build_map(t_data *data, char *file)
{
	char	*ext;

	ext = ft_strrchr(file, 46);
	if (ext == NULL || ext[0] != '.' || ext[1] != 'b' || ext[2] != 'e'
		|| ext[3] != 'r' || ext[4] != '\0')
		handle_error(data, WRNGEXT);
	fill_data(data, file);
	if (check_rec(data, file) == -1)
	{
		handle_error(data, NOTREC);
		return (1);
	}
	if (!(data->map.map_v))
		exit_error(MALLERR);
	data->map.fd = open(file, O_RDONLY);
	if (data->map.fd < 0)
	{
		handle_error(data, MAPNOPEN);
	}
	else
	{
		fill_in_map_v(data);
		close(data->map.fd);
	}
	return (0);
}
