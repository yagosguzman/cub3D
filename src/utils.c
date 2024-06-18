/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:07 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/18 18:26:38 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*safe_malloc(t_game *game, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size + 1, sizeof(char));
	if (!ptr)
		return (ft_error(game, 8));
	return (ptr);
}

void	*ft_free(void *ptr)
{
	free(ptr);
	ptr == NULL;
}