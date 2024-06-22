/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:36:28 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/22 17:58:30 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup - duplicate a string
*/

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*result;

	if (s)
		slen = ft_strlen(s);
	else
		slen = 0;
	result = (char *)malloc(sizeof(char) * (slen + 1));
	if (!(result))
		return (0);
	slen = 0;
	while (s[slen])
	{
		result[slen] = s[slen];
		slen++;
	}
	result[slen] = '\0';
	return (result);
}
