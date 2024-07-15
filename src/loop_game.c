/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:28:01 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/15 17:04:54 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	game_loop_hooks(t_game *game)
{
	if (get_key_state(game->keys, W_KEY))
		moveForwardBackward(game, W_KEY);
	if (get_key_state(game->keys, S_KEY))
		moveForwardBackward(game, S_KEY);
	if (get_key_state(game->keys, A_KEY))
		moveLeftRight(game, A_KEY);
	if (get_key_state(game->keys, D_KEY))
		moveLeftRight(game, D_KEY);
	if (get_key_state(game->keys, LEFT_ARROW))
		rotateLeft(game->player, ROT_SPEED);
	if (get_key_state(game->keys, RIGHT_ARROW))
		rotateRight(game->player, ROT_SPEED);
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
	mlx_mouse_hide(game.mlx->mlx, game.mlx->win);
	mlx_mouse_move(game.mlx->mlx, game.mlx->win,
		SCREENWIDTH / 2, SCREENHEIGHT / 2);
	mlx_loop_hook(game->mlx->mlx, game_loop, game);
	mlx_loop(game->mlx->mlx);
}
