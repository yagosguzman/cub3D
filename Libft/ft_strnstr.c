/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:59:50 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 19:50:39 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strnstr() function locates the first occurrence of the null-terminated 
string little in the string big, where not more than len characters are searched.
Characters that appear after a ‘\0’ character are not searched.*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		while (big[i] == little[i] && len - i > 0)
		{
			i++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		i = 0;
		big++;
		len--;
	}
	return (0);
}
