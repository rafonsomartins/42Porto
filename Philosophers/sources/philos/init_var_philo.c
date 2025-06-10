/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:58:35 by ralves-e          #+#    #+#             */
/*   Updated: 2024/09/07 15:52:37 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	init_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (philo->philo_id == philo->args->num_philo)
			philo->forks[0] = 1;
		else
			philo->forks[0] = philo->philo_id + 1;
		philo->forks[1] = philo->philo_id;
	}
	else
	{
		philo->forks[0] = philo->philo_id;
		if (philo->philo_id == philo->args->num_philo)
			philo->forks[1] = 1;
		else
			philo->forks[1] = philo->philo_id + 1;
	}
}

void	init_var_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->nbr_eaten_mutex));
	philo->nbr_eaten = 0;
	pthread_mutex_unlock(&(philo->nbr_eaten_mutex));
	philo->is_dead = 0;
	pthread_mutex_lock(&(philo->last_eat_mutex));
	philo->last_eat = ft_actual_time();
	pthread_mutex_unlock(&(philo->last_eat_mutex));
	init_forks(philo);
}
