/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:13:02 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/18 13:13:52 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!line)
	{
		free (leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = ft_new_leftover(leftover);
	return (line);
}

// # include <fcntl.h>
// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc > 1)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf("Error opening file\n");
// 			return (1);
// 		}
// 	}
// 	else
// 	{
// 		fd = 0;
// 		printf("Reading from standard input. Enter text (Ctrl+D to end):\n");
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	if (fd != 0)
// 		close(fd);
// 	return (0);
// }

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42
// get_next_line.c get_next_line_utils.c -o gnl
// ./gnl test.txt
// ./gnl