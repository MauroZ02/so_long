/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:40 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/22 21:57:46 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**aux_readmap(int count_line, char **argv, t_map *var_map)
{
	int	fd;
	int	i;

	i = 0;
	var_map->map = ft_calloc(count_line + 1, sizeof(char *));
	var_map->map_copy = ft_calloc(count_line + 1, sizeof(char *));
	if (!var_map->map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL); //hay que liberar la memoria reservada (ft_free)$
	var_map->map[i] = get_next_line(fd);
	while (var_map->map[i])
	{
		i++;
		var_map->map[i] = get_next_line(fd);
		/*if(var_map->map[i][0] == '\n')
		return (NULL);//hay que liberar la memoria reservada*/
	}
	var_map->map_copy = var_map->map;
	return (var_map->map);
}

char	**read_map(char **argv, t_map *var_map)
{
	char	*count_str;
	int		i;
	int		count_line;
	int		fd; //numero de chars que lee read (bytes) por eso -1
	count_line = 0;
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e' && argv[1][i - 3] == 'b'
		&& argv[1][i - 4] == '.' && i > 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (NULL); // si no entra al fd da -1
		count_str = get_next_line(fd); //gnl solo lee primera linea
		while (count_str)
		{
			free(count_str);
			count_str = get_next_line(fd);
			count_line++;
		}
		var_map->map = aux_readmap(count_line, argv, var_map);
		return (var_map->map);
	}
	return (NULL);
}

void	printmap(t_map *var_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (var_map->map_copy[y])
	{
		while (var_map->map_copy[y][x])
		{
			ft_printf("%c", var_map->map_copy[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	ft_printf("\n");
	return ;
}

int	check_walls(t_map *var_map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = 0;
	y = 0;
	width = (int)ft_strlen(var_map->map[y]);
	while (var_map->map[y])
	{
		while (var_map->map[0][x] == '1')
			x++;
		if (var_map->map[0][x] != '1')
			return (0);
		y++;
		if (var_map->map[y][0] != '1' && var_map->map[y][ft_strlen(var_map->map[y]) - 1] != '1')
			return (0);
		x = 0;
		while (var_map->map[height][x] == '1')
			x++;
		if (var_map->map[height][x] != '1')
		return (0);
	}
	return (1);
}

int	validate_map(t_map *var_map)
{
	int		y;
	size_t	gen_len;

	y = 0;
	if (!var_map->map[0])
		return (0);
	gen_len = ft_strlen(var_map->map[0] - 1);
	while (var_map->map[y])
	{
		if (ft_strlen(var_map->map[y] - 1) != gen_len)
			return (0);
		y++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map		*var_map;
	t_sprites	*sprites;

	var_map = ft_calloc(1, sizeof(t_map));
	sprites = ft_calloc(1, sizeof(t_sprites));

	if (argc != 2)
		return (1);
	var_map->map_copy = read_map(argv, var_map);
	if (argc != 2)
		return (1); //como el .ber tiene que ser el primer arg nos percatamos 1º
	if (!validate_map(var_map))
		return (ft_printf("Error validating map\n"));
	if (!check_walls(var_map))
		return (ft_printf("Error checking walls\n"));
	printmap(var_map);
	win_size(var_map);
	run_mlx(var_map, sprites);
	free(var_map);
	free(sprites);
	return (0);
}

// int main(int argc, char **argv)
// {
//     t_map   var_map;
//     int     ret;

//     if (argc != 2)
//         return (1);
//     var_map.map_copy = read_map(argv, &var_map);
//     if (!var_map.map_copy)
//         return (1);
//     win_size(&var_map);                     // compute width/height
//     ret = check_walls(&var_map);            // call it!
//     ft_printf("check_walls returned: %d\n", ret);
//     /* free your map here if you like */
//     return (0);
// }
