/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:23:24 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/27 17:08:19 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *var_map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = (int)ft_strlen(var_map->map[0]);
	x = 0;
	while (x < width)
		if (var_map->map[0][x++] != '1')
			return (0);
	y = 1;
	while (var_map->map[y] != NULL)
	{
		if (var_map->map[y + 1] == NULL)
			break ;
		if (var_map->map[y][0] != '1' || var_map->map[y++][width - 1] != '1')
			return (0);
	}
	height = y;
	x = 0;
	while (x < width)
		if (var_map->map[height][x++] != '1')
			return (0);
	return (1);
}

int	check_comp(t_map *var_map, t_counts *var_counts)
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
				var_counts->p++;
			else if (var_map->map[y][x] == 'C')
				var_counts->c++;
			else if (var_map->map[y][x] == 'E')
				var_counts->e++;
			else if (var_map->map[y][x] != '1' && var_map->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	if (var_counts->p != 1 || var_counts->e != 1 || var_counts->c < 1)
		return (0);
	return (1);
}

int	validate_map(t_map *var_map)
{
	int		y;
	size_t	gen_len;

	y = 0;
	if (!var_map->map[0] || !var_map->map)
		return (0);
	gen_len = ft_strlen(var_map->map[0]);
	while (var_map->map[y])
	{
		if (ft_strlen(var_map->map[y]) != gen_len)
			return (0);
		y++;
	}
	if (y < 5 || gen_len < 3)
		return (0);
	if (y > MAX_MAP_HEIGHT || gen_len > MAX_MAP_WIDTH)
		return (0);
	return (1);
}

void	flood_fill(t_map *var_map, int x, int y)
{
	if (x < 0 || x >= var_map->width || y < 0 || y >= var_map->height)
		return ;
	if (var_map->map_copy[y][x] == '1' || var_map->map_copy[y][x] == 'X')
		return ;
	var_map->map_copy[y][x] = 'X';
	flood_fill(var_map, x + 1, y);
	flood_fill(var_map, x - 1, y);
	flood_fill(var_map, x, y - 1);
	flood_fill(var_map, x, y + 1);
}

int	check_path(t_map *var_map)
{
	int	px;
	int	py;
	int	x;
	int	y;

	if (!find_player(var_map, &px, &py))
		return (0);
	flood_fill(var_map, px, py);
	y = 0;
	while (var_map->map_copy[y])
	{
		x = 0;
		while (var_map->map_copy[y][x])
		{
			if (var_map->map_copy[y][x] == 'C'
				|| var_map->map_copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// int	check_path(t_map *var_map)
// {
// 	int	y;
// 	int	x;
// 	int	py;
// 	int	px;

// 	y = 0;
// 	py = -1;
// 	px = -1;
// 	while (var_map->map_copy[y])
// 	{
// 		x = 0;
// 		while (var_map->map_copy[y][x])
// 		{
// 			if (var_map->map_copy[y][x] == 'P')
// 			{
// 				px = x;
// 				py = y;
// 				break ;
// 			}
// 			x++;
// 		}
// 		if (px >= 0)
// 			break ;
// 		y++;
// 	}
// 	if (px < 0 || py < 0)
// 		return (0);
// 	flood_fill(var_map, px, py);
// 	y = 0;
// 	while (var_map->map_copy[y])
// 	{
// 		x = 0;
// 		while (var_map->map_copy[y][x])
// 		{
// 			if (var_map->map_copy[y][x] == 'C'
// 			|| var_map->map_copy[y][x++] == 'E')
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }

// int	check_path(t_map *var_map)
// {
// 	int	y;
// 	int	x;
// 	int	py;
// 	int	px;

// 	y = -1;
// 	py = -1;
// 	px = -1;
// 	while (var_map->map_copy[++y])
// 	{
// 		x = -1;
// 		while (var_map->map_copy[y][++x])
// 			if (var_map->map_copy[y][x] == 'P')
// 			{
// 				px = x;
// 				py = y;
// 				break ;
// 			}
// 		if (px >= 0)
// 			break ;
// 	}
// 	if (px < 0 || py < 0)
// 		return (0);
// 	flood_fill(var_map, px, py);
// 	y = -1;
// 	while (var_map->map_copy[++y])
// 	{
// 		x = -1;
// 		while (var_map->map_copy[y][++x])
// 			if (var_map->map_copy[y][x] == 'C'
// 			|| var_map->map_copy[y][x++] == 'E')
// 				return (0);
// 	}
// 	return (1);
// }
