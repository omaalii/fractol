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
    int		integer_part;
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
	}
	return ((integer_part + fractional_part) * sign);
}