/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:04:01 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/10 20:04:13 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int count = 5;
	Zombie* horde = zombieHorde(count, "Walker");

	if (!horde) {
		std::cout << "Failed to create zombie horde!" << std::endl;
		return 1;
	}

	std::cout << "Zombie Horde: " << std::endl;
	for (int i = 0; i < count; ++i)
		horde[i].announce();

	delete[] horde;

	return 0;
}