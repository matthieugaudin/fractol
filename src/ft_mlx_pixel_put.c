/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:09:01 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/20 10:39:57 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;
	int		offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		pxl = img->pixel + offset;
		*(unsigned int *)pxl = color;
	}
}
