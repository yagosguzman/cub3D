/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:02:15 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/22 18:05:57 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	valid_map_char(t_game *game, char *line)
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

void	move_cursor(t_game **game, int *fd, char *map_file)
{
	char	*buff;

	buff = safe_malloc((*game)->read);
	*fd = open(map_file, O_RDONLY);
	if (*fd < 0)
		ft_error(game, 7, buff);
	if (read(*fd, buff, (*game)->read) < 0)
		ft_error(game, 7, buff);
	ft_free(buff);
}

void	copy_map_line(t_game **game, int i, char *line)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (line[k] && line[k] != '\n')
	{
		if (line[k] == '\t')
			tab_to_space ((*game)->map->w_map[i], &j, &k);
		else
		{
			if (line[k] == 'N' || line[k] == 'S'
				|| line[k] == 'W' || line[k] == 'E')
				init_player((*game), line[k], i, j);
			(*game)->map->w_map[i][j++] = line[k++];
		}
	}
	while (j < (*game)->map->map_wide)
		(*game)->map->w_map[i][j++] = ' ';
	ft_free(line);
}
