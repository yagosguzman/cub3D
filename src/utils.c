/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:07 by ysanchez          #+#    #+#             */
/*   Updated: 2024/06/25 19:28:04 by ysanchez         ###   ########.fr       */
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

char	*perfect_file(char *file)
{
	char	*new_file;
	int		fd[2];
	char	*line;
	int		i;

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
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '\t')
			{
				write(fd[1], "    ", 4);
				i++;
			}
			else
				write(fd[1], &line[i++], 1);
		}
		ft_free(line);
		line = get_next_line(fd[0]);
		if (line)
			write(fd[1], "\n", 1);
	}
	close(fd[0]);
	close(fd[1]);
	return (new_file);
}
	