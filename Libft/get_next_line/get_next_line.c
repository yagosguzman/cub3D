/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:56:05 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/30 00:12:06 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_line(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (NULL);
}

void	*ft_memset_line(void *s, int c, size_t n)
{
	unsigned char	*sp;

	sp = s;
	while (n-- > 0)
		*sp++ = c;
	return (s);
}

char	*extract_line(char **backup)
{
	char	*line;
	char	*temp_char;
	int		leng_line;
	int		leng_backup;

	if (!*backup)
		return (NULL);
	leng_line = 0;
	while ((*backup)[leng_line])
	{
		leng_line++;
		if ((*backup)[leng_line - 1] == '\n')
			break ;
	}
	leng_backup = ft_strlen_line(*backup) - leng_line;
	line = ft_substr_line(*backup, 0, leng_line);
	if (!line)
		return (NULL);
	temp_char = *backup;
	*backup = ft_substr_line(temp_char, leng_line, leng_backup);
	free(temp_char);
	temp_char = NULL;
	if (!*backup)
		return (ft_free_line(line));
	return (line);
}

char	*find_line(int fd, char *backup)
{
	char	*buff;
	int		read_size;
	char	*temp_char;

	read_size = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free_line(backup));
	while (!(ft_strchr(backup, '\n')) && read_size > 0)
	{
		ft_memset_line(buff, '\0', BUFFER_SIZE + 1);
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
			backup = ft_free_line(backup);
		else if (read_size > 0)
		{
			temp_char = backup;
			backup = ft_strjoin(temp_char, buff);
			ft_free_line(temp_char);
			if (!backup)
				break ;
		}
	}
	ft_free_line(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*backup;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (NULL);
	backup = find_line(fd, backup);
	if (!backup)
		return (NULL);
	line = extract_line(&backup);
	if (!line || *line == '\0')
	{
		ft_free_line(line);
		ft_free_line(backup);
		return (NULL);
	}
	return (line);
}
