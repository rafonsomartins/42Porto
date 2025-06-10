/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:27 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/10 19:35:08 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

bool Contact::setContact(std::string fn, std::string ln, std::string nn, std::string p, std::string s)
{
	if (fn.empty() || ln.empty() || nn.empty() || p.empty() || s.empty())
		return false;
	first_name = fn;
	last_name = ln;
	nickname = nn;
	phone = p;
	secret = s;
	return true;
}

static std::string formatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

void Contact::display(void) const
{
	std::cout << formatField(first_name) << "|";
	std::cout << formatField(last_name) << "|";
	std::cout << formatField(nickname) << std::endl;
}

void Contact::show(void) const
{
	std::cout << "First Name:    " << first_name << std::endl;
	std::cout << "Last Name:    " << last_name << std::endl;
	std::cout << "Nickname:    " << nickname << std::endl;
	std::cout << "Phone Number:    " << phone << std::endl;
	std::cout << "Darkest Secret:    " << secret << std::endl;
}