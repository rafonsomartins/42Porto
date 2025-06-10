/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPhoneBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:05:30 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/10 19:04:27 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyPhoneBook.hpp"

void MyPhoneBook::addContact() {
	std::string fn, ln, nn, p, s;
	std::cout << "First Name:    ";
	std::getline(std::cin, fn);
	std::cout << "Last Name:    ";
	std::getline(std::cin, ln);
	std::cout << "Nickname:    ";
	std::getline(std::cin, nn);
	std::cout << "Phone Number:    ";
	std::getline(std::cin, p);
	std::cout << "Darkest Secret:    ";
	std::getline(std::cin, s);

	Contact contact;
	if (contact.setContact(fn, ln, nn, p, s))
		phonebook.add(contact);
	else
		std::cout << std::endl << "ERROR:	Fields cannot be blank!" << std::endl;
	std::cout << std::endl;
}

void MyPhoneBook::searchContact() {
	phonebook.display();
	std::string input;
	std::cout << "Enter index to view details: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;

	if (input.length() == 1 && std::isdigit(input[0])) {
		int idx = input[0] - '0';
		if (phonebook.search(idx))
			std::cout << "Invalid index.\n";
	} else {
		std::cout << "Invalid input.\n";
	}
	std::cout << std::endl;
}

void MyPhoneBook::run() {
	std::string command;

	while (true && !(std::cin.eof())) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			addContact();
		} else if (command == "SEARCH") {
			searchContact();
		} else if (command == "EXIT") {
			std::cout << "Exiting PhoneBook.\n" << std::endl;
			break;
		} else if (std::cin.eof()) {
			std::cout << std::endl << "Received signal equivalent to EXIT command. Exiting PhoneBook.\n" << std::endl;
			break;
		} else
			std::cout << std::endl;
	}
}
