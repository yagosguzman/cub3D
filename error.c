/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:17:47 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/10 21:24:14 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_error(t_game *game, int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Incorrect map file extension.\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Unexpected elements on the map.\n", 2);
	if (errnum == 3)
		ft_putstr_fd("The map is not completely surrounded by walls.\n", 2);
	if (errnum == 4)
		ft_putstr_fd("Incomplete map info.\n", 2);
	if (errnum == 5)
		ft_putstr_fd("More than one player on the map.\n", 2);
	if (errnum == 6)
		ft_putstr_fd("Problem reading the map.\n", 2);
	if (errnum == 7)
		ft_putstr_fd("Problem with mallocs.\n", 2);
	return (ft_free(game));
}

int	ft_error_mlx(int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Problem initializing MLX Library.\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Problem initializing Window on MLX.\n", 2);
	return (1);
}