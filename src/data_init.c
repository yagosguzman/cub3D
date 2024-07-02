/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:19:26 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/02 19:06:55 by ysanchez         ###   ########.fr       */
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

void	init_player(t_game *game)
{
	safe_malloc(sizeof(t_player));
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
