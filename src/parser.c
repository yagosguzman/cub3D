/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:08:30 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/18 21:11:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	assign_texture(t_game *game, int key, char *address)
{
	if (!game->textures[key].path)
		game->textures[key].path = address;
	else
		ft_error(&game, 2, address);
	game->checklist++;
}

static void	check_dir(t_game *game, char *line, int key, int i)
{
	char	*address;
	int		fd;

	while (line [i] && ft_isspace(line[i]))
		i++;
	address = clean_address((&line[i]));
	if (*address == '\0')
		ft_error(&game, 5, address);
	if (key <= 3)
	{
		fd = open(address, O_RDONLY);
		if (fd < 0)
			ft_error(&game, 7, address);
		close(fd);
		assign_texture(game, key, address);
	}
	else
		check_rgb_valid(game, address, key);
}

static int	check_identifier(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO", 2) && ft_isspace(*(line + 2))
		&& !game->textures[0].path)
		check_dir(game, line, 0, 3);
	else if (!ft_strncmp(line, "SO", 2) && ft_isspace(*(line + 2))
		&& !game->textures[1].path)
		check_dir(game, line, 1, 3);
	else if (!ft_strncmp(line, "WE", 2) && ft_isspace(*(line + 2))
		&& !game->textures[2].path)
		check_dir(game, line, 2, 3);
	else if (!ft_strncmp(line, "EA", 2) && ft_isspace(*(line + 2))
		&& !game->textures[3].path)
		check_dir(game, line, 3, 3);
	else if (!ft_strncmp(line, "F", 1) && ft_isspace(*(line + 1))
		&& empty_values(game, 4))
		check_dir(game, line, 4, 2);
	else if (!ft_strncmp(line, "C", 1) && ft_isspace(*(line + 1))
		&& empty_values(game, 5))
		check_dir(game, line, 5, 2);
	else
		return (1);
	return (0);
}

void	check_specs(t_game **game, char *map_file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error(game, 7, NULL);
	line = get_next_line(fd);
	if (!line)
		ft_error(game, 7, NULL);
	while (line != NULL && (*game)->checklist < 6)
	{
		while (line[i] != '\0' && ft_isspace(line[i]))
			i++;
		if (line[i] != '\n' && line[i] != '\0'
			&& check_identifier(*game, line) != 0)
			ft_error(game, 2, line);
		(*game)->read += ft_strlen(line);
		ft_free(line);
		i = 0;
		line = get_next_line(fd);
	}
	map_size(game, fd, line);
	close(fd);
}
