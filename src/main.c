/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:38:13 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/25 17:32:06 by gpinilla         ###   ########.fr       */
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

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		init_textures(game);
		if (checker_exec(&game, argv[1]) == 0)
			printf("TUDO BEM\n");
		else
			printf("OH NO :\n");
		game->mlx = init_minilibx(game);
		game_loop(game);
		safe_clean_cub3D(game);
	}
	return (0);
}
