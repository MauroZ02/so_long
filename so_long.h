/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:58 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/06 17:08:32 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef SIZE
#  define SIZE 30
#  define MAX_MAP_HEIGHT 200
#  define MAX_MAP_WIDTH 200

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
	char	**map;		//DYNAMIC 	ALLOC
	char	**map_copy;	//DYNAMIC	ALLOC
	int		height;
	int		width;
	int		player_x;
	int		player_y;
}	t_map;

//DYNAMIC ALLOC
typedef struct sprites
{
	void	*wall;
	void	*floor;
	void	*box;
	void	*player;
	void	*exit;
}	t_sprites;

//DYNAMIC ALLOC
typedef struct counts
{
	int	p;
	int	e;
	int	c;
	int	collected;
}	t_counts;

typedef struct game
{
	t_map		*map;		//ALLOC DYNAMIC
	t_sprites	*sprites;	//ALLOC DYNAMIC
	t_counts	*counts;	//ALLOC DYNAMIC
	void		*mlx;		//ALLOC DYNAMIC
	void		*win;		//ALLOC DYNAMIC
	int			player_x;
	int			player_y;
	int			moves;
}	t_game;
//checks.c
int		check_walls(t_map *var_map);
int		check_comp(t_map *var_map, t_counts *var_counts);
int		validate_map(t_map *var_map);
void	flood_fill(t_map *var_map, int x, int y);
int		check_path(t_map *var_map);
//graphics.c
void	win_size(t_map *var_map);
void	run_mlx(t_game *game);
// readmap.c
char	**aux_readmap(int count_line, char **argv, t_map *var_map);
char	**read_map(char **argv, t_map *var_map);
char	**copy_map(char **map);
void	loc_player(t_map *var_map, t_game *game);
int		find_player(t_map *var_map, int *px, int *py);
//render.c
void	clean_up_and_exit(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
int		handle_keys(int keycode, void *param);
int		handle_exit(t_game *game);
void	render_map(t_game *g);
//main.c
void	free_map(char **map);
void	cleanup_game(t_game *g);
int		init_game(int argc, char **argv, t_game *g);

# endif
#endif
