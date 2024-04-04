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

#include "fractol.h"

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
    if (s == NULL || fd < 0)
        return ;
    while (s[i] != '\0')
    {
        write(1, s, 1);
        i++;
    }
}
