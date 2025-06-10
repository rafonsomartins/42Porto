/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:58:53 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/10 18:29:16 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int		index;
	int		max;

public:
	PhoneBook();
	~PhoneBook();

	void add(Contact contact);
	void display(void) const;
	bool search(int choice) const;
};

#endif
