/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:07 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/16 20:15:48 by gpinilla         ###   ########.fr       */
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

void	safe_write(t_game *game, int fd, char c)
{
	if (write(fd, &c, sizeof(c)) < 0)
		ft_error(&game, 3, NULL);
}

void	ft_exit_error(void)
{
	perror(NULL);
	exit(errno);
}

char	*perfect_file(t_game *game, char *file)
{
	char	*new_file;
	int		fd[2];
	char	*line;
	int		i;
	int		space_count;

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
				space_count = 0;
				while (space_count++ < 4)
					safe_write(game, fd[1], ' ');
				i++;
			}
			else
				safe_write(game, fd[1], line[i++]);
		}
		ft_free(line);
		line = get_next_line(fd[0]);
		if (line)
			safe_write(game, fd[1], '\n');
	}
	close(fd[0]);
	close(fd[1]);
	return (new_file);
}
	