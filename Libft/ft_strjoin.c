/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:08:37 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:33:42 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Reserva (con malloc(3)) y devuelve una nueva
string, formada por la concatenación de ’s1’ y
’s2’*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	char	*s;

	i = 0;
	len = ft_strlen(s1);
	len = len + ft_strlen(s2);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}

/*
int main(void)
{
	char s1[] = "hola ";
	char s2[] = "Gorka.";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
