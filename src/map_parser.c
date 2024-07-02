/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:27:19 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/02 20:05:44 by gpinilla         ###   ########.fr       */
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
				init_player((game));
			else
				ft_error(&game, 6, line);
		}
		i++;
	}
}

void	map_parser(t_game **game, char *map_file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	*buff;

	i = 0;
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
	while (line != NULL && !line[i])
	{
		i = 0;

		ft_free(line);
		line = get_next_line(fd);
	}
}

void	map_size(t_game **game, int fd, char *line)
{
	int	len;
	int	i;

	i = -1;
	while (!ft_strchr(line, '1'))
	{
		(*game)->read += ft_strlen(line);
		ft_free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		len = ft_strlen(line) - 1;
		valid_map_char(*game, line);
		if ((*game)->map->map_wide < len)
			(*game)->map->map_wide = len;
		(*game)->map->map_height++;
		ft_free(line);
		line = get_next_line(fd);
	}
	(*game)->map->w_map = 
		(char **)safe_malloc(sizeof((*game)->map->map_height));
	while (++i < (*game)->map->map_height)
		(*game)->map->w_map[i] = 
			(char *)safe_malloc(sizeof((*game)->map->map_wide));
	printf("Max wide is %i\nMax len is %i\n", (*game)->map->map_wide, (*game)->map->map_height);
}
