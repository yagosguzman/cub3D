/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:09:41 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/24 20:01:02 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_valid_chars(char *address)
{
	int	i;
	int	comma;

	comma = 0;
	i = 0;
	while (address[i])
	{
		if (address[i] == ',')
			comma++;
		if (address[i] == ',' || (address[i] >= '0' && address[i] <= '9'))
			i++;
		else
			return (1);
	}
	if (comma != 2)
		return (1);
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
		res[i++] = *(address++);
	return (res);
}

int	empty_values(t_game *game, int key)
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

int	empty_textures(t_game *game)
{
	if (!game->textures[0].path || !game->textures[1].path
		|| !game->textures[2].path || !game->textures[3].path)
		return (1);
	return (0);
}
