#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>


class ApplicationLayer {
protected:
	std::map<std::string, std::string>ApplicationMap;

private:
	std::string key;
	std::string value;
	std::string textLine;
	std::string outputString;
	int wordCount = 0;

public:
	void readFile() {
		std::ifstream testFile("testingInput.txt");
		if (testFile.is_open()) {
			std::string testString;
			int testStrLength;
			int numberNeeded;

			while (getline(testFile, testString)) {
				//std::cout << testString << "\n";
				
				testStrLength = testString.length();

				for (int i = 0; i < testStrLength; i++) {
					if (isspace(testString.at(i))){
						key = testString.substr(0, i);
						numberNeeded = testStrLength - i - 5;
						value = testString.substr(i + 1, numberNeeded);
						ApplicationMap[value] = key;
						//std::cout << "Key: " << ApplicationMap[value] << " Value: " << value << " \n";
						outputString.append(ApplicationMap[value]);
						outputString.append(value);
						outputString.append("\n");
						break;
					}

				}
				
			}

		};

	}


	std::string getApplicationLayer() {
		return outputString;
	}

};
