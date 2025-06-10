/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:44:49 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/08 15:37:57 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	run_sim(t_args *args, t_philo *philos)
{
	int	i;

	i = args->num_philo;
	while (--i >= 0)
	{
		philos[i].args = args;
		philos[i].philo_id = (i + 1);
		philos[i].last_eat = 0;
		philos[i].nbr_eaten = 0;
		pthread_mutex_init(&(philos[i].nbr_eaten_mutex), NULL);
		pthread_mutex_init(&(philos[i].last_eat_mutex), NULL);
		if (pthread_create(&(philos[i].philo), NULL, &routine, &philos[i]))
			exit_function(args, &philos);
		ft_sleep(7);
	}
	return ;
}
