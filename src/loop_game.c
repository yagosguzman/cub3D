/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:28:01 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/26 20:51:08 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	destroy_win(int keycode, t_mlx *s_mlx)
{
	mlx_destroy_window(s_mlx->mlx, s_mlx->mlx_win);
	return (0);
}

void	game_loop(t_game *game)
{
	void	*img;
	char	*path = "textures/TEXT_NO.xpm";
	int		heigth;
	int		width;

	heigth = HEIGHT;
	width = WIDTH; 
	img = mlx_xpm_file_to_image(game->mlx->mlx, path, &heigth, &width);
	if (!img)
		ft_error(&game, 2, NULL);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_win, img, 0, 0);
	mlx_loop(game->mlx->mlx);
}