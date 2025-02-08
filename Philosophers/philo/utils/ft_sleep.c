/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:10:50 by ralves-e          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:34 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	ft_actual_time(void)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));
}

void	ft_sleep(unsigned int milliseconds)
{
	unsigned long	desire_time;

	desire_time = ft_actual_time() + milliseconds;
	while (ft_actual_time() <= desire_time)
		;
	return ;
}
