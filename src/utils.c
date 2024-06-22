/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:07 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/22 18:17:39 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size + 1, sizeof(char));
	if (!ptr)
		return (perror);
	return (ptr);
}

void *safe_free(void **ptr)
{
	if (ptr && ptr[0])
	{
		free(ptr[0]);
		ptr[0] = NULL;
	}
	return (NULL);
}
