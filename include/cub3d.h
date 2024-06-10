/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/10 21:14:44 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

typedef struct s_game
{
	void *mlx;
	void *win;
}	t_game;

/*###### PARSER.C ######*/
int	valid_file(t_game *game, char *file_name);
int check_specs(t_game *game, char *map_file);
int	valid_chars_map(t_game *game);
int	checker_exec(t_game *game, char *argv);


#endif	