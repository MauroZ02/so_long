/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:47:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/16 20:05:35 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_esc(int keycode, void *param)
{
	(void)param;
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

void	render_map(void *mlx, void *win, t_map *map, void *wall_img, void *floor_img, void *char_img, void *box_img, void *exit_img)
{
	int		y;
	int		x;
	char	c;
	void	*sprites;
	
	y = 0;
	x = 0;
	while (map->map_copy[y])
	{
		while (map->map_copy[y][x])
		{
			c = map->map_copy[y][x];
			sprites = NULL;
			if (c == '1')
				sprites = wall_img;
			else if (c == '0')
				sprites = floor_img;
			else if (c == 'P')
				sprites = char_img;
			else if (c == 'C')
				sprites = box_img;
			else if (c == 'E')
				sprites = exit_img;
			if (sprites)
				mlx_put_image_to_window(mlx, win, sprites, x * SPRITE_SIZE, y * SPRITE_SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}
