/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:04:16 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/18 22:02:50 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	valid_file(t_game **game, char *file_name)
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
	map_parser(game, file);
	if (!(*game)->player)
		ft_error(game, 5, NULL);
	check_closed_map(game, (*game)->map->w_map);
}
