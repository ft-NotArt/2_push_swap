/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 06:53:06 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/16 20:27:51 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_buffer_init(char **buffer, int fd)
{
	int	sz;
	int	i;

	*buffer = malloc(BUFFER_SIZE + 1);
	if (!*buffer)
		return (-1);
	i = -1;
	while (++i != BUFFER_SIZE + 1)
		(*buffer)[i] = 0;
	sz = read(fd, *buffer, BUFFER_SIZE);
	return (sz);
}

char	*ft_gnl_exit(char **buffer, char *line)
{
	free(line);
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_get_line(char **buffer, char *line)
{
	char	*res;
	char	*tmp;
	char	*pos_n;

	pos_n = ft_strchr(*buffer, '\n');
	if (!pos_n)
		pos_n = *buffer + ft_strlen(*buffer) - 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, pos_n + 1, ft_strlen(pos_n + 1) + 1);
	if (ft_strchr(*buffer, '\n'))
		pos_n[1] = '\0';
	res = ft_strjoin(line, *buffer);
	free(line);
	free(*buffer);
	*buffer = tmp;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			sz;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	sz = BUFFER_SIZE;
	if (!buffer)
		sz = ft_buffer_init(&buffer, fd);
	line = ft_strjoin("", "");
	while (!ft_strchr(buffer, '\n') && sz > 0)
	{
		line = ft_get_line(&buffer, line);
		if (!line)
			return (ft_gnl_exit(&buffer, line));
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz >= 0)
			buffer[sz] = '\0';
	}
	if (sz <= 0 && *line == '\0')
		return (ft_gnl_exit(&buffer, line));
	return (ft_get_line(&buffer, line));
}
