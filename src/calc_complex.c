/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:15:03 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/17 15:55:31 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
- Mandelbrot set
- Julia set
- zoom in and zoom out
- beautiful nice-looking color games to feel the depth of fratales
- display an image in the window
- window managment should be runny
- quit the porgram properly with ESC key press
- same with the cros at the top of the window
- use the minilibx images
- implement another fractal
- make sure the zoom effect follows the mouse position
- we can also move arround with the key arrows
- handle color shift
*/

void calc_complex(void)
{
	t_complex_nb	z;
	t_complex_nb	c;
	int				tmp_real;
	int				i;

	z.real = 0;
	z.i = 0;

	c.real = -1;
	c.i = 0;

	i = 0;
	while (i++ < 42)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.i += c.i;
		z.real += c.real;
	}
}
