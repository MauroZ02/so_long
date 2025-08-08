/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:41:12 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/09 00:42:42 by mzangaro         ###   ########.fr       */
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

int	init_game(int argc, char **argv, t_game *g)
{
	if (argc != 2)
		return (ft_printf("Usage: %s map.ber\n", argv[0]), 0);
	g->map = ft_calloc(1, sizeof (*g->map));
	g->sprites = ft_calloc(1, sizeof (*g->sprites));
	g->counts = ft_calloc(1, sizeof (*g->counts));
	if (!g->map || !g->sprites || !g->counts)
		return (perror("malloc"), cleanup_game(g), 0);
	g->map->map = read_map(argv, g->map);
	if (!g->map->map)
		return (ft_printf("Empty map\n"), cleanup_game(g), 0);
	g->map->map_copy = copy_map(g->map->map);
	if (!g->map->map_copy)
		return (perror("malloc"), cleanup_game(g), 0);
	win_size(g->map);
	if (!validate_map(g->map) || !check_walls(g->map)
		|| !check_comp(g->map, g->counts) || !check_path(g->map))
		return (ft_printf("Invalid map\n"), cleanup_game(g), 0);
	free_map(g->map->map_copy);
	g->map->map_copy = copy_map(g->map->map);
	if (!g->map->map_copy)
		return (perror("malloc"), cleanup_game(g), 0);
	loc_player(g->map, g);
	g->moves = 0;
	return (1);
}
