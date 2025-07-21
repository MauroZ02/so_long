/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:47:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/21 21:56:49 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_esc(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit (0);
	ft_printf("Key pressed: %d\n", keycode);
	return (0);
}

int	handle_exit(void *param)
{
	(void)param;
	exit (0);
	return (0);
}

void	render_map(void *mlx, void *win, t_map *map, t_sprites *sprites)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map->map_copy[y])
	{
		while (map->map_copy[y][x])
		{
			if (map->map_copy[y][x] == '1')
				mlx_put_image_to_window(mlx, win, sprites->wall, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == '0')
				mlx_put_image_to_window(mlx, win, sprites->floor, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, sprites->player, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, sprites->box, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, sprites->exit, x * SIZE, y * SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}
