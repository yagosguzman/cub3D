/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:27:19 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/20 23:20:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_parser(t_game **game, char *map_file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	int		k;

	i = (*game)->map->map_height - 1;
	k = 0;
	j = 0;
	move_cursor(game, &fd, map_file);
	line = get_next_line(fd);
	if (!line)
		ft_error(game, 7, NULL);
	while (line != NULL)
	{
		copy_map_line(game, i, line);
		line = get_next_line(fd);
		i--;
	}
}

static void	create_map_malloc(t_game **game)
{
	int	i;

	i = -1;
	if (!(*game)->map)
		ft_error(game, 5, NULL);
	(*game)->map->w_map
		= (char **)safe_malloc(sizeof(char *) * (*game)->map->map_height);
	while (++i < (*game)->map->map_height)
		(*game)->map->w_map[i]
			= (char *)safe_malloc(sizeof(char) * (*game)->map->map_wide);
}

static int	check_size(char *line)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '\t')
		{
			result += (4 - (result % 4));
		}
		else
			result++;
		i++;
	}
	return (result);
}

void	map_size(t_game **game, int fd, char *line)
{
	int	len;

	while (line != NULL && !ft_strchr(line, '1'))
	{
		(*game)->read += ft_strlen(line);
		ft_free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		init_map(*game);
	while (line != NULL)
	{
		if (!ft_strchr(line, '1'))
			ft_error(game, 4, line);
		len = check_size(line);
		valid_map_char(*game, line);
		if ((*game)->map->map_wide < len)
			(*game)->map->map_wide = len;
		(*game)->map->map_height++;
		ft_free(line);
		line = get_next_line(fd);
	}
	create_map_malloc(game);
}
