/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:02:36 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/13 18:22:31 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), max(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add(Contact contact)
{
	if (index >= 8)
		index = 0;
	contacts[index] = contact;
	index++;
	if (max < 8)
		max++;
}

void PhoneBook::display(void) const
{
	std::cout << "     Index";
	std::cout << "|";
	std::cout << "First Name";
	std::cout << "|";
	std::cout << " Last Name";
	std::cout << "|";
	std::cout << "  Nickname" << std::endl;

	for (int i = 0; (i < max && i <= 7); i++) {
		std::cout <<  "         " << i << "|";
		contacts[i].display();
	}
	
	std::cout << std::endl;
}

bool PhoneBook::search(int choice) const
{
	if (choice < 0 || choice > max || choice >= 8)
		return true;
	contacts[choice].show();
	return false;
}
