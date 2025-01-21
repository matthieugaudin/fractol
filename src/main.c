/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:20:10 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/21 11:52:07 by mgaudin          ###   ########.fr       */
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
	c.a = scale(x, -2, 2, WIDTH - 1);
	c.b = scale(y, 2, -2, HEIGHT - 1);
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
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->win)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
    fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
										&fractal->img.line_len, &fractal->img.endian);
	fractal->nb_iterations = 500;
}

int	key_handler(int keycode, void *param)
{
	if (keycode == 65307)
		printf("ESC");
	if (keycode == 65361)
        printf("Left Arrow Pressed\n");
    else if (keycode == 65362)
        printf("Up Arrow Pressed\n");
    else if (keycode == 65363)
        printf("Right Arrow Pressed\n");
    else if (keycode == 65364)
        printf("Down Arrow Pressed\n");
}

void	event_handler(t_env *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, key_handler, fractal);
	// mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handler, fractal);
	// mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, window_handler, fractal);
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
	}
	else
		ft_putstr_fd("Error\n", 1);
}
