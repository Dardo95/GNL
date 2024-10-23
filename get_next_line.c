/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:29:53 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/23 17:45:24 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_keep(int fd, char *buffer, ssize_t bytes_read)
{
	char	*buf;
	char	*newnl;
	int	nl_pos;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return(free(buf), NULL);
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		buf[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (buffer);
}

static char *get_line(char buffer)
{

}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer = read_keep(fd, buffer, bytes_read);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
