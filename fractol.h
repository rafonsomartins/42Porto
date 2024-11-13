/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:37:42 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/13 16:04:28 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# ifndef GRADIENT
#  define GRADIENT 0x2211FF
# endif

# ifndef MAX_ITER
#  define MAX_ITER 42
# endif

# define ESC 65307
# define WIDTH 800
# define HEIGHT 800

typedef struct s_cbnr
{
	double	real;
	double	imag;
}	t_cnbr;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	double	x_max;
	double	y_max;
	double	y_min;
	double	x_min;
}	t_mlx;

typedef struct s_julia
{
	t_mlx	mlx;
	t_cnbr	c;
}	t_julia;

typedef struct s_coor
{
	double	x;
	double	y;
}	t_coor;

int		main(int ac, char **av);
int		mandelbrot(void);
int		julia(double real, double imag);
int		close_window(t_mlx *mlx);
int		keypress(int keycode, t_mlx *mlx);
void	zoom(t_mlx *mlx, double factor, double center_x, double center_y);
int		print_commands(char *av0);
int		color(int i);

#endif