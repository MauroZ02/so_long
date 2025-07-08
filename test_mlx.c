/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:47:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/08 19:45:53 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>

int	handle_esc(int keycode, void *param)
{
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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");
	mlx_key_hook(win, handle_esc, NULL); // cuando en al win se toque una tecla llama a handle_esc.
	mlx_hook(win, 17, 0, handle_exit, NULL); //hook dice "cuando ocurra algo llama a: funcion" - cuando en la win se toque la X (17) llama a handle_exit
	mlx_loop(mlx);
}
