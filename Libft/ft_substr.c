/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:10:29 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 19:53:58 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Reserva (con malloc(3)) y devuelve una substring de
la string ’s’. La substring empieza desde el índice ’start’ y
tiene una longitud máxima ’len’.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	leng_s;

	leng_s = ft_strlen(s);
	if (leng_s < start)
		return (ft_strdup(""));
	if (leng_s > (len + start))
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((leng_s + 1 - start) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
