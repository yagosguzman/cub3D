/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:00:17 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/25 18:08:37 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	events_init(t_mlx *s_mlx)
{
	mlx_hook(s_mlx->mlx_win, KeyPress, KeyPressMask, ft_key_handle, s_mlx);
	//mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, ft_mouse_handle, s_mlx);
	mlx_hook(s_mlx->mlx_win, DestroyNotify, StructureNotifyMask, ft_close_handler, s_mlx);
}

t_mlx	*init_minilibx(t_game *game)
{
	t_mlx *s_mlx;

	s_mlx = (t_mlx *)safe_malloc(sizeof(t_mlx));
	s_mlx->mlx = mlx_init();
	if (!s_mlx->mlx)
		ft_error(&game, 8);
	s_mlx->mlx_win = mlx_new_window(s_mlx->mlx, WIDTH, HEIGHT, "cub3D");
	if (!s_mlx->mlx_win)
		ft_error(&game, 8);
	events_init(s_mlx);
	return (s_mlx);
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