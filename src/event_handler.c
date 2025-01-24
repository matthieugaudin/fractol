/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:43:16 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/24 12:41:34 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	key_handler(int keycode, t_env *param)
{
	printf("%d\n", keycode);
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
	else if (keycode == 65451 || keycode == 61)
		param->nb_iterations += 10;
	else if ((keycode == 65453 || keycode == 45) && param->nb_iterations > 12)
		param->nb_iterations -= 10;
	else if (keycode == 108)
	{
		param->to_lerp = !param->to_lerp;
	}
	else if (keycode == 115)
	{
		if (param->color->next)
			param->color = param->color->next;
	}
	draw_fractal(param);
	return (0);
}

static int	window_handler(t_env *param)
{
	free_data(param);
	exit(0);
}

static int	mouse_handler(int mousecode, int x, int y, t_env *param)
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