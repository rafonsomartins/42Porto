/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:49 by ralves-e          #+#    #+#             */
/*   Updated: 2025/06/08 17:07:18 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &text, const std::string &s1, const std::string &s2) {
	std::string result;
	size_t pos = 0;
	size_t match;

	while ((match = text.find(s1, pos)) != std::string::npos) {
		result += text.substr(pos, match - pos);
		result += s2;
		pos = match + s1.length();
	}
	result += text.substr(pos);
	return result;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty\n";
		return 1;
	}

	std::ifstream inputFile(filename);
	if (!inputFile) {
		std::cerr << "Error: could not open input file: " << filename << '\n';
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();

	std::string modified = replaceAll(content, s1, s2);

	std::ofstream outputFile(filename + ".replace");
	if (!outputFile) {
		std::cerr << "Error: could not create output file\n";
		return 1;
	}

	outputFile << modified;
	outputFile.close();

	return 0;
}
