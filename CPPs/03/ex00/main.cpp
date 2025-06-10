/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:16:25 by ralves-e          #+#    #+#             */
/*   Updated: 2025/06/10 19:45:34 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout << "===== CREATING CLAPTRAPS =====" << std::endl;
	ClapTrap a("Alice");
	ClapTrap b("Bob");

	std::cout << "\n===== ATTACK PHASE =====" << std::endl;
	a.attack("Bob");
	b.takeDamage(10);
	b.attack("Alice");

	std::cout << "\n===== REPAIR PHASE =====" << std::endl;
	ClapTrap c("Mark");
	ClapTrap d("Alex");

	c.beRepaired(5);

	std::cout << "\n===== MORE DAMAGE =====" << std::endl;
	d.attack("Mark");
	d.attack("Mark");
	c.takeDamage(20);

	std::cout << "\n===== COPYING AND ATTACKING WITH DEAD CLAPTRAP=====" << std::endl;
	c.attack("Bob");
	ClapTrap e = a;
	e.attack("Some target");

	return 0;
}
