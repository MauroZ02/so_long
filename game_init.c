/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:46:45 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/09 16:54:18 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup_game(t_game *g)
{
	if (g->map)
	{
		free_map(g->map->map);
		free_map(g->map->map_copy);
		free(g->map);
	}
	free(g->sprites);
	free(g->counts);
}

int	structs_alloc(t_game *g)
{
	g->map = ft_calloc(1, sizeof (*g->map));
	g->sprites = ft_calloc(1, sizeof (*g->sprites));
	g->counts = ft_calloc(1, sizeof (*g->counts));
	if (!g->map || !g->sprites || !g->counts)
	{
		perror("Error in allocation\n");
		cleanup_game(g);
		return (0);
	}
	return (1);
}

int	build_map_and_copy(char **argv, t_game *g)
{
	g->map->map = read_map(argv, g->map);
	if (!g->map->map)
	{
		ft_printf("Empty or invalid map\n");
		cleanup_game(g);
		return (0);
	}
	g->map->map_copy = copy_map(g->map->map);
	if (!g->map->map_copy)
	{
		perror("Error copying map\n");
		cleanup_game(g);
		return (0);
	}
	win_size(g->map);
	return (1);
}

int	validate_and_init(t_game *g)
{
	if (!validate_map(g->map) || !check_walls(g->map)
		|| !check_comp(g->map, g->counts) || !check_path(g->map))
	{
		ft_printf("Invalid map\n");
		cleanup_game(g);
		return (0);
	}
	free_map(g->map->map_copy);
	g->map->map_copy = copy_map(g->map->map);
	if (!g->map->map_copy)
	{
		perror("Error copying second map\n");
		cleanup_game(g);
		return (0);
	}
	loc_player(g->map, g);
	g->moves = 0;
	return (1);
}
