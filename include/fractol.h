/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:15:22 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/17 16:12:10 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // TO DEBUG

typedef struct s_complex_nb
{
	double	real;
	double	i;
}	t_complex_nb;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_env;

#endif /* FRACTOL_H */