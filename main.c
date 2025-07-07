/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:40 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/07 21:05:12 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**aux_readmap(int count_line, char **argv, t_map *var_map)
{
	int	fd;
	int	i;
	int	len;

	i = 0;
	var_map->map = ft_calloc(count_line + 1, sizeof(char *)); //calloc para poner \n y sizeof char * porque es un string
	//var_map->map_copy = ft_calloc(count_line + 1, sizeof(char*));
	if (!var_map->map)
	return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	return (NULL); //hay que liberar la memoria reservada (ft_free)
	var_map->map[i] = get_next_line(fd);
	while ((var_map->map[i] = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(var_map->map[i]);
		if (len > 0 && var_map->map[i][len - 1] == '\n') // si al final de "y" hay un \n
			var_map->map[i][len - 1] = '\0'; // lo convertimos en \0 para que sea mas facil contar las lineas después
		i++;
		//var_map->map[i] = get_next_line(fd);
		/*if(var_map->map[i][0] == '\n')
		return (NULL);//hay que liberar la memoria reservada*/
	}
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

int	validate_map(t_map *var_map)
{
	size_t	gen_len;
	//int	x;
	int	y;

	//x = 0;
	y = 0;
	gen_len = ft_strlen(var_map->map[0]);
	while(var_map->map[y])
	{
		printf("Línea %d tiene largo %zu, se esperaba %zu\n",
		y, ft_strlen(var_map->map[y]), gen_len);

		if (ft_strlen(var_map->map[y]) != gen_len)
			return (0);
		y++;
	}
	return(1);
}

// int	validate_map(t_map *var_map)
// {
// 	int	y;
// 	int	x;
// 	int	len;

// 	x = 0;
// 	y = 0;
// 	len = ft_strlen(var_map->map[x]) - 1;

// 	while (var_map->map[y])
// 	{
// 		while (var_map->map[y][x])
// 		{
// 			while (var_map->map[y][x] == '1') // primer fila todos 1
// 				x++;
// 			x = 0;
// 			y++;
// 			if (var_map->map[y][x] == '1') // segunda fila primer colum 1
// 				x++;
// 			else
// 				return (0);
// 			while (var_map->map[y][x] != '1' && var_map->map[y][i - 1] == '1') // todo diferente a 1 y ultima colum es 1
// 				x++;
// 			x = 0;
// 			y++;
// 			while (var_map->map[i - 1][x] == '1')
// 				x++;
// 		}
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_map *var_map;

	var_map = ft_calloc(1, sizeof(t_map));

	if(argc != 2)
		return(1); //como el .ber tiene que ser el primer arg nos percatamos 1º
	var_map->map_copy = read_map(argv, var_map);
	if (!validate_map(var_map))
		return(printf("Error\n"));
	printmap(var_map);

	return(0);
}