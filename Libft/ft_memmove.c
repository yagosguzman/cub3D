/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:57:05 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:03:42 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destp;
	const unsigned char	*srcp;

	if (dest == src || !n)
		return (dest);
	if (dest > src)
	{
		destp = dest + n;
		srcp = src + n;
		while (n-- > 0)
		{
			*--destp = *--srcp;
		}
	}
	else
	{
		destp = dest;
		srcp = src;
		while (n-- > 0)
		{
			*destp++ = *srcp++;
		}
	}
	return (dest);
}
