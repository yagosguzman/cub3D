/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:28:01 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/18 21:56:23 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	exit(0);
	return (0);
}

int	game_loop_hooks(t_game *game)
{
	if (get_key_state(game->keys, W_KEY))
		move_forward_backward(game, W_KEY);
	if (get_key_state(game->keys, S_KEY))
		move_forward_backward(game, S_KEY);
	if (get_key_state(game->keys, A_KEY))
		move_left_right(game, A_KEY);
	if (get_key_state(game->keys, D_KEY))
		move_left_right(game, D_KEY);
	if (get_key_state(game->keys, LEFT_ARROW))
		rotate_left(game->player, ROT_SPEED);
	if (get_key_state(game->keys, RIGHT_ARROW))
		rotate_right(game->player, ROT_SPEED);
	cast_rays(game);
	return (0);
}

void	game_loop(t_game *game)
{
	initialize_game(game);
	cast_rays(game);
	mlx_hook(game->mlx->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->mlx->win, 6, 1L << 6, handle_mouse, game);
	mlx_hook(game->mlx->win, 17, 0L, close_window, game);
	mlx_mouse_hide(game->mlx->mlx, game->mlx->win);
	mlx_mouse_move(game->mlx->mlx, game->mlx->win,
		SCREENWIDTH / 2, SCREENHEIGHT / 2);
	mlx_loop_hook(game->mlx->mlx, game_loop_hooks, game);
	mlx_loop(game->mlx->mlx);
}
