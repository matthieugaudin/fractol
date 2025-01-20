/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:15:22 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/20 11:02:12 by mgaudin          ###   ########.fr       */
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
	int		nb_iterations;
}	t_env;

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
double	scale(double unscaled_num, double new_min, double new_max, double old_max);
double	modulus(t_complex z);
void	calc_suit_iteration(t_complex *z, t_complex c);

#endif /* FRACTOL_H */