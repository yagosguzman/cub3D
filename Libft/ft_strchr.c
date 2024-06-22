/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:58:32 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/22 17:54:38 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strchr() function returns a pointer to the first 
çoccurrence of the character c in the string s*/

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}
