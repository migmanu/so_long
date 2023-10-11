/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:42 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/11 17:21:20 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

# define WRGMAP "Map is not valid\n"
# define MAPNOPEN "Map could not be opened\n"
# define NOTRECT "Map is not a rectangle\n"
# define NOEXIT "Map has no valid exit or valid path to exit\n"
# define COLLERR "Map has no valid path to collectables\n"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_map
{
	char	*path;
	int		fd;
	int		line_count;
	size_t	line_length;
	char	**map_v;
}	t_map;

typedef struct s_data
{
	t_map	map;
}	t_data;

# ifndef FALSE
#  define FALSE false
# endif

# ifndef TRUE
#  define TRUE true
# endif

// build_map
t_bool	build_map(t_data *data, char *file);

#endif
