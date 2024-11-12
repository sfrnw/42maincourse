/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:13:02 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/12 16:44:39 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*leftover[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	leftover[fd] = ft_read_to_leftover(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = ft_get_line(leftover[fd]);
	leftover[fd] = ft_new_leftover(leftover[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	char	*line1;
// 	char	*line2;
// 	int		line_count;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd1 == -1 || fd2 == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	line_count = 1;
// 	while (1)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		if (line1)
// 		{
// 			printf("File 1, line %d: %s\n", line_count, line1);
// 			free(line1);
// 		}
// 		if (line2)
// 		{
// 			printf("File 2, line %d: %s\n", line_count, line2);
// 			free(line2);
// 		}
// 		if (!line1 && !line2)
// 			break ;
// 		line_count++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
// cc -Wall -Wextra -Werror get_next_line_bonus.c  
// get_next_line_utils_bonus.c -o gnl_test && ./gnl_test
