/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:31:58 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/05 22:53:14 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

#endif