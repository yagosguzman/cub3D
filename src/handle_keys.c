/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:38:06 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/16 23:55:22 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	walk(t_map *map, double x, double y)
{
	return (map->w_map[(int)x][(int)y] == '0');
}

void	move_forward_backward(t_game *game, int keycode)
{
	double	new_pos_x;
	double	new_pos_y;

	if (keycode == W_KEY)
	{
		new_pos_x = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
		new_pos_y = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
		if (walk(game->map, new_pos_x + HITBOX_MARGIN, game->player->pos_y)
			&& walk(game->map, new_pos_x - HITBOX_MARGIN, game->player->pos_y))
			game->player->pos_x = new_pos_x;
		if (walk(game->map, game->player->pos_x, new_pos_y + HITBOX_MARGIN)
			&& walk(game->map, game->player->pos_x, new_pos_y - HITBOX_MARGIN))
			game->player->pos_y = new_pos_y;
	}
	if (keycode == S_KEY)
	{
		new_pos_x = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
		new_pos_y = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
		if (walk(game->map, new_pos_x + HITBOX_MARGIN, game->player->pos_y)
			&& walk(game->map, new_pos_x - HITBOX_MARGIN, game->player->pos_y))
			game->player->pos_x = new_pos_x;
		if (walk(game->map, game->player->pos_x, new_pos_y + HITBOX_MARGIN)
			&& walk(game->map, game->player->pos_x, new_pos_y - HITBOX_MARGIN))
			game->player->pos_y = new_pos_y;
	}
}

void	move_left_right(t_game *game, int keycode)
{
	double	new_pos_x;
	double	new_pos_y;

	if (keycode == D_KEY)
	{
		new_pos_x = game->player->pos_x - game->player->dir_y * MOVE_SPEED;
		new_pos_y = game->player->pos_y + game->player->dir_x * MOVE_SPEED;
		if (walk(game->map, new_pos_x + HITBOX_MARGIN, game->player->pos_y)
			&& walk(game->map, new_pos_x - HITBOX_MARGIN, game->player->pos_y))
			game->player->pos_x = new_pos_x;
		if (walk(game->map, game->player->pos_x, new_pos_y + HITBOX_MARGIN)
			&& walk(game->map, game->player->pos_x, new_pos_y - HITBOX_MARGIN))
			game->player->pos_y = new_pos_y;
	}
	if (keycode == A_KEY)
	{
		new_pos_x = game->player->pos_x + game->player->dir_y * MOVE_SPEED;
		new_pos_y = game->player->pos_y - game->player->dir_x * MOVE_SPEED;
		if (walk(game->map, new_pos_x + HITBOX_MARGIN, game->player->pos_y)
			&& walk(game->map, new_pos_x - HITBOX_MARGIN, game->player->pos_y))
			game->player->pos_x = new_pos_x;
		if (walk(game->map, game->player->pos_x, new_pos_y + HITBOX_MARGIN)
			&& walk(game->map, game->player->pos_x, new_pos_y - HITBOX_MARGIN))
			game->player->pos_y = new_pos_y;
	}
}

void	rotate_left(t_player *player, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-speed)
		- player->dir_y * sin(-speed);
	player->dir_y = old_dir_x * sin(-speed)
		+ player->dir_y * cos(-speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-speed)
		- player->plane_y * sin(-speed);
	player->plane_y = old_plane_x * sin(-speed)
		+ player->plane_y * cos(-speed);
}

void	rotate_right(t_player *player, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(speed)
		- player->dir_y * sin(speed);
	player->dir_y = old_dir_x * sin(speed)
		+ player->dir_y * cos(speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(speed)
		- player->plane_y * sin(speed);
	player->plane_y = old_plane_x * sin(speed)
		+ player->plane_y * cos(speed);
}
