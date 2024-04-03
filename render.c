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
*/
void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         colour;
    
    i = 0;
    //1st iteration
    z.x = 0.0;
    z.y = 0.0;

    //pixel co-ordinated scaled to fit mandelbrot
    c.x = map(x, -2, 2, 0, WIDTH);
    c.y = map(y, 2, -2, 0, HEIGHT);
    //How many times we want to iterate
    //to check if the point escaped
    while(i < fractal->iterations)
    {
        //apply actual z^2 + c
        z = complex_sum(complex_square(z), c);//TODO

        //Has the values escaped??
        if((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            colour = map(i, BLACK, WHITE, 0, fractal->iterations);
            my_pixel_put();//TODO
            return ;
        }
    }
}