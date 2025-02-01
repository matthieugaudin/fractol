/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:50:57 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/01 18:59:41 by mgaudin          ###   ########.fr       */
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
		*(unsigned int *)pxl = color;
	}
}

static void	draw_mandelbrot(t_env *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	z.a = 0;
	z.b = 0;
	c.a = (scale(x, -2, 2, WIDTH - 1) + fractal->x_shift) * fractal->zoom;
	c.b = (scale(y, 2, -2, HEIGHT - 1) + fractal->y_shift) * fractal->zoom;
	i = 0;
	while (i < fractal->nb_iterations)
	{
		calc_suit_iteration(fractal, &z, c);
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

static void	draw_julia(t_env *fractal, char **argv, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	c.a = ft_atod(argv[2]);
	c.b = ft_atod(argv[3]);
	z.a = (scale(x, -2, 2, WIDTH - 1) + fractal->x_shift) * fractal->zoom;
	z.b = (scale(y, 2, -2, HEIGHT - 1) + fractal->y_shift) * fractal->zoom;
	i = 0;
	while (i < fractal->nb_iterations)
	{
		calc_suit_iteration(fractal, &z, c);
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

static void	draw_burningship(t_env *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	z.a = 0;
	z.b = 0;
	c.a = (scale(x, -2, 2, WIDTH - 1) + fractal->x_shift) * fractal->zoom;
	c.b = (scale(y, -2, 2, HEIGHT - 1) - fractal->y_shift) * fractal->zoom;
	i = 0;
	while (i < fractal->nb_iterations)
	{
		calc_suit_iteration(fractal, &z, c);
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
			if (fractal->id == 1)
				draw_mandelbrot(fractal, x, y);
			else if (fractal->id == 2)
				draw_julia(fractal, fractal->argv, x, y);
			else if (fractal->id == 3)
				draw_burningship(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
