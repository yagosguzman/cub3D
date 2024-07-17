/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:27:19 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/17 21:07:28 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	valid_map_char(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] != '0' && line[i] != '1' && line[i] != 'N'
				&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
				&& line[i] != '\n') && !ft_isspace(line[i]))
			ft_error(&game, 2, line);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
		{
			if (!game->player)
				game->player = (t_player *)safe_malloc(sizeof(t_player));
			else
				ft_error(&game, 6, line);
		}
		i++;
	}
}

void	tab_to_space(char *w_map, int *j, int *k)
{
	int	nbr_space;
	int	i;

	i = -1;
	nbr_space = 4 - (*j % 4);
	while (++i < nbr_space)
		w_map[(*j)++] = ' ';
	(*k)++;
}

void	map_parser(t_game **game, char *map_file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	int		k;
	char	*buff;

	i = 0;
	k = 0;
	j = 0;
	buff = safe_malloc((*game)->read);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error(game, 7, buff);
	if (read(fd, buff, (*game)->read) < 0)
		ft_error(game, 7, buff);
	ft_free(buff);
	line = get_next_line(fd);
	if (!line)
		ft_error(game, 7, NULL);
	while (line != NULL && line[k])
	{
		while (line[k] && line[k] != '\n')
		{
			if (line[k] == '\t')
				tab_to_space ((*game)->map->w_map[i], &j, &k);
			else if (line[k] == 'N' || line[k] == 'S' || line[k] == 'W'
				|| line[k] == 'E')
			{
				init_player((*game), line[k++], i, j);
				(*game)->map->w_map[i][j++] = '0';
			}
			else
				(*game)->map->w_map[i][j++] = line[k++];
		}
		while (j < (*game)->map->map_wide)
		{
			(*game)->map->w_map[i][j] = ' ';
			j++;
		}
		ft_free(line);
		line = get_next_line(fd);
		i++;
		j = 0;
		k = 0;
	}
}

void	create_map_malloc(t_game **game)
{
	int	i;

	i = -1;
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

	while (!ft_strchr(line, '1'))
	{
		(*game)->read += ft_strlen(line);
		ft_free(line);
		line = get_next_line(fd);
	}
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

void	check_borders(t_game **game,char **map, int last, int len)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[0][++i])
		if (map[0][i] != '1' && map[0][i] != ' ')
			ft_error(game, 4, NULL);
	i = -1;
	while (map[last][++i])
		if (map[last][i] != '1' && map[last][i] != ' ')
			ft_error(game, 4, NULL);
	while (map[++j])
	{
		if ((map[j][0] != ' ' && map[j][0] != '1')
			|| (map[j][len] != ' ' && map[j][len] != '1'))
			ft_error(game, 4, NULL);
	}
}

void	check_closed_map(t_game **game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_borders(game, map, (*game)->map->map_height - 1,
		(*game)->map->map_wide - 1);
	// while (map[i])
	// {
	// 	while (map[i][j])
	// 	{
	// 		if (map[i][j] = '0')
	// 			if (j == 0)
	// 	}
	// }
}
