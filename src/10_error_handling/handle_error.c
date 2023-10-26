/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:07:38 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/26 15:56:06 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	exit_error(char str[])
{
	ft_putendl_fd("Error", 1);
	if (ft_strncmp(str, MAPNOPEN, ft_strlen(str)) == 0)
		ft_putendl_fd(MAPNOPEN, 1);
	if (ft_strncmp(str, WRGMAP, ft_strlen(str)) == 0)
		ft_putendl_fd(WRGMAP, 1);
	if (ft_strncmp(str, WRGWALL, ft_strlen(str)) == 0)
		ft_putendl_fd(WRGWALL, 1);
	if (ft_strncmp(str, NOPATH, ft_strlen(str)) == 0)
		ft_putendl_fd(NOPATH, 1);
	if (ft_strncmp(str, NOTREC, ft_strlen(str)) == 0)
		ft_putendl_fd(NOTREC, 1);
	if (ft_strncmp(str, WRNGEXT, ft_strlen(str)) == 0)
		ft_putendl_fd(WRNGEXT, 1);
	exit(ERROR);
}

void	handle_error(t_data *data, char str[])
{
	ft_free_vec(data->map.map_v);
	if (data->mlx != NULL)
		mlx_terminate(data->mlx);
	if (ft_strncmp(str, "end", 3) == 0)
	{
		exit(0);
		return ;
	}
	exit_error(str);
}
