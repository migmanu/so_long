/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:42 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/22 16:27:17 by migmanu          ###   ########.fr       */
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
# define TEXTERR "Texture could not be loaded\n"
# define IMGERR "Image could not be loaded\n"

# define FLOOR1 "assets/textures/tiles/wood_floor.png"

# define WALL_LEFT "assets/textures/tiles/wall_left.png"
# define WALL_RIGHT "assets/textures/tiles/wall_right.png"
# define WALL_UP "assets/textures/tiles/wall_up.png"
# define WALL_DOWN "assets/textures/tiles/wall_down.png"
# define CORNER_NW "assets/textures/tiles/wall_corner_nw.png"
# define CORNER_NE "assets/textures/tiles/wall_corner_ne.png"
# define CORNER_SW "assets/textures/tiles/wall_corner_sw.png"
# define CORNER_SE "assets/textures/tiles/wall_corner_se.png"

# define DIRT_1 "assets/textures/collectables/dirt_1.png"
# define DIRT_2 "assets/textures/collectables/dirt_2.png"
# define POOP "assets/textures/collectables/poop.png"

# define FURNI_1 "assets/textures/tiles/cajonera.png"
# define TABLE "assets/textures/tiles/mesa.png"
# define PLANT_1 "assets/textures/tiles/plant_1.png"

# define DORA_1 "assets/textures/robot/robot_stop_1.png"
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
	mlx_image_t	*wall_left;
	mlx_image_t	*wall_right;
	mlx_image_t	*wall_up;
	mlx_image_t	*wall_down;
	mlx_image_t	*corner_nw;
	mlx_image_t	*corner_ne;
	mlx_image_t	*corner_sw;
	mlx_image_t	*corner_se;
	mlx_image_t	*dirt_1;
	mlx_image_t	*dirt_2;
	mlx_image_t	*poop;
	mlx_image_t	*dora_1;
	mlx_image_t	*furni_1;
	mlx_image_t	*table;
	mlx_image_t	*plan_1;
	mlx_image_t	*bed;
	mlx_image_t	*sofa;
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
// fill_map_utils.c
void	fill_inner_walls(t_data *data);

/****************	10_error_handling	****************/
// handle_error.c
void	handle_error(t_data *data, char str[]);
void	exit_error(char str[]);

#endif
