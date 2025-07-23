/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:58 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/23 22:25:36 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef SIZE
#  define SIZE 32

#  include <unistd.h>
#  include <stdio.h>
#  include <string.h>
#  include <fcntl.h>
#  include <stdlib.h>
#  include "libft/libft.h"
#  include "./minilibx-linux/mlx_int.h"
#  include "./minilibx-linux/mlx.h"

typedef struct map
{
	char	**map;
	char	**map_copy;
	int		height;
	int		width;
}	t_map;

typedef struct sprites
{
	void	*wall;
	void	*floor;
	void	*box;
	void	*player;
	void	*exit;
}	t_sprites;

//graphics.c
void	win_size(t_map *var_map);
void	run_mlx(t_map *var_map, t_sprites *var_sprites);
//render.c
int		handle_esc(int keycode, void *param);
int		handle_exit(void *param);
void	render_map(void *mlx, void *win, t_map *map, t_sprites *sprites);
//checks.c
int	check_walls(t_map *var_map);
int	validate_map(t_map *var_map);

# endif
#endif