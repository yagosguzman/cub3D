/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:36:41 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/22 16:40:50 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_player(t_game *game)
{
	double		fov;

	fov = 0.66;
	game->player->plane_x = -game->player->dir_y * fov;
	game->player->plane_y = game->player->dir_x * fov;
}

void	initialize_textures(t_game *game)
{
	int			i;
	t_textures	*textures;
	t_mlx		*mlx;

	textures = game->textures;
	mlx = game->mlx;
	i = -1;
	while (++i < 4)
	{
		textures[i].img = mlx_xpm_file_to_image(mlx->mlx, textures[i].path,
				&textures[i].width, &textures[i].height);
		if (!textures[i].img)
		{
			printf("Error loading texture %d\n", i);
			ft_error(&game, 1, NULL);
		}
		textures[i].data = (int *)mlx_get_data_addr(textures[i].img,
				&textures[i].bpp, &textures[i].size_line,
				&textures[i].endian);
	}
}

void	initialize_game(t_game *game)
{
	game->mlx = (t_mlx *)safe_malloc(sizeof(t_mlx));
	game->mlx->mlx = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->mlx,
			SCREENWIDTH, SCREENHEIGHT, "Cub3D");
	initialize_player(game);
	initialize_textures(game);
	game->mlx->img = mlx_new_image(game->mlx->mlx,
			SCREENWIDTH, SCREENHEIGHT);
	game->mlx->data = (int *)mlx_get_data_addr(game->mlx->img,
			&game->mlx->bpp, &game->mlx->size_line,
			&game->mlx->endian);
	game->keys = NULL;
	game->mouse_control = false;
}
