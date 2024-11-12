/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:13:02 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/12 16:52:38 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_leftover(int fd, char *leftover)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!leftover || ((!ft_strchr(leftover, '\n')) && (read_bytes != 0)))
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			if (leftover)
				free(leftover);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		leftover = ft_strjoin(leftover, buffer);
		if (!leftover)
			return (NULL);
	}
	free (buffer);
	return (leftover);
}

static char	*ft_get_line(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftover[i])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_new_leftover(char *leftover)
{
	int		i;
	int		j;
	char	*new_leftover;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free (leftover);
		return (NULL);
	}
	new_leftover = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - i + 1));
	if (!new_leftover)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i])
		new_leftover[j++] = leftover[i++];
	new_leftover[j] = '\0';
	free (leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = ft_read_to_leftover(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_get_line(leftover);
	leftover = ft_new_leftover(leftover);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
//  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c
// get_next_line_utils.c && ./a.out