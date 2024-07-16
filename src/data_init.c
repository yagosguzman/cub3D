/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:19:26 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/16 19:43:12 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	init_textures(t_game *game)
{
	game->textures[0].path = NULL;
	game->textures[1].path = NULL;
	game->textures[2].path = NULL;
	game->textures[3].path = NULL;
	game->floor[0] = -1;
	game->floor[1] = -1;
	game->floor[2] = -1;
	game->ceiling[0] = -1;
	game->ceiling[1] = -1;
	game->ceiling[2] = -1;
}

void	init_map(t_game *game)
{
	game->map = safe_malloc(sizeof(t_map));
	game->map->map_wide = -1;
	game->map->map_height = 0;
	game->player = NULL;
	game->map->w_map = NULL;
}

void	init_player(t_game *game, char c, int i, int j)
{
	game->player->pos_x = i;
	game->player->pos_y = j;
	if (c == 'N')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
	}
	else if (c == 'S')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
	}
	else if (c == 'W')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
	}
	else if (c == 'E')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
	}
}

void	safe_clean_texture(t_game *game)
{
	if (game && game->textures)
	{
		safe_free((void **)&game->textures[0].path);
		safe_free((void **)&game->textures[1].path);
		safe_free((void **)&game->textures[2].path);
		safe_free((void **)&game->textures[3].path);
		safe_free((void **)&game->textures);
	}
}
