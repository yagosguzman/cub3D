/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:38:13 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/16 20:35:47 by gpinilla         ###   ########.fr       */
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
		checker_exec(&game, argv[1]);
		game_loop(game);
		safe_clean_cub3D(game);
	}
	return (0);
}
