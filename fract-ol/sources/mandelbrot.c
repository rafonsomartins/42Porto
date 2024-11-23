/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:04:12 by ralves-e          #+#    #+#             */
/*   Updated: 2024/11/16 00:35:19 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	calculate(t_cnbr c)
{
	t_cnbr	z;
	double	buf;
	int		i;

	i = 0;
	z.real = 0;
	z.imag = 0;
	while (((z.real * z.real) + (z.imag * z.imag)) <= 4 && i < MAX_ITER)
	{
		buf = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = buf;
		i++;
	}
	return (i);
}

static void	create_image(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		exit(EXIT_FAILURE);
	mlx->img_data = mlx_get_data_addr(mlx->img, &(mlx->bpp),
			&(mlx->size_line), &(mlx->endian));
}

static void	render(t_mlx *mlx)
{
	t_coor	n;
	t_cnbr	c;
	int		pixel_color;
	int		pixel_index;

	create_image(mlx);
	n.y = 0;
	while (n.y < HEIGHT)
	{
		n.x = 0;
		while (n.x < WIDTH)
		{
			c.real = (((mlx->x_max - mlx->x_min) / WIDTH) * n.x) + mlx->x_min;
			c.imag = (((mlx->y_max - mlx->y_min) / HEIGHT) * n.y) + mlx->y_min;
			pixel_color = color(calculate(c));
			pixel_index = (n.y * mlx->size_line) + (n.x * (mlx->bpp / 8));
			mlx->img_data[pixel_index] = (pixel_color & 0xFF);
			mlx->img_data[pixel_index + 1] = (pixel_color & 0xFF00) >> 8;
			mlx->img_data[pixel_index + 2] = (pixel_color & 0xFF0000) >> 16;
			n.x++;
		}
		n.y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

static int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	double	center_x;
	double	center_y;

	center_x = ((double)x / WIDTH) * (mlx->x_max - mlx->x_min) + mlx->x_min;
	center_y = ((double)y / WIDTH) * (mlx->y_max - mlx->y_min) + mlx->y_min;
	if (button == 4)
		zoom(mlx, 0.9, center_x, center_y);
	if (button == 5)
		zoom(mlx, 1.1, center_x, center_y);
	render(mlx);
	return (0);
}

int	mandelbrot(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.img = NULL;
	if (mlx.mlx == NULL)
		return (EXIT_FAILURE);
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	if (mlx.win == NULL)
		return (EXIT_FAILURE);
	mlx.x_max = 2;
	mlx.x_min = -2;
	mlx.y_max = 2;
	mlx.y_min = -2;
	render(&mlx);
	mlx_key_hook(mlx.win, keypress, (void *)&mlx);
	mlx_hook(mlx.win, 17, 0, close_window, (void *)&mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (EXIT_SUCCESS);
}
