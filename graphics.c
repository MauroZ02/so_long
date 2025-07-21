/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:34:26 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/16 20:34:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	win_size(t_map *var_map)
// {
// 	size_t	width;
// 	int		y;
// 	int		x;
// 	int		height;

// 	y = 0;
// 	width = ft_strlen(var_map->map[y]);
// 	height;
// }

void	run_mlx(t_map *var_map)
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*floor_img;
	void	*char_img;
	void	*box_img;
	void	*exit_img;
	int		width;
	int		height;

	width = 100;
	height = 100;
	

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 700, "so_long");

	wall_img = mlx_xpm_file_to_image(mlx, "sprites/wall_1.xpm", &width, &height);
	floor_img = mlx_xpm_file_to_image(mlx, "sprites/floor_1.xpm", &width, &height);
	char_img = mlx_xpm_file_to_image(mlx, "sprites/player_1.xpm", &width, &height);
	exit_img = mlx_xpm_file_to_image(mlx, "sprites/exit_1.xpm", &width, &height);
	box_img = mlx_xpm_file_to_image(mlx, "sprites/coin_1.xpm", &width, &height);

	render_map(mlx, win, var_map, wall_img, floor_img, char_img, box_img, exit_img);

	mlx_key_hook(win, handle_esc, NULL); // cuando en al win se toque una tecla llama a handle_esc.
	mlx_hook(win, 17, 0, handle_exit, NULL); //hook dice "cuando ocurra algo llama a: funcion" - cuando en la win se toque la X (17) llama a handle_exit
	mlx_loop(mlx);
	// mlx_put_image_to_window(mlx, win, wall_img, 700, 500);
	// mlx_put_image_to_window(mlx, win, floor_img, 500, 120);
	// mlx_put_image_to_window(mlx, win, char_img, 400, 300);
	// mlx_put_image_to_window(mlx, win, exit_img, 100, 200);
	// mlx_put_image_to_window(mlx, win, box_img, 200, 300);
}