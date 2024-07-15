/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:32:46 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/14 11:58:40 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_win(int keycode, t_mlx *s_mlx)
{
	mlx_destroy_window(s_mlx->mlx, s_mlx->win);
	return (0);
}

int	handle_mouse(int x, int y, t_game *game)
{
	static int	last_x = -1;

	if (last_x == -1)
		last_x = x;
	if (x > last_x)
		rotate_right(game->player, (x - last_x) * MOUSE_SENSITIVITY);
	else if (x < last_x)
		rotate_left(game->player, (last_x - x) * MOUSE_SENSITIVITY);
	last_x = x;
	return (0);
}
