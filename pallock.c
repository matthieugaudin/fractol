/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:20:10 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/17 09:35:12 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int main(void)
{
    void    *mlx_ptr;
    void    *mlx_win;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 500, 500, "fractol");
    mlx_loop(mlx_ptr);
}
