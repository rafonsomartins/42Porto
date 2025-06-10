/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:30:56 by ralves-e          #+#    #+#             */
/*   Updated: 2025/05/14 18:13:06 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon *weapon;

public:
	HumanB();
	HumanB(std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
