/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:07:38 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/11 20:42:30 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	exit_error(char str[])
{
	if (ft_strncmp(str, MAPNOPEN, ft_strlen(str)) == 0)
		ft_putendl_fd(MAPNOPEN, 1);
	if (ft_strncmp(str, WRGMAP, ft_strlen(str)) == 0)
		ft_putendl_fd(WRGMAP, 1);
	if (ft_strncmp(str, WRGWALL, ft_strlen(str)) == 0)
		ft_putendl_fd(WRGWALL, 1);
	exit(ERROR);
}

void	handle_error(t_data *data, char str[])
{
	ft_free_vec(data->map.map_v);
	exit_error(str);
}
