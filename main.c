/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:40 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/09 15:58:09 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(int argc, char **argv, t_game *g)
{
	if (argc != 2)
	{
		ft_printf("Usage: %s map.ber\n", argv[0]);
		return (0);
	}
	if (!structs_alloc(g))
		return (0);
	if (!build_map_and_copy(argv, g))
		return (0);
	if (!validate_and_init(g))
		return (0);
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
