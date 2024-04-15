/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:57 by omaali            #+#    #+#             */
/*   Updated: 2024/04/04 00:03:58 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../mlx/mlx.h"

//In case of ESC or pressing x in the window
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
					fractal->img.img_ptr);
	mlx_clear_window(fractal->mlx_connection,
						fractal->mlx_window);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_ESC)
		close_handler(fractal);
	else if (keysym == KEY_LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);//To scale the shift proportionately to the zoom
	else if (keysym == KEY_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == KEY_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == KEY_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
    else if (keysym == KEY_PLUS)//+ sign MORE ITERATIONS
		fractal->iterations += 5;
	else if (keysym == KEY_MINUS)
		fractal->iterations -= 5;
    //refresh the image after the event
    fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)//Zooming IN
		fractal->zoom *= 0.90;
	else if (button == 4)//Zooming OUT
		fractal->zoom *= 1.1;
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	//refresh
	fractal_render(fractal);
	return (0);
}
