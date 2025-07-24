/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:06:59 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/24 18:58:36 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	join = ft_calloc_gnl(i + j + 1, sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy_gnl(join, (char *)s1, i + 1);
	ft_strlcat_gnl(join, s2, i + j + 1);
	return (join);
}

char	*read_till_nl(int fd, char *rest)
{
	char	*temp_buffer;
	char	*new_rest;
	int		bytes_read;

	temp_buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(rest, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp_buffer), free(rest), NULL);
		if (bytes_read == 0)
		{
			free(temp_buffer);
			return (rest);
		}
		temp_buffer[bytes_read] = '\0';
		new_rest = ft_strjoin_gnl(rest, temp_buffer);
		free(rest);
		rest = new_rest;
	}
	free(temp_buffer);
	return (rest);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc_gnl(i + 2, sizeof(char));
	else
		line = ft_calloc_gnl(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc_gnl((ft_strlen_gnl(buffer) - i + 1), sizeof(char));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_till_nl(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = next_line(buffer);
	return (line);
}

// int main(void)
// {
// 	char *line;
// 	//char *buffer;
// 	int	fd;
// 	int	line_number = 1;

// 	fd = open("./hola.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (printf("Error opening the file\n"));
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("line [%d]: %s", line_number, line);
// 		line_number++;
// 		free(line);
// 	}
// 	close(fd);
// 	// Libera cualquier contenido restante en buffer
// 	//free(buffer);
// 	printf("\nel buffer size es %d\n", BUFFER_SIZE);
// 	return (0);
// }