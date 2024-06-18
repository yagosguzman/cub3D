/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:08:30 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/18 20:14:04 by ysanchez         ###   ########.fr       */
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
	if (key == 0 && game->textures->north == NULL)
		game->textures->north = address;
	else if (key == 1 && game->textures->south == NULL)
		game->textures->south = address;
	else if (key == 2 && game->textures->west == NULL)
		game->textures->west = address;
	else if (key == 3 && game->textures->east == NULL)
		game->textures->east = address;
	else if (key == 4 && game->textures->floor == NULL)
		game->textures->floor = address;
	else if (key == 5 && game->textures->ceiling == NULL)
		game->textures->ceiling = address;
	else
	{
		free(address);
		return (1);
	}
	return (0);
}

char	*clean_address(char *address)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (address[len] && !ft_isspace(address[len]) && address[len] != '\n')
		len++;
	res = (char *)safe_malloc(len);
	while (i < len)
		res[i++] = (*address)++;
	return (res);
}

static int	check_dir(t_game *game, char *line, int key, int i)
{
	char	*address;
	int		fd;

	while (line[i])
		while (ft_isspace(line[i]))
			i++;
	address = clean_address((&line[i]));
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
	int	result;

	result = 0;
	if (!ft_strncmp(line, "NO ", 3))
		result = check_dir(game, line, 0, 3);
	else if (!ft_strncmp(line, "SO ", 3))
		result = check_dir(game, line, 1, 3);
	else if (!ft_strncmp(line, "WE ", 3))
		result = check_dir(game, line, 2, 3);
	else if (!ft_strncmp(line, "EA ", 3))
		result = check_dir(game, line, 3, 3);
	else if (!ft_strncmp(line, "F ", 2))
		result = check_dir(game, line, 4, 2);
	else if (!ft_strncmp(line, "C ", 2))
		result = check_dir(game, line, 5, 2);
	else
		return (1);
	return (result);
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
	return (0);
}
