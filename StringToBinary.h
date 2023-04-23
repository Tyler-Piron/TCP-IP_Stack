#pragma once
#include <bitset>
#include <iostream>
class StringToBinary {
public:
	StringToBinary(const std::string& input) : input(input) {}

	void Convert() {
		for (char c : input) {
			std::bitset<8> binary(c);
			std::cout << binary << " ";
		}
		std::cout << std::endl;
	}

private:
	std::string input;
};
