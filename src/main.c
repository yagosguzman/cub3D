/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:38:13 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/28 19:11:29 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void safe_clean_cub3D(t_game *game)
{
	safe_clean_mlx(game);
	safe_clean_texture(game);
	safe_free((void **)&game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*clean_file;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		init_textures(game);
		init_map(game);
		clean_file = perfect_file(game, argv[1]);
		if (!clean_file)
			ft_error(&game, 7, NULL);
		checker_exec(&game, argv[1]);
		printf("Textures path: %s, %s, %s, %s\nRGB codes:\nF: %i,%i,%i\nC: %i,%i,%i\n", game->textures[0].path, game->textures[1].path, game->textures[2].path, game->textures[3].path, game->floor[0], game->floor[1], game->floor[2], game->ceiling[0], game->ceiling[1], game->ceiling[2]);
		init_minilibx(game);
		game_loop(game);
		safe_clean_cub3D(game);
	}
	return (0);
}
