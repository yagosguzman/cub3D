/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:57:24 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:12:25 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcpy - size-bounded string copying and concatenation
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	leng;

	leng = ft_strlen(src);
	if (leng + 1 < size)
	{
		ft_memcpy(dest, src, leng);
		dest[leng] = '\0';
	}
	else if (size > 0)
	{
		ft_memcpy(dest, src, size);
		dest[size - 1] = '\0';
	}
	return (leng);
}
