/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:57:38 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:40:20 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	leng_src;
	size_t	leng_dest;

	leng_src = ft_strlen(src);
	leng_dest = ft_strlen(dest);
	if (size <= leng_dest)
		return (leng_src + size);
	if (leng_src < size - leng_dest)
	{
		ft_memcpy(dest + leng_dest, src, leng_src);
		dest[leng_dest + leng_src] = '\0';
	}
	else
	{
		ft_memcpy(dest + leng_dest, src, size - leng_dest -1);
		dest[size - 1] = '\0';
	}
	return (leng_src + leng_dest);
}
/*
int	main(void)
{
	char			src[] = "holaassdasd";
	char			dest[] = "adios";
	size_t	n = 5;

	printf("%s \n", dest);
	printf("%s \n", src);
	printf("%lu \n", ft_strlcat(dest, src, n));
	printf("%u \n", strlcat(dest, src, n));
	printf("%s \n", dest);
	return (0);
}*/