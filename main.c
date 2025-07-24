/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:40 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/24 19:14:44 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(t_map *var_map)
{
	int	x;
	int	y;

	y = 0;
	while (var_map->map_copy[y])
	{
		x = 0;
		while (var_map->map_copy[y][x])
		{
			ft_printf("%c", var_map->map_copy[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	return ;
}

static void free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// int	free_all(t_map *var_map, t_counts var_counts, t_sprites sprites)
// {
// 		free(var_map);
// 		free(sprites);
// 		free(var_counts);
// }

int	main(int argc, char **argv)
{
	t_map		*var_map;
	t_sprites	*sprites;
	t_counts	*var_counts;

	if (argc != 2)
		return (ft_printf("Too few arguments\n"));

	var_map = ft_calloc(1, sizeof(t_map));
	sprites = ft_calloc(1, sizeof(t_sprites));
	var_counts = ft_calloc(1, sizeof(t_counts));
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
	var_counts->P = 0;
	var_counts->C = 0;
	var_counts->E = 0;
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
	printmap(var_map);
	win_size(var_map);
	ft_printf("\nP:%d\n", var_counts->P);
	ft_printf("C:%d\n", var_counts->C);
	ft_printf("E:%d\n", var_counts->E);
	run_mlx(var_map, sprites);
	free_map(var_map->map);
	free_map(var_map->map_copy);
	free(var_map);
	free(sprites);
	return (0);
}
