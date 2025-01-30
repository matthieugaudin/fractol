/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:56:31 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/30 19:56:50 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_rgb	get_rgb(int color)
{
	t_rgb	c;

	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = color & 0xFF;
	return (c);
}

int	rgb_lerping(int color1, int color2, float t)
{
	t_rgb	c1;
	t_rgb	c2;
	t_rgb	c;

	c1 = get_rgb(color1);
	c2 = get_rgb(color2);
	c.r = c1.r + ((c2.r - c1.r) * t);
	c.g = c1.g + ((c2.g - c1.g) * t);
	c.b = c1.b + ((c2.b - c1.b) * t);
	return ((c.r << 16) | (c.g << 8) | c.b);
}
