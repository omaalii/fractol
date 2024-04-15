/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:36:46 by omaali            #+#    #+#             */
/*   Updated: 2024/03/28 17:36:49 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../mlx/mlx.h"

int ft_strncmp(char *s1, char *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}

void put_str_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (s == NULL || fd < 0)
        return ;
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i++;
    }
}

double  atod(char *s)
{
    long	integer_part;
    double	fractional_part;
    double	power;
    int		sign;

	integer_part = 0;
	fractional_part = 0.0;
	power = 1;
    sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s && *s != '.')
		integer_part = (integer_part * 10) + *s++ - '0';
	if (*s == '.')
		s++;
	while (*s)
	{
		power /= 10;
		fractional_part = fractional_part  + (*s - '0') * power;
		s++;
	}
	return ((integer_part + fractional_part) * sign);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	valid_decimal(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!is_digit(*s))
		return (0);
	while (is_digit(*s))
		s++;
	if (*s != '.' && *s != '\0')
		return (0);
	if (*s == '\0')
		return (1);
	s++;
	if (*s == '\0')// if the string ends with '.'
		return (0);
	while (is_digit(*s))
		s++;
	return (*s == '\0');
}

int	check_args(char **argv, t_fractal *fractal)
{
	if (!valid_decimal(argv[2]) || !valid_decimal(argv[3]))
		return (0);
	fractal->julia_x = atod(argv[2]);
	fractal->julia_y = atod(argv[3]);
	if (fractal->julia_x < -2.0 || fractal->julia_x > 2.0
		|| fractal->julia_y < -2.0 || fractal->julia_y > 2.0)
		return (0);
	return (1);
}

int check_error(int argc, char **argv, t_fractal *fractal)
{
	if (argc >= 2)
	{
		if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			return (1);
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			if (argc == 4 && check_args(argv, fractal) == 1)
				return (1);
			return (0);
		}
	}
	return (0);
}