/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:08:30 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/02 18:03:54 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static void	assign_texture(t_game *game, int key, char *address)
{
	if (!game->textures[key].path)
		game->textures[key].path = address;
	else
		ft_error(&game, 2, address);
	game->checklist++;
}

static int	check_valid_chars(char *address)
{
	int	i;

	i = 0;
	while (address[i])
	{
		if (address[i] == ',' || (address[i] >= '0' && address[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

void	check_rgb_valid(t_game *game, char *address, int key)
{
	int		i;
	int		result;
	char	*aux;

	aux = address;
	i = -1;
	if (check_valid_chars(address))
		ft_error(&game, 9, aux);
	while (address && ++i < 3)
	{
		result = ft_atoi(address);
		if (result < 0 || result > 255)
			ft_error(&game, 9, aux);
		if (key == 4)
			game->floor[i] = result;
		else if (key == 5)
			game->ceiling[i] = result;
		while (*address && *(address++) != ',')
			;
	}
	if (*address != '\0' || *(address - 1) == ',')
		ft_error(&game, 9, aux);
	game->checklist++;
	ft_free(aux);
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
		res[i++] = *(address++);
	return (res);
}
static int	empty_values(t_game *game, int key)
{
	if (key == 4)
	{
		if (game->floor[0] < 0 && game->floor[1] < 0
			&& game->floor[2] < 0)
			return (1);
	}
	else if (key == 5)
	{
		if (game->ceiling[0] < 0 && game->ceiling[1] < 0
			&& game->ceiling[2] < 0)
			return (1);
	}
	return (0);
}

static int	empty_textures(t_game *game)
{
	if (!game->textures[0].path || !game->textures[1].path
		|| !game->textures[2].path || !game->textures[3].path)
		return (1);
	return (0);
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
	if (!ft_strncmp(line, "NO", 2) && ft_isspace(*(line+2))
		&& !game->textures[0].path)
		check_dir(game, line, 0, 3);	
	else if (!ft_strncmp(line, "SO", 2) && ft_isspace(*(line+2))
		&& !game->textures[1].path)
		check_dir(game, line, 1, 3);
	else if (!ft_strncmp(line, "WE", 2) && ft_isspace(*(line+2))
		&& !game->textures[2].path)
		check_dir(game, line, 2, 3);
	else if (!ft_strncmp(line, "EA", 2) && ft_isspace(*(line+2))
		&& !game->textures[3].path)
		check_dir(game, line, 3, 3);
	else if (!ft_strncmp(line, "F", 1) && ft_isspace(*(line+1))
		&& empty_values(game, 4))
		check_dir(game, line, 4, 2);
	else if (!ft_strncmp(line, "C", 1) && ft_isspace(*(line+1))
		&& empty_values(game, 5))
		check_dir(game, line, 5, 2);
	else
		return (1);
	return (0);
}

static void	check_complete(t_game **game)
{
	if (empty_values(*game, 4) || empty_values(*game, 5))
		ft_error(game, 5, NULL);
	if (empty_textures(*game))
		ft_error(game, 5, NULL);
}

static void	check_specs(t_game **game, char *map_file)
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
		{
			//(*game)->read++;
			i++;
		}
		if (line[i] != '\n' && line[i] != '\0' && check_identifier(*game, line) != 0)
			ft_error(game, 2, line);
		(*game)->read += ft_strlen(line);
		ft_free(line);
		i = 0;
		line = get_next_line(fd); // aqui se queda una linea que no se libera al salir del bucle;
	}
	map_size(game, fd, line);
	close(fd);
}

static void	valid_file(t_game **game, char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (file_name[len] != 'b' || file_name[len - 1] != 'u'
		|| file_name[len - 2] != 'c' || file_name[len - 3] != '.' || len < 4)
		ft_error(game, 1, NULL);
}

void	checker_exec(t_game **game, char *file)
{
	valid_file(game, file);
	check_specs(game, file);
	check_complete(game);
}
