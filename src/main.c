/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:38:13 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/22 20:23:56 by ysanchez         ###   ########.fr       */
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
		if (checker_exec(&game, argv[1]) == 0)
			printf("TUDO BEM\n");
		else
			printf("OH NO :(\n");
		safe_clean_texture(game);
		safe_free((void **)&game);
	}
	return (0);
}
