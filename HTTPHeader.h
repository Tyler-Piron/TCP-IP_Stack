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
	std::string key; // temporary key value used to populate the map
	std::string value; // temporary value used to populate the map
	std::string textLine; // textline parsed from the text file
	std::string outputString; // string variable used to grab the string output from this header
	int wordCount = 0;

public:
	HTTPHeader(){
		key = "";
		value = "";
		textLine = "";
		outputString = "";

	}
		
	


	void readFile() {
		//reads the text file and populates based on the text file
		std::ifstream testFile("testingInput.txt"); //make sure to change this string value to the text file's name
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

	void displayHTTPHeader() { //displays the header information
		std::cout << getHTTPHeaderString();
	}

	std::string getHTTPHeaderString() { //returns the string equivalent of this class' information
		return outputString;
	}
	
	
};
