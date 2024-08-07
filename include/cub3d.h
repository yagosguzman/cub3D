/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/22 18:29:30 by gpinilla         ###   ########.fr       */
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

# define SCREENWIDTH 2000
# define SCREENHEIGHT 1000
# define MOVE_SPEED 0.07
# define ROT_SPEED 0.05
# define MOUSE_SENSITIVITY 0.0004
# define HITBOX_MARGIN 0.1

# define ESC_PRESS 65307
# define SPACE_KEY 32
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

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
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}	t_ray;

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
	int					keycode;
	int					is_pressed;
	struct s_key_node	*next;
}	t_key_node;

typedef struct s_draw_params
{
	int			x;
	int			drawstart;
	int			drawend;
	int			texx;
	int			lineheight;
	t_textures	*texture;
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
	t_key_node		*keys;
	bool			mouse_control;
}				t_game;

/*###### PARSER ######*/
void		valid_file(t_game **game, char *file_name);
void		check_specs(t_game **game, char *map_file);
void		checker_exec(t_game **game, char *file);
void		*safe_malloc(size_t size);
char		*clean_address(char *address);
int			empty_values(t_game *game, int key);
int			empty_textures(t_game *game);
int			check_valid_chars(char *address);
void		*safe_free(void **ptr);
void		safe_clean_cub3d(t_game *game);
bool		ft_isspace(char c);
void		ft_exit_error(void);
void		ft_error(t_game **game, int errnum, char *to_free);
void		init_textures(t_game *game);
void		init_map(t_game *game);
void		init_player(t_game *game, char c, int i, int j);
void		safe_clean_texture(t_game *game);
void		check_rgb_valid(t_game *game, char *address, int key);
void		safe_clean_mlx(t_game *game);
void		check_borders(t_game **game, char **map, int last, int len);
void		check_closed_map(t_game **game, char **map);
void		map_parser(t_game **game, char *map_file);
void		map_copy(t_game **game, int fd, char *line);
void		map_size(t_game **game, int fd, char *line);
void		copy_map_line(t_game **game, int i, char *line);
void		move_cursor(t_game **game, int *fd, char *map_file);
void		tab_to_space(char *w_map, int *j, int *k);
void		valid_map_char(t_game *game, char *line);

/*###### RAYCASTING ######*/
void		game_loop(t_game *game);
void		initialize_game(t_game *game);
void		cast_rays(t_game *game);
void		clear_screen(t_game *game);
void		calculate_step_and_side_dist(t_ray *ray, t_player *player);
void		perform_dda(t_game *game, t_ray *ray);
void		calculate_wall_distance(t_ray *ray, t_player *player);
void		draw_walls(t_game *game, t_ray *ray, int x);
void		determine_texture(t_game *game, t_ray *ray, t_draw_params *params);
void		calculate_texture_coordinates(t_game *game,
				t_ray *ray, t_draw_params *params);
void		draw_line(t_game *game, t_draw_params *params);
void		move_forward_backward(t_game *game, int keycode);
void		move_left_right(t_game *game, int keycode);
void		rotate_left(t_player *player, double speed);
void		rotate_right(t_player *player, double speed);
int			handle_keypress(int keycode, t_game *game);
int			handle_keyrelease(int keycode, t_game *game);
int			handle_mouse(int x, int y, t_game *game);
t_key_node	*create_key_node(int keycode);
t_key_node	*find_key_node(t_key_node *head, int keycode);
void		add_key_node(t_key_node **head, int keycode);
void		set_key_state(t_key_node **head, int keycode, int is_pressed);
int			get_key_state(t_key_node *head, int keycode);
#endif