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

#include "fractol.h"

/*Mandelbrot and Julia
 Infinite Zoom
 Take command line args to decide which fracta renders
 Take command line to shape Julia (x, y) coordinates
 ESC closes the process with no leaks
 Click on the X window, closes the process with no leaks
 We have two promts:
    ./fractol mandelbrot
    ./fractol julia <real> <i>*/

int main(int argc, char **ar)
{
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
    || argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		//Start Prompt
		fracta_init(&fractal);
		fracta_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		put_str_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}