/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:37:18 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/14 13:06:20 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_step_and_side_dist(t_game *game, t_ray *ray, t_player *player)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->pos_x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - player->pos_x) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->pos_y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - player->pos_y) * ray->deltadisty;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	t_map	*map;

	map = game->map;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map->w_map[ray->mapx][ray->mapy] > 0)
			ray->hit = 1;
	}
}

void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->mapx - player->pos_x
				+ (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - player->pos_y
				+ (1 - ray->stepy) / 2) / ray->raydiry;
}

void	setup_ray(t_game *game, t_ray *ray, int x)
{
	t_player	*player;

	player = game->player;
	ray->camerax = 2 * x / (double)SCREENWIDTH - 1;
	ray->raydirx = player->dir_x + player->plane_x * ray->camerax;
	ray->raydiry = player->dir_y + player->plane_y * ray->camerax;
	ray->mapx = (int)player->pos_x;
	ray->mapy = (int)player->pos_y;
	if (ray->raydirx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->raydirx);
	if (ray->raydiry == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
}

void	cast_rays(t_game *game)
{
	int			x;
	t_player	*player;
	t_ray		*ray;

	player = game->player;
	clear_screen(game);
	x = -1;
	while (++x < SCREENWIDTH)
	{
		ray = (t_ray *)safe_malloc(sizeof(t_ray));
		setup_ray(game, ray, x);
		calculate_step_and_side_dist(game, ray, player);
		perform_dda(game, ray);
		calculate_wall_distance(ray, player);
		draw_walls(game, ray, x);
		free(ray);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, 
		game->mlx->img, 0, 0);
}
