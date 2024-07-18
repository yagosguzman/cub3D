/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:32:46 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/18 20:53:07 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	destroy_win(int keycode, t_mlx *s_mlx)
{
	mlx_destroy_window(s_mlx->mlx, s_mlx->win);
	return (0);
}

int	handle_mouse(int x, int y, t_game *game)
{
    int center_x;
    int center_y;
    static int last_x = -1;

    center_x = SCREENWIDTH / 2;
    center_y = SCREENHEIGHT / 2;
    if (last_x == -1)
        last_x = center_x;
    if (x <= 0 || x >= SCREENWIDTH - 1 || y <= 0 || y >= SCREENHEIGHT - 1)
    {
        mlx_mouse_move(game->mlx->mlx, game->mlx->win, center_x, center_y);
        last_x = center_x;
        return (0);
    }
    if (x != last_x)
    {
        if (x > last_x)
            rotate_right(game->player, (x - last_x) * MOUSE_SENSITIVITY);
        else if (x < last_x)
            rotate_left(game->player, (last_x - x) * MOUSE_SENSITIVITY);
    }
    mlx_mouse_move(game->mlx->mlx, game->mlx->win, center_x, center_y);

    return (0);
}

