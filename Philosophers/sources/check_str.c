/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:46:30 by ralves-e          #+#    #+#             */
/*   Updated: 2024/08/25 16:01:10 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_str(char **str)
{
	char	*arg;

	if (!str || !*str || !**str)
		return (2);
	while (*str)
	{
		arg = *str;
		if (!*arg)
			return (4);
		if (*arg == '+')
		{
			arg++;
			if (!isdigit(*arg))
				return (4);
		}
		while (*arg)
		{
			if (!isdigit(*arg))
				return (4);
			arg++;
		}
		str++;
	}
	return (0);
}
