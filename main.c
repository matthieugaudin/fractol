/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:20:10 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/17 16:18:38 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

#define WIDTH 500
#define HEIGHT 500

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pxl;
	int		offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
		pxl = data->addr + offset;
		*(unsigned int *)pxl = color;
	}

}

int main(void)
{
	t_env	env;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, 750, 750, "fractol");
    env.img.img = mlx_new_image(env.mlx, 750, 750);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, 
								&env.img.endian);
	ft_mlx_pixel_put(&env.img, 250, 250, 0xff0000);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	mlx_loop(env.mlx);
}
