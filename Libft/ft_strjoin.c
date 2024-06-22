/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:08:37 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/22 17:55:49 by gpinilla         ###   ########.fr       */
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

	if (s1 == NULL)
	{
		s = ft_strdup(s2);
		return (s);
	}
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1 && *s1)
		s[i++] = *s1++;
	while (s2 && *s2)
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
