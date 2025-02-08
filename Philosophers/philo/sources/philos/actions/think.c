/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:06:17 by ralves-e          #+#    #+#             */
/*   Updated: 2024/09/07 12:40:32 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philo.h"

void	*philo_think(t_philo *philo)
{
	long long	timestamp;

	pthread_mutex_lock(&(philo->args->stdout_mutex));
	pthread_mutex_lock(&(philo->args->someone_dead_mutex));
	pthread_mutex_lock(&(philo->args->init_time_mutex));
	timestamp = ft_actual_time() - philo->args->init_time;
	if (philo->args->someone_dead == 0)
		printf("%lld %d is thinking\n", timestamp, philo->philo_id);
	else
	{
		pthread_mutex_unlock(&(philo->args->init_time_mutex));
		pthread_mutex_unlock(&(philo->args->stdout_mutex));
		pthread_mutex_unlock(&(philo->args->someone_dead_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(philo->args->init_time_mutex));
	pthread_mutex_unlock(&(philo->args->someone_dead_mutex));
	pthread_mutex_unlock(&(philo->args->stdout_mutex));
	return (philo_eat(philo));
}
