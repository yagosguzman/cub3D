/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:58:32 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 19:49:48 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	leng;

	leng = ft_strlen(s);
	while (s[leng] != (char) c)
	{
		if (leng == 0)
			return (0);
		leng--;
	}
	return ((char *)(s + leng));
}
