/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:50:57 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/24 12:02:16 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;
	int		offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		pxl = img->pixel + offset;
		if (*(unsigned int *)pxl != color)
			*(unsigned int *)pxl = color;
	}
}

static t_rgb	get_rgb(int color)
{
	t_rgb	c;

	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = color & 0xFF;
	return (c);
}

static int	rgb_lerping(int color1, int color2, float t)
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


static void	draw_pixel(t_env *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	z.a = 0;
	z.b = 0;
	c.a = scale(x, -2 + fractal->x_shift, 2 + fractal->x_shift, WIDTH - 1) * fractal->zoom;
	c.b = scale(y, 2 + fractal->y_shift, -2 + fractal->y_shift, HEIGHT - 1) * fractal->zoom;
	i = 0;
	while (i < fractal->nb_iterations)
	{
		calc_suit_iteration(&z, c);
		if ((z.a * z.a + z.b * z.b) > 4)
			break ;
		i++;
	}
	color = rgb_lerping(((int *)fractal->color->content)[0], ((int *)fractal->color->content)[1], (float)i / fractal->nb_iterations);
	if (i == fractal->nb_iterations)
		ft_mlx_pixel_put(&fractal->img, x, y, ((int *)fractal->color->content)[0]);
	else if (fractal->to_lerp)
		ft_mlx_pixel_put(&fractal->img, x, y, color);
	else
		ft_mlx_pixel_put(&fractal->img, x, y, ((int *)fractal->color->content)[1] * i);
}

void	draw_fractal(t_env *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			draw_pixel(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
