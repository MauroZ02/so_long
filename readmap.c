/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:51:57 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/06 16:23:22 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**aux_readmap(int count_line, char **argv, t_map *var_map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	var_map->map = ft_calloc(count_line + 1, sizeof(char *));
	if (!var_map->map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free(var_map->map), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		var_map->map[i++] = line;
		line = get_next_line(fd);
	}
	if (i == 0)
		return (free(var_map->map), var_map->map = NULL, NULL);
	var_map->map[i] = NULL;
	close(fd);
	return (var_map->map);
}

char	**read_map(char **argv, t_map *var_map)
{
	char	*count_str;
	int		i;
	int		count_line;
	int		fd;

	count_line = 0;
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e' && argv[1][i - 3] == 'b'
		&& argv[1][i - 4] == '.' && i > 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (NULL);
		count_str = get_next_line(fd);
		while (count_str)
		{
			free(count_str);
			count_str = get_next_line(fd);
			count_line++;
		}
		var_map->map = aux_readmap(count_line, argv, var_map);
		get_next_line(-1);
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

void	loc_player(t_map *var_map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (var_map->map[y])
	{
		x = 0;
		while (var_map->map[y][x])
		{
			if (var_map->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	find_player(t_map *var_map, int *px, int *py)
{
	int	x;
	int	y;

	y = 0;
	*px = 0;
	*py = 0;
	while (var_map->map_copy[y])
	{
		x = 0;
		while (var_map->map_copy[y][x])
		{
			if (var_map->map_copy[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// void	print_originalmap(t_map *var_map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (var_map->map[y])
// 	{
// 		x = 0;
// 		while (var_map->map[y][x])
// 		{
// 			//ft_printf("%c", var_map->map[y][x]);
// 			x++;
// 		}
// 		//ft_printf("\n");
// 		y++;
// 	}
// 	return ;
// }