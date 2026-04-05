/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:39:24 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 12:32:56 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_ffree(char *stored, char *buffer)
{
	if (buffer)
		free(buffer);
	if (stored)
		free(stored);
	return (NULL);
}

static char	*ft_fill_1(int fd, char *stored, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(stored, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_ffree(stored, buffer));
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		temp = stored;
		stored = ft_strjoin(temp, buffer);
		free(temp);
		if (!stored)
			return (ft_ffree(NULL, buffer));
	}
	free(buffer);
	return (stored);
}

static char	*ft_extract_line(char *stored)
{
	char	*line;
	int		i;

	if (!stored || !stored[0])
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (stored[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
	{
		line[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_trim_storage(char *stored)
{
	char	*new_stored;
	int		i;
	int		j;

	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
		return (ft_ffree(stored, NULL));
	new_stored = malloc(ft_strlen(stored) - i);
	if (!new_stored)
		return (NULL);
	i++;
	j = 0;
	while (stored[i])
		new_stored[j++] = stored[i++];
	new_stored[j] = '\0';
	free(stored);
	return (new_stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stored = ft_fill_1(fd, stored, buffer);
	if (!stored)
		return (NULL);
	line = ft_extract_line(stored);
	stored = ft_trim_storage(stored);
	return (line);
}
