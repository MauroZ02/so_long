/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:34:26 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/06 19:18:57 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_size(t_map *var_map)
{
	int	y;

	y = 0;
	var_map->width = (int)ft_strlen(var_map->map[0]);
	while (var_map->map[y])
		y++;
	var_map->height = y;
}

void	run_mlx(t_game *game)
{
	int	tex_w;
	int	tex_h;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * SIZE,
			game->map->height * SIZE, "so_long");
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall_1.xpm",
			&tex_w, &tex_h);
	game->sprites->floor = mlx_xpm_file_to_image(game->mlx,
			"sprites/floor_1.xpm", &tex_w, &tex_h);
	game->sprites->player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_1.xpm", &tex_w, &tex_h);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit_1.xpm",
			&tex_w, &tex_h);
	game->sprites->box = mlx_xpm_file_to_image(game->mlx, "sprites/coin_1.xpm",
			&tex_w, &tex_h);
	render_map(game);
	mlx_key_hook(game->win, handle_keys, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop(game->mlx);
}

// void	run_mlx(t_map *var_map, t_sprites *sprites, t_game *game)
// {
// 	// void	*mlx;
// 	// void	*win;
// 	int		width;
// 	int		height;

// 	width = 0;
// 	height = 0;
// 	game->map = var_map;
// 	game->sprites = sprites;
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, var_map->width * SIZE, var_map->height
//* SIZE, "so_long");
// 	sprites->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall_1.xpm",
// &width, &height);
// 	sprites->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor_1.xpm",
// &width, &height);
// 	sprites->player = mlx_xpm_file_to_image(game->mlx, "sprites/player_1.xpm",
// &width, &height);
// 	sprites->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit_1.xpm",
// &width, &height);
// 	sprites->box = mlx_xpm_file_to_image(game->mlx, "sprites/coin_1.xpm",
// &width, &height);
// 	render_map(game->mlx, game->win, var_map, sprites);
// 	mlx_key_hook(game->win, handle_keys, game); 
// 	mlx_hook(game->win, 17, 0, handle_exit, NULL); 
// 	mlx_loop(game->mlx);
// }