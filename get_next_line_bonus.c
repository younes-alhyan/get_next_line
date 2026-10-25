/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalahian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:29:32 by yalahian          #+#    #+#             */
/*   Updated: 2026/10/25 18:56:48 by yalahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_file(int fd, char *buffer, char **stash)
{
	ssize_t	bytes;
	char	*temp;

	while (!ft_strchr(*stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (0);
		if (bytes == 0)
			return (1);
		buffer[bytes] = '\0';
		temp = ft_strljoin(*stash, buffer, bytes);
		if (!temp)
			return (0);
		free(*stash);
		*stash = temp;
	}
	return (1);
}

int	read_stash(char **stash, char **line)
{
	char	*endl;
	char	*temp;

	if (!*stash || **stash == '\0')
		return (0);
	endl = ft_strchr(*stash, '\n');
	if (!endl)
	{
		*line = ft_strndup(*stash, ft_strlen(*stash));
		if (!*line)
			return (0);
		free(*stash);
		*stash = NULL;
		return (1);
	}
	*line = ft_strndup(*stash, endl - *stash + 1);
	if (!*line)
		return (0);
	temp = ft_strndup(endl + 1, ft_strlen(endl + 1));
	if (!temp)
		return (0);
	free(*stash);
	*stash = temp;
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = NULL;
	if (!read_file(fd, buffer, &stash[fd]) || !read_stash(&stash[fd], &line))
	{
		free(stash[fd]);
		stash[fd] = NULL;
		free(line);
		line = NULL;
	}
	free(buffer);
	return (line);
}
