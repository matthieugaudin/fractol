/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:42:18 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/02 19:37:44 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	scale(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * num / old_max + new_min);
}

void	calc_suit_iteration(t_env *fractal, t_complex *z, t_complex c)
{
	double	tmp_z_a;

	if (fractal->id == 3)
	{
		z->a = fabs(z->a);
		z->b = fabs(z->b);
	}
	tmp_z_a = (z->a * z->a) - (z->b * z->b);
	z->b = 2 * z->a * z->b;
	z->a = tmp_z_a;
	z->a += c.a;
	z->b += c.b;
}

double	ft_atod(char *str)
{
	double	res;
	double	pow;
	int		sign;

	pow = 0.1;
	res = 0.0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str != '.' && ('0' <= *str && *str <= '9'))
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res = res + (pow * (*str++ - '0'));
		pow /= 10;
	}
	return (res * sign);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;
	int		offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		pxl = img->pixel + offset;
		*(unsigned int *)pxl = color;
	}
}
