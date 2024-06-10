/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:08:30 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/10 21:25:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_file(t_game *game, char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (file_name[len] != 'b' || file_name[len - 1] != 'u'
		|| file_name[len - 2] != 'c' || file_name[len - 3] != '.' || len < 4)
		return (ft_error(game, 1));
	return (0);
}

int	check_specs(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = "";
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(game, 6));
	line = get_nex_line(fd);
	if (!line)
		return (ft_error(game, 6));
}

int	valid_chars_map(t_game *game)
{

}

int	checker_exec(t_game *game, char *argv)
{
	if (valid_file(game, argv) != 0)
		return (1);
}