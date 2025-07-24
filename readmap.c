/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:51:57 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/24 18:39:09 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**aux_readmap(int count_line, char **argv, t_map *var_map)
{
	int		fd;
	int		i;
	char	*line;
	size_t	len;

	i = 0;
	var_map->map = ft_calloc(count_line + 1, sizeof(char *));
	// var_map->map_copy = ft_calloc(count_line + 1, sizeof(char *));
	if (!var_map->map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL); //hay que liberar la memoria reservada (ft_free)$
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if(line[0] == '\n')
			return (NULL);//hay que liberar la memoria reservada
		var_map->map[i++] = line ;
	}
	var_map->map[i] = NULL;
	var_map->map_copy = var_map->map;
	return (var_map->map);
}

char	**read_map(char **argv, t_map *var_map)
{
	char	*count_str;
	int		i;
	int		count_line;
	int		fd; //numero de chars que lee read (bytes) por eso -1
	count_line = 0;
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e' && argv[1][i - 3] == 'b'
		&& argv[1][i - 4] == '.' && i > 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (NULL); // si no entra al fd da -1
		count_str = get_next_line(fd); //gnl solo lee primera linea
		while (count_str)
		{
			free(count_str);
			count_str = get_next_line(fd);
			count_line++;
		}
		var_map->map = aux_readmap(count_line, argv, var_map);
		return (var_map->map);
	}
	return (NULL);
}

char	**copy_map(char **map)
{
	char	**dup;
	int		y;
	int		i;

	y = 0;
	while (map[y])
		y++;
	dup = ft_calloc(y + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < y)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			while (i-- > 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
