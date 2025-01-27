/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:52:15 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/27 14:23:50 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	add_color(t_env *fractal, t_list **head, int color1, int color2)
{
	t_list 	*color_node;
	int		*colors;
 
	colors = malloc(sizeof(int) * 2);
	if (!colors)
		free_data(fractal);
	colors[0] = color1;
	colors[1] = color2;
	color_node = ft_lstnew(colors);
	if (!color_node)
	{
		free(colors);
		free_data(fractal);
	}
	ft_lstadd_back(head, color_node);
	if (color1 == 0x111111 && color2 == 0x888888)
		color_node->next = *head;
}

static void	create_color_palette(t_env *fractal)
{
	fractal->color = NULL;
	add_color(fractal, &fractal->color, 0x000022, 0x3333ff);
	add_color(fractal, &fractal->color, 0x661100, 0xff6600);
	add_color(fractal, &fractal->color, 0x001f33, 0x00aaff);
	add_color(fractal, &fractal->color, 0x003322, 0x33ffaa);
	add_color(fractal, &fractal->color, 0x001122, 0x33ffff);
	add_color(fractal, &fractal->color, 0x112200, 0x66ff33);
	add_color(fractal, &fractal->color, 0x331a00, 0xcc6600);
	add_color(fractal, &fractal->color, 0x2a0033, 0xff33ff);
	add_color(fractal, &fractal->color, 0x110022, 0x5500aa);
	add_color(fractal, &fractal->color, 0xffcccc, 0xffffcc);
	add_color(fractal, &fractal->color, 0xccffcc, 0xccffff);
	add_color(fractal, &fractal->color, 0x111111, 0x888888);
}

static void	set_fractal_id(t_env *fractal, char **argv)
{
	if (!ft_strcmp("mandelbrot", argv[1]))
		fractal->id = 1;
	else if (!ft_strcmp("julia", argv[1]))
		fractal->id = 2;
}

static void	init_fractal_data(t_env *fractal, char **argv)
{
	fractal->zoom = 1;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
	fractal->to_lerp = 1;
	fractal->nb_iterations = 42;
	fractal->argv = argv;
	create_color_palette(fractal);
	set_fractal_id(fractal, argv);
}

void	init_fractal(t_env *fractal, char **argv)
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
	init_fractal_data(fractal, argv);
}
