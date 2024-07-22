/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:43:03 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/22 22:03:42 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	determine_texture(t_game *game, t_ray *ray, t_draw_params *params)
{
	if (ray->side == 0)
	{
		if (ray->raydirx > 0)
			params->texture = &game->textures[0];
		else
			params->texture = &game->textures[1];
	}
	else
	{
		if (ray->raydiry > 0)
			params->texture = &game->textures[3];
		else
			params->texture = &game->textures[2];
	}
}

void	calculate_texture_coordinates(t_game *game,
				t_ray *ray, t_draw_params *params)
{
	double	wallx;

	if (ray->side == 0)
		wallx = game->player->pos_y + ray->perpwalldist * ray->raydiry;
	else
		wallx = game->player->pos_x + ray->perpwalldist * ray->raydirx;
	wallx -= floor((wallx));
	params->texx = (int)(wallx * (double)params->texture->width);
	if (ray->side == 0 && ray->raydirx < 0)
		params->texx = params->texture->width - params->texx - 1;
	if (ray->side == 1 && ray->raydiry > 0)
		params->texx = params->texture->width - params->texx - 1;
}

void	draw_line(t_game *game, t_draw_params *params)
{
	int	y;
	int	d;
	int	texy;
	int	color;

	y = params->drawstart - 1;
	while (++y < params->drawend)
	{
		d = y * 256 - SCREENHEIGHT * 128 + params->lineheight * 128;
		texy = ((d * params->texture->height) / params->lineheight) / 256;
		// if (texy >= 0 && texy < params->texture->height && params->texx >= 0 && params->texx < params->texture->width)
		// {
			color = params->texture->data[texy * params->texture->width
			+ params->texx];
			game->mlx->data[y * SCREENWIDTH + params->x] = color;
		// }
		
		
	}
}

void	calculate_draw_params(t_ray *ray, t_draw_params *params)
{
	params->lineheight = (int)(SCREENHEIGHT / ray->perpwalldist);
	params->drawstart = -params->lineheight / 2 + SCREENHEIGHT / 2;
	if (params->drawstart < 0)
		params->drawstart = 0;
	params->drawend = params->lineheight / 2 + SCREENHEIGHT / 2;
	if (params->drawend >= SCREENHEIGHT)
		params->drawend = SCREENHEIGHT - 1;
}

void	draw_walls(t_game *game, t_ray *ray, int x)
{
	t_draw_params	params;

	params.x = x;
	determine_texture(game, ray, &params);
	calculate_texture_coordinates(game, ray, &params);
	calculate_draw_params(ray, &params);
	draw_line(game, &params);
}
