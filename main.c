#include "so_long.h"

char	**aux_readmap(int count_line, char **argv, t_map *var_map)
{
	int	fd;
	int	i;
	
	i = 0;
	var_map->map = ft_calloc(count_line + 1, sizeof(char*));//calloc para poner \n sizeof char * porque es un string
	//var_map->map_copy = ft_calloc(count_line + 1, sizeof(char*));
	if (!var_map->map)
	return (NULL);
	fd = open(argv[1], O_RDONLY);
	if( fd < 0)
	return (NULL); //hay que liberar la memoria reservada (ft_free)
	var_map->map[i] = get_next_line(fd);
	while(var_map->map[i])
	{
		i++;
		var_map->map[i] = get_next_line(fd);
		/*if(var_map->map[i][0] == '\n')
		return (NULL);//hay que liberar la memoria reservada*/
	}
	return(var_map->map);
}

char	**read_map(char** argv, t_map *var_map)
{
	int i;
	int count_line;
	char *count_str;
	int fd; //numero de chars que lee read (bytes) por eso -1
	
	count_line = 0;
	i = ft_strlen(argv[1]);
	if (argv[1][i-1] == 'r' && argv[1][i-2] == 'e' && argv[1][i-3] == 'b' &&
		argv[1][i-4] == '.' && i > 4)
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
		return(var_map->map);
	}
	return (NULL);
}

void printmap(t_map *var_map)
{
    int x;
    int y;
    x = 0;
    y = 0;
    while (var_map->map_copy[y])
    {
        while (var_map->map_copy[y][x])
        {
            printf("%c", var_map->map_copy[y][x]);
            x++;
        }
        x = 0;
        y++;
    }
    printf("\n");
    return ;
}
int main(int argc, char **argv)
{
	t_map *var_map;

	var_map = calloc(1, sizeof(t_map));

	if(argc != 2)
		return(1); //como el .ber tiene que ser el primer arg nos percatamos primero
	var_map->map_copy = read_map(argv, var_map);
	printmap(var_map);
}