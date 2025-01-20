/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:07:37 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/20 11:40:00 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	modulus(t_complex z)
{
	return (z.a * z.a + z.b * z.b);
}

double	scale(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

void	calc_suit_iteration(t_complex *z, t_complex c)
{
	double	tmp_z_a;

	tmp_z_a = (z->a * z->a) - (z->b * z->b);
	z->b = 2 * z->a * z->b;
	z->a = tmp_z_a;
	z->a += c.a;
	z->b += c.b;
}
