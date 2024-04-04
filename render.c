/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:36:43 by omaali            #+#    #+#             */
/*   Updated: 2024/04/01 02:36:47 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Put a pixel in my image buffer
static void my_pixel_put(int x, int y, t_img *img, int colour)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    colour = *(unsigned int *)(img->pixel_ptr + offset);
}

/*
                0___________800       -2___________+2
                |            |         |           |
                |            |         |           |
            800 |            |         |           |
                |            |         |           |
                |____________|         |___________|
            MANDELBROT
            z = z^2 + c
            z initially is (0, 0)
            c is the actaul point we want to check

			JULIA
			./fractol julia <real> <i>
			z = pixel_point + constant
			requires converting strings to doubles
*/
static void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex	z;
    t_complex	c;
    int			i;
    int			colour;
    
    i = 0;
    //1st iteration
    z.x = 0.0;
    z.y = 0.0;

    //pixel co-ordinated scaled to fit mandelbrot
    c.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
    //How many times we want to iterate
    //to check if the point escaped
    while (i < fractal->iterations)
	{
		//apply actual z^2 + c
		z = complex_sum(complex_square(z), c);

		//Has the values escaped??
		if((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			colour = map(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, colour);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_CYAN_BLUE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}