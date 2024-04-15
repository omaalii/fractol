/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:23:38 by omaali            #+#    #+#             */
/*   Updated: 2024/03/28 14:26:27 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../mlx/mlx.h"

/*Mandelbrot and Julia
 Infinite Zoom
 Take command line args to decide which fracta renders
 Take command line to shape Julia (x, y) coordinates
 ESC closes the process with no leaks
 Click on the X window, closes the process with no leaks
 We have two promts:
    ./fractol mandelbrot
    ./fractol julia <real> <i>*/

int main(int argc, char **argv)
{
	t_fractal	fractal;

    if (check_error(argc, argv, &fractal) == 1)
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		mlx_loop_hook(fractal.mlx_connection, fractal_render, &fractal);
		mlx_loop(fractal.mlx_connection);//loop listening for event like clicking etc 
	}
	else
	{
		put_str_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}