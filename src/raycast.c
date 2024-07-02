/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:34:23 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/02 19:28:32 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#include "../include/cub3d.h"

void initializeGame(t_game *game) {
    // Inicializar la estructura de MiniLibX
    game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
    game->mlx->mlx = mlx_init();
    game->mlx->win = mlx_new_window(game->mlx->mlx, SCREENWIDTH, SCREENHEIGHT, "Raycaster");

    // Inicializar el jugador
    game->player = (t_player *)malloc(sizeof(t_player));
    game->player->pos_x = 22.0;
    game->player->pos_y = 12.0;
    game->player->dir_x = -1.0;
    game->player->dir_y = 0.0;
    game->player->plane_x = 0.0;
    game->player->plane_y = 0.66;

    // Inicializar el mapa (ejemplo de 24x24 con paredes alrededor)
    game->map = (t_map *)malloc(sizeof(t_map));
    game->map->map_wide = 24;
    game->map->map_height = 24;
    game->map->w_map = (char **)malloc(game->map->map_wide * sizeof(char *));
    for (int i = 0; i < game->map->map_wide; i++) {
        game->map->w_map[i] = (char *)malloc(game->map->map_height * sizeof(char));
        for (int j = 0; j < game->map->map_height; j++) {
            if (i == 0 || i == game->map->map_wide - 1 || j == 0 || j == game->map->map_height - 1)
                game->map->w_map[i][j] = 1; // Pared
            else
                game->map->w_map[i][j] = 0; // Espacio vacío
        }
    }

    // Inicializar las texturas
    game->textures[0].path = NORTH_PATH;
    game->textures[1].path = SOUTH_PATH;
    game->textures[2].path = EAST_PATH;
    game->textures[3].path = WEST_PATH;
    

    for (int i = 0; i < 4; i++) {
        game->textures[i].height = 500;
        game->textures[i].width = 500;
        game->textures[i].img = mlx_xpm_file_to_image(game->mlx->mlx, game->textures[i].path, &game->textures[i].width, &game->textures[i].height);
        if (!game->textures[i].img) {
            printf("Error loading texture %d\n", i);
            exit(1);
        }
        game->textures[i].data = (int *)mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].size_line, &game->textures[i].endian);
    }
    game->mlx->img = mlx_new_image(game->mlx->mlx, SCREENWIDTH, SCREENHEIGHT);
    game->mlx->data = (int *)mlx_get_data_addr(game->mlx->img, &game->mlx->bpp, &game->mlx->size_line, &game->mlx->endian);
}

void castRays(t_game *game) {
    t_player *player = game->player;
    t_map *map = game->map;
    t_textures *textures = game->textures;
    int screenWidth = SCREENWIDTH;
    int screenHeight = SCREENHEIGHT;

    for (int x = 0; x < screenWidth; x++) {
        double cameraX = 2 * x / (double)screenWidth - 1;
        double rayDirX = player->dir_x + player->plane_x * cameraX;
        double rayDirY = player->dir_y + player->plane_y * cameraX;

        int mapX = (int)player->pos_x;
        int mapY = (int)player->pos_y;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        double sideDistX;
        double sideDistY;
        int stepX, stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player->pos_x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->pos_x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player->pos_y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->pos_y) * deltaDistY;
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
            if (map->w_map[mapX][mapY] > 0) hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - player->pos_x + (1 - stepX) / 2) / rayDirX;
        else           perpWallDist = (mapY - player->pos_y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

        int textureNum = map->w_map[mapX][mapY] - 1;
        t_textures texture = textures[textureNum];

        double wallX;
        if (side == 0) wallX = player->pos_y + perpWallDist * rayDirY;
        else           wallX = player->pos_x + perpWallDist * rayDirX;
        wallX -= floor((wallX));

        int texX = (int)(wallX * (double)texture.width);
        if (side == 0 && rayDirX > 0) texX = texture.width - texX - 1;
        if (side == 1 && rayDirY < 0) texX = texture.width - texX - 1;

        for (int y = drawStart; y < drawEnd; y++) {
            int d = y * 256 - screenHeight * 128 + lineHeight * 128;
            int texY = ((d * texture.height) / lineHeight) / 256;
            int color = texture.data[texY * texture.width + texX];
            game->mlx->data[y * screenWidth + x] = color;
        }
    }

    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
}
