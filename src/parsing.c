/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:48 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/27 14:55:30 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	show_helper(void)
{
	ft_putstr_fd("|----------------- How to use fractol-----------------|\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|    ./fractol mandelbrot                             |\n", 1);
	ft_putstr_fd("|    ./fractol julia -0.8 0.156 (double values)       |\n", 1);
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
