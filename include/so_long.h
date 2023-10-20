/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:42 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/20 12:37:28 by migmanu          ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

# define WRGMAP "Map is not valid\n"
# define WRGWALL "Map is not correctly delimited by walls\n"
# define MALLERR "Malloc error\n"
# define MAPNOPEN "Map could not be opened\n"
# define NOTRECT "Map is not a rectangle\n"
# define NOPATH "Map has no valid path to exit or collectable\n"
# define COLLERR "Map has no valid path to collectables\n"
# define UNXERR "Unexpected error ocurred\n"

# define FLOOR1 "assets/textures/tiles/wood_floor.png"
# define WALL1 "assets/textures/tiles/junglegrass.png"
#define SIZE 64

typedef struct s_map
{
	char	*path;
	int		fd;
	int		coll;
	int		exit;
	int		player;
	int		player_pos[2];
	int		line_count;
	size_t	line_length;
	char	**map_v;
}	t_map;

typedef struct s_img
{
	mlx_image_t	*floor_1;
	mlx_image_t	*floor_2;
	mlx_image_t	*floor_3;
	mlx_image_t	*wall_1;
	mlx_image_t	*wall_2;
	mlx_image_t	*wall_3;
	mlx_image_t	*bed;
	mlx_image_t	*sofa;
	mlx_image_t	*table;
	mlx_image_t	*chair1;
	mlx_image_t	*chair2;
	mlx_image_t	*coll;
}	t_img;

typedef struct s_data
{
	t_map	map;
	mlx_t	*mlx;
	t_img	img;
}	t_data;

/****************	00_build_map	****************/
// build_map
int	build_map(t_data *data, char *file);

/****************	01_check_map	****************/
// map_parse.c
int	check_map(t_data *data);
// map_flood.c
int	flood_map(t_data data);

/****************	02_fill_map	****************/
// fill_map.c
void	fill_map(t_data *data);
// load_assets.c
void	load_assets(t_data *data);

/****************	10_error_handling	****************/
// handle_error.c
void	handle_error(t_data *data, char str[]);
void	exit_error(char str[]);

#endif
