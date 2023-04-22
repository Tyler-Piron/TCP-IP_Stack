#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "HTTPRequestLine.h"
#include "ApplicationLayer.h"


class HTTPHeader {
protected:
	std::map<std::string, std::string>ApplicationMap;

private:
	std::string key;
	std::string value;
	std::string textLine;
	std::string outputString;
	int wordCount = 0;

public:
	HTTPHeader(){
		key = "";
		value = "";
		textLine = "";
		outputString = "";

	}
		
	


	void readFile() {
		std::ifstream testFile("testingInput.txt");
		if (testFile.is_open()) {
			std::string testString;
			int testStrLength;
			int numberNeeded;
			int numKeys = 0;

			while (getline(testFile, testString)) {
				//std::cout << testString << "\n";

				testStrLength = testString.length();

				for (int i = 0; i < testStrLength; i++) {
					if (isspace(testString.at(i))) {
						numKeys++;
						if (numKeys == 1) {
							break;
						}
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

	void displayHTTPHeader() {
		std::cout << outputString;
	}

	std::string getApplicationLayer() {
		return outputString;
	}
	
	
};
