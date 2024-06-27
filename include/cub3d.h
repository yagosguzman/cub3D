/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/27 17:29:20 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <X11/X.h>
# include "../Libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 800
#define ESC_PRESS 65307
#define NORTH_PATH "../textures/DALL·E-2024-06-23-14.54.46-NO.xpm"
#define SOUTH_PATH "../textures/DALL·E-2024-06-23-14.54.46-SO.xpm"
#define EAST_PATH "../textures/DALL·E-2024-06-23-14.54.46-ES.xpm"
#define WEST_PATH "../textures/DALL·E-2024-06-23-14.54.46-WS.xpm"

typedef struct cub3d
{
	void	*mlx;
	void	*mlx_win;
	void	*no_text;
	void	*so_text;
	void	*es_text;
	void	*ws_text;
}	t_mlx;


typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor[3];
	int		ceiling[3];

}	t_textures;

typedef struct s_game
{
	t_mlx			*mlx;
	t_textures		*textures;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}	t_game;

/*###### PARSER.C ######*/
// int	assign_texture(t_game *game, int key, char *address);
// int	check_dir(t_game *game, char *line, int key, int i);
// int	check_identifier(t_game *game, char *line);
// int	check_specs(t_game **game, char *map_file);
// int	valid_file(t_game **game, char *file_name);
void	checker_exec(t_game **game, char *argv);

/*###### UTILS.C ######*/
void	*safe_malloc(size_t size);
void 	*safe_free(void **ptr);
void 	safe_clean_cub3D(t_game *game);
/*###### ERROR.C ######*/
void	ft_exit_error(void);
void	ft_error(t_game **game, int errnum, char *to_free);

void	init_textures(t_game *game);
void	safe_clean_texture(t_game *game);
void	check_rgb_valid(t_game *game, char *address, int key);
char	*perfect_file(char *file);
void	safe_clean_mlx(t_game *game);

void	init_minilibx(t_game *game);
void	game_loop(t_game *game);

int		ft_key_handle(int keysym, t_mlx *s_mlx);
int		ft_close_handler(t_mlx *s_mlx);
#endif