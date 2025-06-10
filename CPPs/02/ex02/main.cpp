/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:58:39 by ralves-e          #+#    #+#             */
/*   Updated: 2025/06/10 01:03:05 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "===== subject main (Increment tests) =====" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n===== COMPARISON OPERATORS =====" << std::endl;
	Fixed c(10);
	Fixed d(20);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;

	std::cout << "\n===== ARITHMETIC OPERATORS =====" << std::endl;
	Fixed e(3.5f);
	Fixed f(2.0f);
	std::cout << "e: " << e << ", f: " << f << std::endl;
	std::cout << "e + f: " << (e + f) << std::endl;
	std::cout << "e - f: " << (e - f) << std::endl;
	std::cout << "e * f: " << (e * f) << std::endl;
	std::cout << "e / f: " << (e / f) << std::endl;

	std::cout << "\n===== MIN / MAX TESTS =====" << std::endl;
	Fixed m(3.3f);
	Fixed n(7.7f);
	const Fixed o(2.2f);
	const Fixed p(5.5f);
	std::cout << "min(m, n): " << Fixed::min(m, n) << std::endl;
	std::cout << "max(m, n): " << Fixed::max(m, n) << std::endl;
	std::cout << "min(o, p): " << Fixed::min(o, p) << std::endl;
	std::cout << "max(o, p): " << Fixed::max(o, p) << std::endl;

	return 0;
}
