/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:58 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/16 18:38:09 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef SPRITE_SIZE
# define SPRITE_SIZE 32

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "./minilibx-linux/mlx_int.h"
# include "./minilibx-linux/mlx.h"

typedef struct map
{
	char	**map;
	char	**map_copy;
}	t_map;

void	run_mlx(t_map *var_map);
int	handle_esc(int keycode, void *param);
int	handle_exit(void *param);
void	render_map(void *mlx, void *win, t_map *map, void *wall_img, void *floor_img, void *char_img, void *box_img, void *exit_img);

#endif
# endif