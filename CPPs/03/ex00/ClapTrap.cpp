/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:12:39 by ralves-e          #+#    #+#             */
/*   Updated: 2025/06/10 19:45:04 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : name("Default"), can_do(true), hit_points(10), energy_points(10), attack_damage(10) {
	std::cout << "Default constructor called on " << this->name << " ClapTrap instance." << std::endl;
}
ClapTrap::ClapTrap(const std::string name) : name(name), can_do(true), hit_points(10), energy_points(10), attack_damage(10) {
	std::cout << "Constructor called on " << this->name << " ClapTrap instance." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called on previous " << this->name << " ClapTrap instance.";
	this->name = other.name;
	this->can_do = other.can_do;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	std::cout << "New name: " << this->name << "." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << " Destructor called on " << this->name << " ClapTrap instance." << std::endl;
}


// Member functions
void ClapTrap::takeDamage(unsigned int amount) {
	if (!can_do)
		return;

	int result = this->hit_points - amount;
	if (result <= 0)
	{
		this->hit_points = 0;
		this->can_do = false;
	}
	else
		this->hit_points = result;

	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " got damaged. Now it has: ";
	std::cout << this->hit_points;
	std::cout << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!can_do)
		return;

	this->hit_points += amount;

	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " repaired. Now it has: ";
	std::cout << this->hit_points;
	std::cout << " hit points." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!can_do)
		return;

	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " attacked ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << this->attack_damage;
	std::cout << " points of damage." << std::endl;
}
