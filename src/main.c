/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:38:13 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/23 13:19:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		init_textures(game);
		checker_exec(&game, argv[1]);
		printf("Textures path: %s, %s, %s, %s\nRGB codes:\nF: %i,%i,%i\nC: %i,%i,%i\n", game->textures->north, game->textures->south, game->textures->west, game->textures->east, game->textures->floor[0], game->textures->floor[1], game->textures->floor[2], game->textures->ceiling[0], game->textures->ceiling[1], game->textures->ceiling[2]);
		safe_clean_texture(game);
		safe_free((void **)&game);
	}
	return (0);
}
