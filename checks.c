/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:23:24 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/23 22:28:38 by mzangaro         ###   ########.fr       */
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
	{
		if (var_map->map[0][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (var_map->map[y] != NULL)
	{
		if (var_map->map[y + 1] == NULL)
			break ;
		if (var_map->map[y][0] != '1' || var_map->map[y][width - 1] != '1')
			return (0);
		y++;
	}
	height = y;
	x = 0;
	while (x < width)
	{
		if (var_map->map[height][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	validate_map(t_map *var_map)
{
	int		y;
	size_t	gen_len;

	y = 0;
	if (!var_map->map[0])
		return (0);
	gen_len = ft_strlen(var_map->map[0]);
	while (var_map->map[y])
	{
		if (ft_strlen(var_map->map[y]) != gen_len)
			return (0);
		y++;
	}
	return (1);
}
