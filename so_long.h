/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:58 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/25 22:05:33 by mzangaro         ###   ########.fr       */
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
	int		player_x;
	int		player_y;
}	t_map;

typedef struct sprites
{
	void	*wall;
	void	*floor;
	void	*box;
	void	*player;
	void	*exit;
}	t_sprites;


typedef struct counts
{
	int	p;
	int	e;
	int	c;
}	t_counts;

typedef struct game
{
	t_map		*map;
	t_sprites	*sprites;
	t_counts	*counts;
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			moves;
}	t_game;
//checks.c
int		check_walls(t_map *var_map);
int		check_comp(t_map *var_map, t_counts *var_counts);
int		validate_map(t_map *var_map);
int		check_path(t_map *var_map);
void	flood_fill(t_map *var_map, int x, int y);
//graphics.c
void	win_size(t_map *var_map);
void	run_mlx(t_map *var_map, t_sprites *var_sprites);
// readmap.c
char	**read_map(char **argv, t_map *var_map);
char	**aux_readmap(int count_line, char **argv, t_map *var_map);
char	**copy_map(char **map);
void	loc_player(t_map *var_map, t_game *game);
//void	print_originalmap(t_map *var_map);
//render.c
int		handle_keys(int keycode, void *param);
int		handle_exit(void *param);
void	render_map(void *mlx, void *win, t_map *map, t_sprites *sprites);
void	move_player(t_game *game, int new_x, int new_y);

# endif
#endif