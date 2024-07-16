/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:38:06 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/14 15:28:35 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(t_game *game, int keycode)
{
	t_player	*player;
	t_map		*map;

	player = game->player;
	map = game->map;
	if (keycode == W_KEY)
	{
		if (map->w_map[(int)(player->pos_x + player->dir_x * MOVE_SPEED)]
					[(int)(player->pos_y)] == 0)
			player->pos_x += player->dir_x * MOVE_SPEED;
		if (map->w_map[(int)(player->pos_x)]
					[(int)(player->pos_y + player->dir_y * MOVE_SPEED)] == 0)
			player->pos_y += player->dir_y * MOVE_SPEED;
	}
	if (keycode == S_KEY)
	{
		if (map->w_map[(int)(player->pos_x - player->dir_x * MOVE_SPEED)]
					[(int)(player->pos_y)] == 0)
			player->pos_x -= player->dir_x * MOVE_SPEED;
		if (map->w_map[(int)(player->pos_x)]
					[(int)(player->pos_y - player->dir_y * MOVE_SPEED)] == 0)
			player->pos_y -= player->dir_y * MOVE_SPEED;
	}
}

void	move_left_right(t_game *game, int keycode)
{
	t_player	*player;
	t_map		*map;

	player = game->player;
	map = game->map;
	if (keycode == A_KEY)
	{
		if (map->w_map[(int)(player->pos_x - player->dir_y * MOVE_SPEED)]
					[(int)(player->pos_y)] == 0)
			player->pos_x += -player->dir_y * MOVE_SPEED;
		if (map->w_map[(int)(player->pos_x)]
					[(int)(player->pos_y + player->dir_x * MOVE_SPEED)] == 0)
			player->pos_y += player->dir_x * MOVE_SPEED;
	}
	if (keycode == D_KEY)
	{
		if (map->w_map[(int)(player->pos_x + player->dir_y * MOVE_SPEED)]
					[(int)(player->pos_y)] == 0)
			player->pos_x += player->dir_y * MOVE_SPEED;
		if (map->w_map[(int)(player->pos_x)]
					[(int)(player->pos_y - player->dir_x * MOVE_SPEED)] == 0)
			player->pos_y += -player->dir_x * MOVE_SPEED;
	}
}

void	rotate_left(t_player *player, double speed)
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

void	rotate_right(t_player *player, double speed)
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
