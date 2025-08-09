/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:58 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/09 17:10:33 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef SIZE
#  define SIZE 30
#  define MAX_MAP_HEIGHT 200
#  define MAX_MAP_WIDTH 200
/* player keys */
#  define LEFT_ARROW 65361
#  define A_KEY 97
#  define UP_ARROW 65362
#  define W_KEY 119
#  define RIGHT_ARROW 65363
#  define D_KEY 100
#  define DOWN_ARROW 65364
#  define S_KEY 115
/* escape key */
#  define ESC_KEY 65307

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
	int	collected;
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
/* checks.c */
int		check_walls(t_map *var_map);
int		check_comp(t_map *var_map, t_counts *var_counts);
int		validate_map(t_map *var_map);
void	flood_fill(t_map *var_map, int x, int y);
int		check_path(t_map *var_map);
/* game_init.c */
void	free_map(char **map);
void	cleanup_game(t_game *g);
int		structs_alloc(t_game *g);
int		build_map_and_copy(char **argv, t_game *g);
int		validate_and_init(t_game *g);
/* graphics.c */
void	win_size(t_map *var_map);
void	run_mlx(t_game *game);
/* map_reading.c */
char	**aux_readmap(int count_line, char **argv, t_map *var_map);
char	**read_map(char **argv, t_map *var_map);
char	**copy_map(char **map);
void	loc_player(t_map *var_map, t_game *game);
int		find_player(t_map *var_map, int *px, int *py);
/* render.c */
void	clean_up_and_exit(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
int		handle_keys(int keycode, void *param);
int		handle_exit(t_game *game);
void	render_map(t_game *g);
/* main.c */
int		init_game(int argc, char **argv, t_game *g);
int		main(int argc, char **argv);
# endif
#endif