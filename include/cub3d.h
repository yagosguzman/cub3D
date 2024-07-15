/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/14 13:45:41 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Map.h"

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
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
#define NORTH_PATH "textures/TEXT_NO.xpm"
#define SOUTH_PATH "textures/TEXT_SO.xpm"
#define EAST_PATH "textures/TEXT_EA.xpm"
#define WEST_PATH "textures/TEXT_WE.xpm"
#define MOVE_SPEED 0.01
#define ROT_SPEED 0.005
#define MOUSE_SENSITIVITY 0.004

#define ESC_PRESS 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
    int		bpp;
    int		size_line;
    int		endian;
}	t_mlx;

typedef struct s_ray 
{
    double camerax;
	double raydirx;
	double raydiry;
	int mapx;
	int mapy;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	int stepx;
	int stepy;
	int hit;
	int side;
} 	t_ray;


typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_map
{
	int		player;
	int		map_wide;
	int		map_height;
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
	int		width;
	int		height;
}	t_textures;

typedef struct s_key_node
{
	int keycode;
	int is_pressed;
	struct s_key_node *next;
}	t_key_node;

typedef struct s_draw_params
{
	int x;
	int drawstart;
	int drawend;
	int texx;
	int lineheight;
	t_textures *texture;
}	t_draw_params;

typedef struct s_game
{
	t_mlx			*mlx;
	t_textures		textures[4];
	int				floor[3];
	int				ceiling[3];
	int				checklist;
	t_map			*map;
	t_player		*player;
	t_ray			*ray;
	long long		read;
	t_key_node 		*keys;
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
void	cast_rays(t_game *game);
void 	initialize_game(t_game *game);

int		ft_key_handle(int keysym, t_game *game);
int		ft_close_handler(t_mlx *s_mlx);

void 	initialize_game(t_game *game);
void 	cast_rays(t_game *game);
void 	clear_screen(t_game *game);
void 	calculate_step_and_side_dist(t_game *game, t_ray *ray, t_player *player);
void 	perform_dda(t_game *game, t_ray *ray);
void 	calculate_wall_distance(t_ray *ray, t_player *player);
void 	draw_walls(t_game *game, t_ray *ray, int x);
void 	determine_texture(t_game *game, t_ray *ray, t_textures *texture);
void 	calculate_texture_coordinates(t_game *game, t_ray *ray, t_textures *texture, int *texx);
void 	draw_line(t_game *game, t_textures *texture, int x, int drawstart, int drawend, int texx);
void 	move_forward_backward(t_game *game, int keycode);
void 	move_left_right(t_game *game, int keycode);
void 	rotate_left(t_player *player, double speed);
void 	rotate_right(t_player *player, double speed);
int 	handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int 	handle_mouse(int x, int y, t_game *game);

// Funciones para manejar la lista enlazada de teclas
t_key_node *create_key_node(int keycode);
t_key_node *find_key_node(t_key_node *head, int keycode);
void 		add_key_node(t_key_node **head, int keycode);
void 		set_key_state(t_key_node **head, int keycode, int is_pressed);
int 		get_key_state(t_key_node *head, int keycode);
#endif