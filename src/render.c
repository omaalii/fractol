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

#include "../includes/fractol.h"
#include "../mlx/mlx.h"

// Put a pixel in my image buffer
 static void my_pixel_put(int x, int y, t_img *img, int colour)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
     *(unsigned int *)(img->pixel_ptr + offset) = colour;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
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
	colour = 0;
    //pixel co-ordinated scaled to fit mandelbrot
    z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_or_julia(&z, &c, fractal);
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
	my_pixel_put(x, y, &fractal->img, WHITE);
}

int	fractal_render(t_fractal *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
			handle_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_connection, f->mlx_window, \
	f->img.img_ptr, 0, 0);
	return (0);
}