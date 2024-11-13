/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:46:29 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/13 23:08:20 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	char	*temp;

	i = 0;
	sign = 1;
	temp = (char *)nptr;
	while (*temp == ' ' || (*temp >= '\t' && *temp <= '\r'))
		temp++;
	if (*temp == '-' || *temp == '+')
	{
		if (*temp == '-')
			sign *= -1;
		temp++;
	}
	if (ft_strncmp((char *)temp, "2147483648", 11) == 0 && sign == -1)
		return (-2147483648);
	while (*temp >= '0' && *temp <= '9')
	{
		i = i * 10 + (*temp - '0');
		temp++;
	}
	return (i * sign);
}
