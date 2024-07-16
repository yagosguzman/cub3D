/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:36:41 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/16 17:33:56 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_player(t_game *game)
{
	t_player	*player;
	double		fov;

	fov = 0.66;
	player = (t_player *)safe_malloc(sizeof(t_player));
	player->pos_x = 22.0;
	player->pos_y = 12.0;
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = -dir_y * fov;
	player->plane_y = dir_x * fov;
	game->player = player;
}

void	initialize_map(t_game *game)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)safe_malloc(sizeof(t_map));
	map->map_wide = 24;
	map->map_height = 24;
	map->w_map = (char **)safe_malloc(map->map_wide * sizeof(char *));
	i = -1;
	while (++i < map->map_wide)
	{
		map->w_map[i] = (char *)safe_malloc(map->map_height * sizeof(char));
		j = -1;
		while (++j < map->map_height)
		{
			if (i == 0 || i == map->map_wide - 1 || j == 0
				|| j == map->map_height - 1)
				map->w_map[i][j] = 1;
			else
				map->w_map[i][j] = 0;
		}
	}
	game->map = map;
}

void	initialize_textures(t_game *game)
{
	int			i;
	t_textures	*textures;
	t_mlx		*mlx;

	textures = game->textures;
	mlx = game->mlx;
	textures[0].path = NORTH_PATH;
	textures[1].path = SOUTH_PATH;
	textures[2].path = EAST_PATH;
	textures[3].path = WEST_PATH;
	i = -1;
	while (++i < 4) 
	{
		textures[i].img = mlx_xpm_file_to_image(mlx->mlx, textures[i].path,
				&textures[i].width, &textures[i].height);
		if (!textures[i].img) 
		{
			printf("Error loading texture %d\n", i);
			ft_exit_error(1);
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
			SCREENWIDTH, SCREENHEIGHT, "Raycaster");
	initialize_player(game);
	initialize_map(game);
	initializeTextures(game);
	game->mlx->img = mlx_new_image(game->mlx->mlx,
			SCREENWIDTH, SCREENHEIGHT);
	game->mlx->data = (int *)mlx_get_data_addr(game->mlx->img,
			&game->mlx->bpp, &game->mlx->size_line,
			&game->mlx->endian);
	game->keys = NULL;// Inicializar la lista de teclas a NULL
}
