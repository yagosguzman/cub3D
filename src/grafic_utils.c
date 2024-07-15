/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:00:17 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/15 17:17:36 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	rgb_to_hex(int rgb[3])
{
	int	red;
	int	green;
	int	blue;

	red = rgb[0];
	green = rgb[1];
	blue = rgb[2];
	return ((red << 16) | (green << 8) | blue);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_PRESS)
		exit(0);
	set_key_state(&game->keys, keycode, 1);
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	set_key_state(&game->keys, keycode, 0);
	return (0);
}

void	clear_screen(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
		{
			if (y < SCREENHEIGHT / 2)
				game->mlx->data[y * SCREENWIDTH + x] = rgb_to_hex(game->ceiling);
			else
				game->mlx->data[y * SCREENWIDTH + x] = rgb_to_hex(game->floor);
		}
	}
}

void	safe_clean_mlx(t_game *game)
{
	if (game && game->mlx)
	{
		safe_free((void **)&game->mlx->mlx);
		safe_free((void **)&game->mlx->win);
		safe_free((void **)&game->mlx);
	}
}
