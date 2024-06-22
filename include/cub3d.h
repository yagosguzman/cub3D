/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/22 18:23:02 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../Libft/inc/libft.h"
# include "../mlx_linux/mlx.h"


typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;

}	t_textures;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	struct s_textures	*textures;

}	t_game;

/*###### PARSER.C ######*/
// int	assign_texture(t_game *game, int key, char *address);
// int	check_dir(t_game *game, char *line, int key, int i);
// int	check_identifier(t_game *game, char *line);
// int	check_specs(t_game *game, char *map_file);
// int	valid_file(t_game *game, char *file_name);
int		checker_exec(t_game *game, char *argv);

/*###### UTILS.C ######*/
void	*safe_malloc(size_t size);
void 	*safe_free(void **ptr);

/*###### ERROR.C ######*/
int	ft_error(t_game **game, int errnum);




#endif