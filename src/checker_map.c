/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:54:25 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/18 20:58:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_borders(t_game **game, char **map, int last, int len)
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
	while (--last > 0)
	{
		if ((map[last][0] != ' ' && map[last][0] != '1')
			|| (map[last][len] != ' ' && map[last][len] != '1'))
			ft_error(game, 4, NULL);
	}
}

static inline bool	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E');
}

void	check_closed_map(t_game **game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_borders(game, map, (*game)->map->map_height - 1,
		(*game)->map->map_wide - 1);
	while (map[++i + 1])
	{
		while (map[i][++j + 1])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (!valid_char(map[i][j - 1]) || !valid_char(map[i][j + 1])
					|| !valid_char(map[i - 1][j]) || !valid_char(map[i + 1][j]))
					ft_error(game, 4, NULL);
				if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
					|| map[i][j] == 'E')
					map[i][j] = '0';
			}
		}
		j = 1;
	}
}
