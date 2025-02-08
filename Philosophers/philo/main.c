/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:35:41 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/08 14:35:45 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_args args, t_philo *philos)
{
	long long	timestamp;

	timestamp = ft_actual_time() - args.init_time;
	printf("%lld 1 has taken a fork\n", timestamp);
	ft_sleep(args.time_to_die);
	timestamp = ft_actual_time() - args.init_time;
	printf("%lld 1 died\n", timestamp);
	return (free_stuff(&args, &philos, 1));
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philos;
	int		i;

	if (check_str(argv + 1))
		return (-1);
	if (parser(&args, argc, argv))
		return (-2);
	init_var(&args, &philos);
	if (args.num_philo == 1)
		return (one_philo(args, philos));
	run_sim(&args, philos);
	check_philos(&args, philos);
	i = args.num_philo;
	while (i-- > 0)
		pthread_join(philos[i].philo, NULL);
	free_stuff(&args, &philos, 0);
	return (args.someone_dead);
}
