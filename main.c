/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:40 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/27 17:52:32 by mzangaro         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	if (!init_game(argc, argv, &game))
		return (1);
	run_mlx(&game);
	cleanup_game(&game);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_map			*m;
// 	t_sprites		sprites;
// 	t_counts		counts;
// 	t_game			game;

// void	clean_exit(char **map, int filled, char *line, int fd)
// {
// 	int	j;

// 	j = 0;
// 	while (j < filled)
// 		free(map[j++]);
// 	free(map);
// 	free(line);
// 	close(fd);
// }
// 	if (argc != 2)
// 		return (ft_printf("Too few arguments\n"), 1);
// 	m = ft_calloc(1, sizeof (*m));
// 	if (!(m->map = read_map(argv, m)))
// 		return (ft_printf("Error reading map\n"), 1);
// 	m->map_copy = copy_map(m->map);
// 	win_size(m);
// 	if (!validate_map(m) || !check_walls(m) || !check_comp(m, &counts)
// 		|| !check_path(m))
// 		return (ft_printf("Invalid map\n"), free_map(m->map),
// 			free_map(m->map_copy), free(m), 1);
// 	loc_player(m, &game);
// 	game.map = m;
// 	game.sprites = &sprites;
// 	game.counts = &counts;
// 	game.moves = 0;
// 	free_map(m->map_copy);
// 	m->map_copy = copy_map(m->map);
// 	run_mlx(&game);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_map		*var_map;
// 	t_sprites	*sprites;
// 	t_counts	*var_counts;
// 	t_game		*game;
// 	int			y;

// 	y = 0;
// 	if (argc != 2)
// 		return (ft_printf("Too few arguments\n"));
// 	var_map = ft_calloc(1, sizeof(t_map));
// 	sprites = ft_calloc(1, sizeof(t_sprites));
// 	var_counts = ft_calloc(1, sizeof(t_counts));
// 	game = ft_calloc(1, sizeof(t_game));
// 	var_map->map = read_map(argv, var_map);
// 	if (!var_map->map)
// 	{
// 		ft_printf("Error in file\n");
// 		free(var_map);
// 		free(sprites);
// 		free(var_counts);
// 		return (1);
// 	}
// 	while (var_map->map[y])
// 	{
// 		if (var_map->map[y][0] == '\0')
// 			return (0);
// 		y++;
// 	}
// 	var_map->map_copy = copy_map(var_map->map);
// 	win_size(var_map);
// 	if (!validate_map(var_map))
// 	{
// 		ft_printf("Error validating map\n");
// 		free_map(var_map->map);
// 		free_map(var_map->map_copy);
// 		free(var_map);
// 		free(sprites);
// 		free(var_counts);
// 		return (1);
// 	}
// 	if (!check_walls(var_map))
// 	{
// 		ft_printf("Error checking walls\n");
// 		free_map(var_map->map);
// 		free_map(var_map->map_copy);
// 		free(var_map);
// 		free(sprites);
// 		free(var_counts);
// 		return (1);
// 	}
// 	var_counts->p = 0;
// 	var_counts->c = 0;
// 	var_counts->e = 0;
// 	if (!check_comp(var_map, var_counts))
// 	{
// 		ft_printf("Error with any component\n");
// 		free_map(var_map->map);
// 		free_map(var_map->map_copy);
// 		free(var_map);
// 		free(sprites);
// 		free(var_counts);
// 		return (1);
// 	}
// 	if (!check_path(var_map))
// 	{
// 		ft_printf("Error with flood_fill\n");
// 		free_map(var_map->map);
// 		free_map(var_map->map_copy);
// 		free(var_map);
// 		free(sprites);
// 		free(var_counts);
// 		return (1);
// 	}
// 	loc_player(var_map, game);
// 	game->map = var_map;
// 	game->sprites = sprites;
// 	game->counts = var_counts;
// 	game->moves = 0;
// 	free_map(var_map->map_copy);
// 	var_map->map_copy = copy_map(var_map->map);
// 	run_mlx(game);
// 	free_map(var_map->map);
// 	free_map(var_map->map_copy);
// 	free(var_map);
// 	free(sprites);
// 	return (0);
// }
