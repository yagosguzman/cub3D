/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:24:26 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/28 19:20:54 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	destroy_win(int keycode, t_mlx *s_mlx)
{
	mlx_destroy_window(s_mlx->mlx, s_mlx->win);
	return (0);
}

int	ft_close_handler(t_mlx *s_mlx)
{
	// safe_clean_mlx(s_mlx);
	exit (EXIT_SUCCESS);
}

int	ft_key_handle(int keysym, t_mlx *s_mlx)
{
	printf("se ha pulsado %d", keysym);
	if (keysym == ESC_PRESS)
		return (ft_close_handler(s_mlx));
	return (0);
}