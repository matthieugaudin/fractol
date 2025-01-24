/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:52:15 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/24 12:36:59 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	add_color_data(t_list **head, int color1, int color2)
{
	t_list 	*color_node;
	int		*colors;
 
	colors = malloc(sizeof(int) * 2); // to protect
	colors[0] = color1;
	colors[1] = color2;
	color_node = ft_lstnew(colors); // to protect
	ft_lstadd_back(head, color_node); // to protect
}

static void	create_color_palette(t_env *fractal)
{
	fractal->color = NULL;
	add_color_data(&fractal->color, 0x121214, 0xffffaa);
	add_color_data(&fractal->color, 0x121214, 0xffffaa); // Sombre vers lumière douce
	add_color_data(&fractal->color, 0x000022, 0x3333ff); // Bleu nuit à bleu vif
	add_color_data(&fractal->color, 0x0a0a0a, 0x444444); // Noir profond à gris acier
	add_color_data(&fractal->color, 0x330000, 0xff0000); // Rouge sombre vers rouge vif
	add_color_data(&fractal->color, 0x661100, 0xff6600); // Brun rougeâtre vers orange feu
	add_color_data(&fractal->color, 0x552200, 0xffff33); // Terre brune vers jaune éclatant
	add_color_data(&fractal->color, 0x001f33, 0x00aaff); // Bleu foncé vers bleu azur
	add_color_data(&fractal->color, 0x003322, 0x33ffaa); // Vert forêt vers vert tropical
	add_color_data(&fractal->color, 0x001122, 0x33ffff); // Bleu nuit vers cyan clair
	add_color_data(&fractal->color, 0x112200, 0x66ff33); // Vert sombre vers vert éclatant
	add_color_data(&fractal->color, 0x331a00, 0xcc6600); // Brun terreux vers orange doux
	add_color_data(&fractal->color, 0x004400, 0x00ff00); // Vert forêt vers vert pur
	add_color_data(&fractal->color, 0x2a0033, 0xff33ff); // Violet profond vers rose vif
	add_color_data(&fractal->color, 0x330044, 0xaa00ff); // Mauve foncé vers violet éclatant
	add_color_data(&fractal->color, 0x110022, 0x5500aa); // Noir-violet vers bleu-violet
	add_color_data(&fractal->color, 0xffcccc, 0xffffcc); // Rose pastel vers jaune pastel
	add_color_data(&fractal->color, 0xccffcc, 0xccffff); // Vert pastel vers cyan pastel
	add_color_data(&fractal->color, 0xffccff, 0xccccff); // Rose pastel vers bleu pastel
	add_color_data(&fractal->color, 0x333333, 0xcccccc); // Gris foncé vers argenté
	add_color_data(&fractal->color, 0x666600, 0xffff00); // Bronze vers doré
	add_color_data(&fractal->color, 0x111111, 0x888888); // Noir métallique vers gris clair
}

static void	init_fractal_data(t_env *fractal)
{
	fractal->zoom = 1;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
	fractal->to_lerp = 1;
	fractal->nb_iterations = 42;
	create_color_palette(fractal);
}

void	init_fractal(t_env *fractal)
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
	init_fractal_data(fractal);
}
