/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:07 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/24 21:17:39 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size + 1, sizeof(char));
	if (!ptr)
		return (ft_exit_error);
	return (ptr);
}

void	*safe_free(void **ptr)
{
	if (ptr)
	{
		free(ptr[0]);
		ptr[0] = NULL;
	}
	return (NULL);
}

void	ft_exit_error(void)
{
	perror(NULL);
	exit(errno);
}

static int	get_line_len(char *line)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t')
			len += 3;
		len++;
		i++;
	}
	return (len);
}

static char	*copy_line(char *line, int len)
{
	char	*new_line;
	int		i;
	int		j;
	int		space_count;

	i = 0;
	j = 0;
	new_line = (char *)safe_malloc(len);

	while (line[i] != '\0')
	{
		if (line[i] == '\t')
		{
			space_count = -1;
			while (++space_count < 4)
				new_line[j++] = ' ';
			i++;
		}
		new_line[j++] = line[i++];
	}
	return (new_line);
}

char	*perfect_file(char *file)
{
	char	*new_file;
	int		fd[2];
	char	*line;
	char	*new_line;
	int		len;

	new_file = "perfect.cub";
	fd[0] = open(file, O_RDONLY);
	if (fd[0] < 0)
	{
		perror("Problem with get_next_line");
		return (NULL);
	}
	fd[1] = open(new_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[1] < 0)
	{
		close(fd[0]);
		perror(NULL);
		return (NULL);
	}
	line = get_next_line(fd[0]);
	if (!line)
	{
		perror("Problem with get_next_line");
		return (NULL);
	}
	while (line != NULL)
	{
		len = get_line_len(line);
		new_line = copy_line(line, len);
		write(fd[1], new_line, len);
		write(fd[1], "\n", 1);
		ft_free(line);
		ft_free(new_line);
		line = get_next_line(fd[0]);
	}
	close(fd[0]);
	close(fd[1]);
	return (new_file);
}
