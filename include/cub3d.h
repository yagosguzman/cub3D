/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/28 21:22:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Map.h"

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

#define SCREENWIDTH 1200
#define SCREENHEIGHT 1200
#define ESC_PRESS 65307
#define NORTH_PATH "../textures/DALL·E-2024-06-23-14.54.46-NO.xpm"
#define SOUTH_PATH "../textures/DALL·E-2024-06-23-14.54.46-SO.xpm"
#define EAST_PATH "../textures/DALL·E-2024-06-23-14.54.46-ES.xpm"
#define WEST_PATH "../textures/DALL·E-2024-06-23-14.54.46-WS.xpm"

#define ESC_PRESS 65307
typedef struct cub3d
{
	void	*mlx;
	void	*win;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	plane_x;
	double	plane_y;
	double	ray_x;
	double	ray_y;
}	t_mlx;


typedef struct s_map
{
	int		player;
	int		max_wide;
	int		len;
	char	**w_map;
}	t_map;

typedef struct s_textures
{
	char	*path;
	void	*img;
	int		*data;
    int		bpp;
    int		size_line;
    int		endian;

}	t_textures;

typedef struct s_game
{
	t_mlx			*mlx;
	t_textures		textures[4];
	int				floor[3];
	int				ceiling[3];
	int				checklist;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	t_map			*map;
	long long		read;
}				t_game;

/*###### PARSER.C ######*/
// int	assign_texture(t_game *game, int key, char *address);
// int	check_dir(t_game *game, char *line, int key, int i);
// int	check_identifier(t_game *game, char *line);
// int	check_specs(t_game **game, char *map_file);
// int	valid_file(t_game **game, char *file_name);
void	checker_exec(t_game **game, char *argv);

/*###### UTILS.C ######*/
void		*safe_malloc(size_t size);
void		*safe_free(void **ptr);
void		safe_clean_cub3D(t_game *game);
bool	ft_isspace(char c);

/*###### ERROR.C ######*/
void	ft_exit_error(void);
void	ft_error(t_game **game, int errnum, char *to_free);

void	init_textures(t_game *game);
void	init_map(t_game *game);
void	safe_clean_texture(t_game *game);
void	check_rgb_valid(t_game *game, char *address, int key);
char	*perfect_file(t_game *game, char *file);
void	safe_clean_mlx(t_game *game);

void	map_parser(t_game **game, char *map_file);
void	map_copy(t_game **game, int fd, char *line);

void	init_minilibx(t_game *game);
void	game_loop(t_game *game);

int		ft_key_handle(int keysym, t_mlx *s_mlx);
int		ft_close_handler(t_mlx *s_mlx);
#endif