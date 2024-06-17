/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:08:30 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/17 22:15:33 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	assign_texture(t_game *game, int key, char *address)
{
	if (key == 0 && game->north == NULL)
		game->north = address;
	else if (key == 1 && game->south == NULL)
		game->south = address;
	else if (key == 2 && game->south == NULL)
		game->south = address;
	else if (key == 3 && game->south == NULL)
		game->south = address;
	else if (key == 4 && game->south == NULL)
		game->south = address;
	else if (key == 5 && game->south == NULL)
		game->south = address;
	else
	{
		free(address);
		return (1);
	}
	return (0);
}

static int	check_dir(t_game *game, char *line, int key, int i)
{
	char	*address;
	int		fd;

	while (line[i])
		while (ft_isspace(line[i]))
			i++;
	address = ft_strdup((line[i])); // customiza strdup para que no copie los espacios del final?
	fd = open(address, O_RDONLY);
	if (fd < 0)
	{
		free (address);
		return (1);
	}
	close(fd);
	if (assign_texture(game, key, address) == 1)
		return (1);
	return (0);
}

static int	check_identifier(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		if (check_dir(game, line, 0, 3))
			return (1);
	else if (!ft_strncmp(line, "SO ", 3))
		if (check_dir(game, line, 1, 3))
			return (1);
	else if (!ft_strncmp(line, "WE ", 3))
		if (check_dir(game, line, 2, 3))
			return (1);
	else if (!ft_strncmp(line, "EA ", 3))
		if (check_dir(game, line, 3, 3))
			return (1);
	else if (!ft_strncmp(line, "F ", 2))
		if (check_dir(game, line, 4, 2))
			return (1);
	else if (!ft_strncmp(line, "C ", 2))
		if (check_dir(game, line, 5, 2))
			return (1);
	else
		return (1);
	return (0);
}

static int	check_specs(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = "";
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(game, 7));
	line = get_next_line(fd);
	if (!line)
		return (ft_error(game, 7));
	while (line != NULL)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			line = get_next_line(fd);
			continue ;
		}
		if (check_identifier(game, line) != 0)
			return (ft_error(game, 2));
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	valid_file(t_game *game, char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (file_name[len] != 'b' || file_name[len - 1] != 'u'
		|| file_name[len - 2] != 'c' || file_name[len - 3] != '.' || len < 4)
		return (ft_error(game, 1));
	if (check_specs(game, file_name) != 0)
		return (ft_error(game, 2));
	return (0);
}

int	checker_exec(t_game *game, char *argv)
{
	if (valid_file(game, argv) != 0)
		return (1);
}
