/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:48 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/01 18:24:44 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	show_helper(void)
{
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("|--------------- How to launch fractol----------------|\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|    ./fractol mandelbrot                             |\n", 1);
	ft_putstr_fd("|    ./fractol burningship                            |\n", 1);
	ft_putstr_fd("|    ./fractol julia [real] [imaginary]               |\n", 1);
	ft_putstr_fd("|    Example: ./fractol julia -0.8 0.156              |\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|-------------- How to use the keyboard --------------|\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|     Press L to turn on/off RGB lerping              |\n", 1);
	ft_putstr_fd("|     Press S to change the set's color               |\n", 1);
	ft_putstr_fd("|     Press arrow keys to move the view               |\n", 1);
	ft_putstr_fd("|     Press +/- to increase/decrease iteration depth  |\n", 1);
	ft_putstr_fd("|     Press ESC to close the window                   |\n", 1);
	ft_putstr_fd("|     Click the window's close button to exit         |\n", 1);
	ft_putstr_fd("|     Scroll to zoom in/out (follows the mouse)       |\n", 1);
	ft_putstr_fd("|                                                     |\n", 1);
	ft_putstr_fd("|-----------------------------------------------------|\n", 1);
	ft_putstr_fd("\n\n", 1);
}

static int	is_numeric(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		else if (str[i] == '.' && !str[i + 1])
			return (0);
		else if (str[i] == '.' && i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	parsing(int argc, char **argv)
{
	if (argc == 1)
	{
		show_helper();
		exit(0);
	}
	else if (!ft_strcmp("mandelbrot", argv[1]) && argc == 2)
		return ;
	else if (!ft_strcmp("burningship", argv[1]) && argc == 2)
		return ;
	else if (!ft_strcmp("julia", argv[1]) && argc == 4
			&& is_numeric(argv[2]) && is_numeric(argv[3]))
		return ;
	show_helper();
	exit(0);
}
