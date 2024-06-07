/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:56:21 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/30 00:12:13 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_line(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin_line(char *s1, char *s2)
{
	size_t	len;
	int		i;
	char	*s;

	if (s1 == NULL)
	{
		s = ft_strdup_line(s2);
		return (s);
	}
	i = 0;
	len = ft_strlen_line(s1) + ft_strlen_line(s2);
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

size_t	ft_strlen_line(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr_line(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup_line(char *s)
{
	size_t	slen;
	char	*result;

	slen = 0;
	if (s)
		slen = ft_strlen_line(s);
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
