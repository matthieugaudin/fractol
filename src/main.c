/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:20:10 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/01 18:48:23 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_env	fractal;

	parsing(argc, argv);
	init_fractal(&fractal, argv);
	draw_fractal(&fractal);
	event_handler(&fractal);
	mlx_loop(fractal.mlx);
	free_data(&fractal);
}
