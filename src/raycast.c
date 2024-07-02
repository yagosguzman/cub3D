/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:34:23 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/02 17:37:48 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void castRays(Player *player, Map *map, int screenWidth, int screenHeight, void *mlx, void *win) {
    for (int x = 0; x < screenWidth; x++) {
        double cameraX = 2 * x / (double)screenWidth - 1;
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        int mapX = (int)player->x;
        int mapY = (int)player->y;

        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player->x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player->y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
        }

        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (map->map[mapX][mapY] > 0) hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
        else           perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

        int textureNum = map->map[mapX][mapY] - 1;
        Texture texture = textures[textureNum];

        double wallX;
        if (side == 0) wallX = player->y + perpWallDist * rayDirY;
        else           wallX = player->x + perpWallDist * rayDirX;
        wallX -= floor((wallX));

        int texX = (int)(wallX * (double)texture.width);
        if (side == 0 && rayDirX > 0) texX = texture.width - texX - 1;
        if (side == 1 && rayDirY < 0) texX = texture.width - texX - 1;

        for (int y = drawStart; y < drawEnd; y++) {
            int d = y * 256 - screenHeight * 128 + lineHeight * 128;
            int texY = ((d * texture.height) / lineHeight) / 256;
            int color = texture.data[texY * texture.width + texX];
            mlx_pixel_put(mlx, win, x, y, color);
        }
    }
}