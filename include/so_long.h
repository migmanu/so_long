/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:42 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/10 19:02:49 by migmanu          ###   ########.fr       */
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

# define WRGMAP "Inputed map is not valid\n"
# define NOTRECT "Inputed map is not a rectangle\n"
# define NOEXIT "Inputed map has no valid exit or valid path to exit\n"
# define COLLERR "Inputed map has no valid path to collectables\n"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

# ifndef FALSE
#  define FALSE false
# endif

# ifndef TRUE
#  define TRUE true
# endif

#endif
