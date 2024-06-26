/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:19:26 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/27 19:53:01 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	init_textures(t_game *game)
{
	game->textures = safe_malloc(sizeof(t_textures));
	game->textures->north = NULL;
	game->textures->south = NULL;
	game->textures->west = NULL;
	game->textures->east = NULL;
	game->textures->floor[0] = -1;
	game->textures->floor[1] = -1;
	game->textures->floor[2] = -1;
	game->textures->ceiling[0] = -1;
	game->textures->ceiling[1] = -1;
	game->textures->ceiling[2] = -1;
}

void	init_map(t_game *game)
{
	game->map = safe_malloc(sizeof(t_map));
	game->map->max_len = -1;
	game->map->player = -1;
	game->map->w_map = NULL;
}

void	safe_clean_texture(t_game *game)
{
	if (game && game->textures)
	{
		safe_free((void **)&game->textures->north);
		safe_free((void **)&game->textures->south);
		safe_free((void **)&game->textures->west);
		safe_free((void **)&game->textures->east);
		safe_free((void **)&game->textures);
	}
}
