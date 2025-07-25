/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:40 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/25 22:14:47 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	free_all(t_map *var_map, t_counts var_counts, t_sprites sprites)
// {
// 	free(var_map);
// 	free(sprites);
// 	free(var_counts);
// }
static void	free_map(char **map)
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

int	main(int argc, char **argv)
{
	t_map		*var_map;
	t_sprites	*sprites;
	t_counts	*var_counts;
	t_game		*game;

	if (argc != 2)
		return (ft_printf("Too few arguments\n"));
	var_map = ft_calloc(1, sizeof(t_map));
	sprites = ft_calloc(1, sizeof(t_sprites));
	var_counts = ft_calloc(1, sizeof(t_counts));
	game = ft_calloc(1, sizeof(t_game));
	var_map->map = read_map(argv, var_map);
	if (!var_map->map)
	{
		ft_printf("Error in file\n");
		free(var_map);
		free(sprites);
		free(var_counts);
		return (1);
	}
	var_map->map_copy = copy_map(var_map->map);
	win_size(var_map);
	if (!validate_map(var_map))
	{
		ft_printf("Error validating map\n");
		free_map(var_map->map);
		free_map(var_map->map_copy);
		free(var_map);
		free(sprites);
		free(var_counts);
		return (1);
	}
	if (!check_walls(var_map))
	{
		ft_printf("Error checking walls\n");
		free_map(var_map->map);
		free_map(var_map->map_copy);
		free(var_map);
		free(sprites);
		free(var_counts);
		return (1);
	}
	var_counts->p = 0;
	var_counts->c = 0;
	var_counts->e = 0;
	if (!check_comp(var_map, var_counts))
	{
		ft_printf("Error with any component\n");
		free_map(var_map->map);
		free_map(var_map->map_copy);
		free(var_map);
		free(sprites);
		free(var_counts);
		return (1);
	}
	if (!check_path(var_map))
	{
		ft_printf("Error with flood_fill\n");
		free_map(var_map->map);
		free_map(var_map->map_copy);
		free(var_map);
		free(sprites);
		free(var_counts);
		return (1);
	}
	//print_originalmap(var_map);
	// ft_printf("\nP:%d\n", var_counts->p);
	// ft_printf("C:%d\n", var_counts->c);
	// ft_printf("E:%d\n", var_counts->e);
	loc_player(var_map, &game);
	move_player(&game,);
	free_map(var_map->map_copy); // First free the modified one
	var_map->map_copy = copy_map(var_map->map);
	run_mlx(var_map, sprites);
	free_map(var_map->map);
	free_map(var_map->map_copy);
	free(var_map);
	free(sprites);
	return (0);
}
