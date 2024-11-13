/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:08:21 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/13 16:11:58 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	return (keypress(ESC, mlx));
}

void	zoom(t_mlx *mlx, double factor, double x, double y)
{
	mlx->x_min = x - (x - mlx->x_min) * factor;
	mlx->x_max = x + (mlx->x_max - x) * factor;
	mlx->y_min = y - (y - mlx->y_min) * factor;
	mlx->y_max = y + (mlx->y_max - y) * factor;
}
