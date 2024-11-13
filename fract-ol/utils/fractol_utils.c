/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:54:00 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/13 15:51:19 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	print_commands(char *av0)
{
	ft_printf("Usage:\n%s M\n%s J <real> <imaginary>\n", av0, av0);
	exit(EXIT_FAILURE);
	return (1);
}

int	color(int i)
{
	if (i == MAX_ITER)
		i = 0;
	return (i * GRADIENT);
}
