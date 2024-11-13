/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:34:00 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/14 13:47:46 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	valid_input(char *str)
{
	int	point;

	point = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str == '.' || *str == ',')
		{
			if (point)
				return (0);
			point++;
		}
		else if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

double	float_part(char *str)
{
	double	result;
	double	temp;
	double	factor;

	str++;
	temp = 0.0;
	result = 0.0;
	factor = 10.0;
	while (*str)
	{
		temp = *str - '0';
		result += temp / factor;
		factor *= 10.0;
		str++;
	}
	return (result);
}

double	int_part(char *str)
{
	double	result;

	result = 0.0;
	if (*str == '-')
		str++;
	while (*str && *str != ',' && *str != '.')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.' || *str == ',')
		result += float_part(str);
	return (result);
}

double	parse(char *str)
{
	double	result;
	int		negative;

	if (!valid_input(str))
		return (print_commands("./fractol"));
	if (*str == '-')
		negative = -1;
	else
		negative = 1;
	result = int_part(str);
	return (result * negative);
}

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		return (print_commands(av[0]));
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "M", ft_strlen(av[1])))
			return (mandelbrot());
		return (print_commands(av[0]));
	}
	if (ft_strncmp(av[1], "J", ft_strlen(av[1])))
		return (print_commands(av[0]));
	return (julia(parse(av[2]), parse(av[3])));
}
