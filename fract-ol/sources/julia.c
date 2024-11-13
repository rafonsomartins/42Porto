/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:03:10 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/13 16:25:37 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	calculate(t_cnbr z, t_cnbr c)
{
	double	buf;
	int		i;

	i = 0;
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

static void	render(t_mlx *mlx, t_cnbr c)
{
	t_coor	n;
	t_cnbr	z;
	int		pixel_color;
	int		pixel_index;

	create_image(mlx);
	n.y = 0;
	while (n.y < HEIGHT)
	{
		n.x = 0;
		while (n.x < WIDTH)
		{
			z.real = (((mlx->x_max - mlx->x_min) / WIDTH) * n.x) + mlx->x_min;
			z.imag = (((mlx->y_max - mlx->y_min) / HEIGHT) * (HEIGHT - n.y))
				+ mlx->y_min;
			pixel_color = color(calculate(z, c));
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

static int	mouse_hook(int button, int x, int y, t_julia *julia)
{
	double	center_x;
	double	center_y;

	center_x = ((double)x / WIDTH)
		* (julia->mlx.x_max - julia->mlx.x_min) + julia->mlx.x_min;
	center_y = ((double)(HEIGHT - y) / WIDTH)
		* (julia->mlx.y_max - julia->mlx.y_min) + julia->mlx.y_min;
	if (button == 4)
		zoom(&(julia->mlx), 0.9, center_x, center_y);
	if (button == 5)
		zoom(&(julia->mlx), 1.1, center_x, center_y);
	render(&(julia->mlx), julia->c);
	return (0);
}

int	julia(double real, double imag)
{
	t_julia	julia;

	julia.mlx.mlx = mlx_init();
	julia.mlx.img = NULL;
	if (julia.mlx.mlx == NULL)
		return (EXIT_FAILURE);
	julia.mlx.win = mlx_new_window(julia.mlx.mlx, WIDTH, HEIGHT, "Julia set");
	if (julia.mlx.win == NULL)
		return (EXIT_FAILURE);
	julia.mlx.x_max = 2;
	julia.mlx.x_min = -2;
	julia.mlx.y_max = 2;
	julia.mlx.y_min = -2;
	julia.c.real = real;
	julia.c.imag = imag;
	render(&(julia.mlx), julia.c);
	mlx_key_hook(julia.mlx.win, keypress, (void *)&(julia.mlx));
	mlx_hook(julia.mlx.win, 17, 0, close_window, (void *)&(julia.mlx));
	mlx_mouse_hook(julia.mlx.win, mouse_hook, (void *)&julia);
	mlx_loop(julia.mlx.mlx);
	return (EXIT_SUCCESS);
}
