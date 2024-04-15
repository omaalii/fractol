/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:25:23 by omaali            #+#    #+#             */
/*   Updated: 2024/03/28 17:25:25 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>// For Debugging
# include <stdlib.h>//malloc free
# include <unistd.h>//write
# include "../mlx/mlx.h"
# include "fractol.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
/*we use a square
to make the rendering math easier*/
#define WIDTH 800
#define HEIGHT 800

/* COLOURS
*/
#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF

//Psychedelic Colours
// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red


//KEYS
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_PLUS 24
# define KEY_MINUS 27
/*
 COMPLEX values
 */
typedef struct s_complex
{
    //      real
    double  x;
    //      i
    double  y;
}               t_complex;

/*Image
this is basically a pixels buffer
values from mlx_get_data_addr()
*/
typedef struct  s_img
{
    void    *img_ptr; //pointer to image struct
    char    *pixel_ptr;//points to the actual pixels
    int     bpp;//bytes per pixel
    int     endian;
    int     line_len;
}               t_img;
/*FRACTAL ID:
 MLX stuff
 Image
 Hooks values*/

typedef struct  s_fractal 
{
    char    *name;//Mandelbrot or Julia
    //MLX
    void    *mlx_connection;// mlx_init()
    void    *mlx_window;// mlx_new_window()
    //Image
    t_img   img;
    //Hooks member variable
    double  escape_value;//hypotenuse
    int     iterations;//tied to the image quality
    double  shift_x;
    double  shift_y;
    double  zoom;
    double julia_x;
    double julia_y;
}				t_fractal;                    

// ***** String Utils *****
int		ft_strncmp(char *s1, char *s2, int n);
void	put_str_fd(char *s, int fd);
double  atod(char *s);
int check_error(char *arg);
int	check_more(char *s);

//***** init *****
void    fractal_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);

//***** render *****
int	fractal_render(t_fractal *fractal);

//***** hooks *****
int key_handler(int keysym, t_fractal *fractal);
int	close_handler(t_fractal *fractal);

//***** events *****
int	close_handler(t_fractal *fractal);
int	key_handler(int keysym, t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);

//***** math utils *****
double  map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex   complex_sum(t_complex z1, t_complex z2);
t_complex   complex_square(t_complex z);

#endif
