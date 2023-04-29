#pragma once
#include <bitset>
#include <iostream>

class StringToBinary {
public:
    StringToBinary(const std::string& input) : input(input) {}

    std::string Convert() {
        std::string binaryString;
        for (char c : input) {
            std::bitset<8> binary(c);
            binaryString += binary.to_string() + " ";
        }
        return binaryString;
    }

private:
    std::string input;
};
