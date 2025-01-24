/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:15:22 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/24 10:16:59 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // TO DEBUG
# include <stdbool.h>
# include <X11/X.h>

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_list	*color;
	int		nb_iterations;
	double	zoom;
	double	x_shift;
	double	y_shift;
	bool	to_lerp;
}	t_env;

void	parsing(int argc, char **argv);
void	init_fractal(t_env *fractal);
void	draw_fractal(t_env *fractal);
void	event_handler(t_env *fractal);
void	free_data(t_env *fractal);
double	scale(double unscaled_num, double new_min, double new_max, double old_max);
void	calc_suit_iteration(t_complex *z, t_complex c);

#endif /* FRACTOL_H */