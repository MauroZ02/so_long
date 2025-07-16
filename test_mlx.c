/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:47:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/15 19:00:59 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

int	handle_esc(int keycode, void *param)
{
	if (keycode == 65307)
		exit (0);
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	handle_exit(void *param)
{
	(void)param;
	exit (0);
	return (0);
}

int	main(void)
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

	wall_img = mlx_xpm_file_to_image(mlx, "sprites/tree.xpm", &width, &height);
	floor_img = mlx_xpm_file_to_image(mlx, "sprites/floor.xpm", &width, &height);
	char_img = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &width, &height);
	exit_img = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm", &width, &height);
	box_img = mlx_xpm_file_to_image(mlx, "sprites/box.xpm", &width, &height);

	mlx_key_hook(win, handle_esc, NULL); // cuando en al win se toque una tecla llama a handle_esc.
	mlx_hook(win, 17, 0, handle_exit, NULL); //hook dice "cuando ocurra algo llama a: funcion" - cuando en la win se toque la X (17) llama a handle_exit
	mlx_put_image_to_window(mlx, win, wall_img, 700, 500);
	mlx_put_image_to_window(mlx, win, floor_img, 500, 120);
	mlx_put_image_to_window(mlx, win, char_img, 400, 300);
	mlx_put_image_to_window(mlx, win, exit_img, 100, 200);
	mlx_put_image_to_window(mlx, win, box_img, 200, 300);

	mlx_loop(mlx);
}
