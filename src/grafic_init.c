/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:00:17 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/25 20:02:38 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	events_init(t_mlx *s_mlx)
{
	mlx_hook(s_mlx->mlx_win, KeyPress, KeyPressMask, ft_key_handle, s_mlx);
	//mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, ft_mouse_handle, s_mlx);
	mlx_hook(s_mlx->mlx_win, DestroyNotify, StructureNotifyMask, ft_close_handler, s_mlx);
}

void	init_minilibx(t_game *game)
{
	game->mlx = (t_mlx *)safe_malloc(sizeof(t_mlx));
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
		ft_error(&game, 8, NULL);
	game->mlx->mlx_win = mlx_new_window(game->mlx->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->mlx->mlx_win)
		ft_error(&game, 8, NULL);
	events_init(game->mlx);
}

void	safe_clean_mlx(t_game *game)
{
	if (game && game->mlx)
	{
		safe_free((void **)&game->mlx->mlx);
		safe_free((void **)&game->mlx->mlx_win);
		safe_free((void **)&game->mlx);
	}
}