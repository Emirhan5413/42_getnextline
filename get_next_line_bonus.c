/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:23:39 by eunlu             #+#    #+#             */
/*   Updated: 2024/12/16 04:23:40 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!check_newline(str))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_line(char *str)
{
	int		len;
	char	*line;
	int		is_newline;

	len = 0;
	if (!str[len])
		return (NULL);
	is_newline = check_newline(str);
	while (str[len] && str[len] != '\n')
		++len;
	line = malloc(sizeof(char) * (len + is_newline + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		line[len] = str[len];
		++len;
	}
	if (is_newline)
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*shift_line(char *str)
{
	int		len;
	int		tmp;
	char	*next_line;

	len = 0;
	while (str[len] && str[len] != '\n')
		++len;
	if (!str[len])
		ft_free(str);
	next_line = malloc(sizeof(char) * (ft_strlen(str) - len));
	if (!next_line)
		return (NULL);
	++len;
	tmp = 0;
	while (str[len])
	{
		next_line[tmp] = str[len];
		++len;
		++tmp;
	}
	next_line[tmp] = '\0';
	free(str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = shift_line(str[fd]);
	return (line);
}
