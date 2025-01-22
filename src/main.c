/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:20:10 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/22 12:40:48 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_pixel(t_env *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	z.a = 0;
	z.b = 0;
	c.a = scale(x, -2, 2, WIDTH - 1) + fractal->zoom_effect;
	c.b = scale(y, 2, -2, HEIGHT - 1) + fractal->zoom_effect;
	i = 0;
	while (i < fractal->nb_iterations)
	{
		calc_suit_iteration(&z, c);
		if (modulus(z) > 4)
			break ;
		i++;
	}
	if (i == fractal->nb_iterations)
		ft_mlx_pixel_put(&fractal->img, x, y, 0xffffff);
	else
		ft_mlx_pixel_put(&fractal->img, x, y, 0x000099 * i);
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

static void	init_fractal(t_env *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		free_data(fractal);
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->win)
		free_data(fractal);
    fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
		free_data(fractal);
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
										&fractal->img.line_len, &fractal->img.endian);
	fractal->nb_iterations = 42;
	fractal->zoom_effect = 0;
}

int	key_handler(int keycode, t_env *param)
{
	if (keycode == 65307)
	{
		free_data(param);
		exit(0);
	}
	return (0);
}

int	window_handler(t_env *param)
{
	free_data(param);
	exit(0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *param)
{
    if (mousecode == 4)
		param->zoom_effect  += 0.5;
	else if (mousecode == 5)
		param->zoom_effect  -= 0.5;
	draw_fractal(param);
	return (0);
}

void	event_handler(t_env *fractal)
{
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, mouse_handler, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, window_handler, fractal);
}

int main(int argc, char **argv)
{
	t_env	fractal;

	if (!argv[1])
		ft_putstr_fd("Error\n", 1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0 || ft_strcmp(argv[1], "julia") == 0)
	{
		init_fractal(&fractal);
		draw_fractal(&fractal);
		event_handler(&fractal);
		mlx_loop(fractal.mlx);
		free_data(&fractal);
	}
	else
		ft_putstr_fd("Error\n", 1);
}
