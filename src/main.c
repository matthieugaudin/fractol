/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:20:10 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/23 18:39:47 by mgaudin          ###   ########.fr       */
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


void	draw_pixel(t_env *fractal, int x, int y)
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
	color = rgb_lerping(0x121214, 0xffffff, (float)i / fractal->nb_iterations);
	if (i == fractal->nb_iterations)
		ft_mlx_pixel_put(&fractal->img, x, y, 0x121214);
	else
		ft_mlx_pixel_put(&fractal->img, x, y, color);
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
	fractal->zoom = 1;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
}

int	key_handler(int keycode, t_env *param)
{
	if (keycode == 65307)
	{
		free_data(param);
		exit(0);
	}
	else if (keycode == 65361)
		param->x_shift -= 0.3;
	else if (keycode == 65362)
		param->y_shift += 0.3;
	else if (keycode == 65363)
		param->x_shift += 0.3;
	else if (keycode == 65364)
		param->y_shift -= 0.3;
	else if (keycode == 65451)
		param->nb_iterations += 10;
	else if (keycode == 65453 && param->nb_iterations > 12)
		param->nb_iterations -= 10;
	draw_fractal(param);
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
		param->zoom  *= 1.05;
	else if (mousecode == 5)
		param->zoom  *= 0.95;
	draw_fractal(param);
	return (0);
}

void	event_handler(t_env *fractal)
{
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, mouse_handler, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, window_handler, fractal);
}

void	show_helper(void)
{
	ft_putstr_fd("|----------------- How to use fractol-----------------|\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|    ./fractol mandelbrot                             |\n", 1);
	ft_putstr_fd("|    ./fractol julia 0,285 0,013 (or other values)    |\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|-------------- How to use the keyboard --------------|\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|     Scroll to zoom in/out                           |\n", 1);
	ft_putstr_fd("|     Press -> keys the move the view                 |\n", 1);
	ft_putstr_fd("|     Press +/- to modify the precision               |\n", 1);
	ft_putstr_fd("|     Press ESC to close the window                   |\n", 1);
	ft_putstr_fd("|     Click on the cross to close the window          |\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|-----------------------------------------------------|\n", 1);
}

void	parsing(int argc, char **argv)
{
	if (argv[1])
	{
		show_helper();
		exit(0);
	}
	else if (ft_strcmp("mandelbrot", argv[1]) && argc != 2)
	{
		show_helper();
		exit(0);
	}
	else if (ft_strcmp("julia", argv[1]) && argc != 4)
	{
		show_helper();
		exit(0);
	}
}

int main(int argc, char **argv)
{
	t_env	fractal;

	// parsing(argc, argv);
	init_fractal(&fractal);
	draw_fractal(&fractal);
	event_handler(&fractal);
	mlx_loop(fractal.mlx);
	free_data(&fractal);
}
