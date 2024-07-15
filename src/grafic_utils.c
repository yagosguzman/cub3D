/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:00:17 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/14 15:28:27 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	int	screenwidth;
	int	screenheight;

	screenwidth = SCREENWIDTH;
	screenheight = SCREENHEIGHT;
	y = -1;
	while (++y < screenheight)
	{
		x = -1;
		while (++x < screenwidth)
		{
			if (y < screenheight / 2)
				game->mlx->data[y * screenwidth + x] = 0x87CEEB;
			else
				game->mlx->data[y * screenwidth + x] = 0xCCCCCC;
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