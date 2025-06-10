/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPhoneBook.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:04:36 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/10 19:08:39 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPHONEBOOK_HPP
#define MYPHONEBOOK_HPP

#include "PhoneBook.hpp"

class MyPhoneBook {
private:
	PhoneBook phonebook;

	void addContact();
	void searchContact();

public:
	void run();
};

#endif
