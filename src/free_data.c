/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:07:37 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/24 12:27:33 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	free_data(t_env *fractal)
{
	if (fractal)
	{
		if (fractal->color)
		{
			ft_lstclear(&fractal->color);
		}
		if (fractal->img.img)
		{
			mlx_destroy_image(fractal->mlx, fractal->img.img);
		}
		if (fractal->win)
		{
			mlx_destroy_window(fractal->mlx, fractal->win);
			mlx_destroy_display(fractal->mlx);
		}
		if (fractal->mlx)
		{
			free(fractal->mlx);
		}
	}
	exit(0);
}
