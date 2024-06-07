/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:09:53 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:37:08 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Elimina todos los caracteres de la string ’set’
desde el principio y desde el final de ’s1’, hasta
encontrar un caracter no perteneciente a ’set’. La
string resultante se devuelve con una reserva de
malloc(3)*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	len;

	while (ft_strchr(set, *s1) != 0 && *s1)
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]))
		len--;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	ft_memcpy(s, s1, len);
	s[len] = '\0';
	return (s);
}
