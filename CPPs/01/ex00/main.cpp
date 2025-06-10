/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:34:17 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/13 17:14:32 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* singleZombie = newZombie("Monster");
	if (singleZombie) {
		std::cout << "\nSingle Zombie: " << std::endl;
		singleZombie->announce();
		delete singleZombie;
	} else {
		std::cout << "Failed to create single zombie!" << std::endl;
	}

	std::cout << "\nRandom Chump: " << std::endl;
	randomChump("Chump");

	return 0;
}
