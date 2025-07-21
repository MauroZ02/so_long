/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:34:26 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/21 22:21:43 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_size(t_map *var_map)
{
	int	y;

	y = 0;
	var_map->width = (int)ft_strlen(var_map->map[0]) - 1;
	while (var_map->map[y])
		y++;
	var_map->height = y;
}

void	run_mlx(t_map *var_map, t_sprites *sprites)
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;

	width = 0;
	height = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, var_map->width * SIZE, var_map->height * SIZE, "so_long");
	sprites->wall = mlx_xpm_file_to_image(mlx, "sprites/wall_1.xpm", &width, &height);
	sprites->floor = mlx_xpm_file_to_image(mlx, "sprites/floor_1.xpm", &width, &height);
	sprites->player = mlx_xpm_file_to_image(mlx, "sprites/player_1.xpm", &width, &height);
	sprites->exit = mlx_xpm_file_to_image(mlx, "sprites/exit_1.xpm", &width, &height);
	sprites->box = mlx_xpm_file_to_image(mlx, "sprites/coin_1.xpm", &width, &height);
	render_map(mlx, win, var_map, sprites);
	mlx_key_hook(win, handle_esc, NULL); // cuando en la win se toque una tecla llama a handle_esc.
	mlx_hook(win, 17, 0, handle_exit, NULL); //hook dice "cuando ocurra algo llama a: funcion" - cuando en la win se toque la X (17) llama a handle_exit
	mlx_loop(mlx);
}
