/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:07:37 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/24 16:32:56 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	free_circular_lst(t_list **head)
{
	t_list	*node;
	t_list	*tmp;

	node = (*head)->next;
	while (node != *head)
	{
		tmp = node;
		node = node->next;
		ft_lstdelone(tmp, free);
	}
	ft_lstdelone(node, free);
}

void	free_data(t_env *fractal)
{
	if (fractal)
	{
		if (fractal->color)
		{
			free_circular_lst(&fractal->color);
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
