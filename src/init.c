/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:08:13 by omaali            #+#    #+#             */
/*   Updated: 2024/04/01 01:08:15 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../mlx/mlx.h"

static void	malloc_error(void)
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}
void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;// 2^2 my hypotenuse
	fractal->iterations = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;//to multiply it when zooming in/out
}
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 02, 0, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, close_handler,	fractal);
}

void    fractal_init(t_fractal *f)
{
    f->mlx_connection = mlx_init();
    if (f->mlx_connection == NULL)
        malloc_error();
     f->mlx_window = mlx_new_window(f->mlx_connection, WIDTH, HEIGHT, f->name);
	 f->img.img_ptr = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	 f->img.pixel_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, \
	 &f->img.line_len, &f->img.endian);
	events_init(f);
	data_init(f);
}