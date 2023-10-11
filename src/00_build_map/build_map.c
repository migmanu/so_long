/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:18:06 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/11 17:40:59 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	exit_error(char str[])
{
	if (ft_strncmp(str, MAPNOPEN, ft_strlen(str)) == 0)
		ft_putendl_fd(MAPNOPEN, 1);
	if (ft_strncmp(str, WRGMAP, ft_strlen(str)) == 0)
		ft_putendl_fd(WRGMAP, 1);
	exit(ERROR);
}

void	handle_error(t_data *data, char str[])
{
	ft_free_vec(data->map.map_v);
	exit_error(str);
}

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
		data->map.line_length = ft_strlen(line);
		while (line != NULL)
		{
			l = ft_strlen(line);
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

void	fill_in_map_v(t_data *data)
{
	char	*line;
	int		i;

	line = get_next_line(data->map.fd);
	i = 0;
	while (line != NULL)
	{
		data->map.map_v[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (data->map.map_v == NULL)
			// handle_error
		data->map.map_v[i] = line;
		data->map.map_v[i][ft_strlen(line)] = '\0';
		printf("length %ld\n", ft_strlen(line));
		printf("line: %s\n", data->map.map_v[i]);
		free(line);
		line = get_next_line(data->map.fd);
		i++;
	}
}

// Main function in charge of building the map from
// the .ber file
t_bool	build_map(t_data *data, char *file)
{
	data->map.line_count = get_map_lines_nbr(data, file);
	data->map.path = file;
	data->map.map_v = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map_v))
		exit_error(MAPNOPEN); // correct error
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
	ft_free_vec(data->map.map_v);
	return (true);
}
