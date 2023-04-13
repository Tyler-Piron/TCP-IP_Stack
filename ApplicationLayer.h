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
						std::cout << "Key: " << ApplicationMap[value] << " Value: " << value << " \n";
						break;
					}

				}
				//if (flag == 1){
					//std::cout << "A space was detected";
				//}







				/*std::cout << "File has opened\n";
				do {

					testFile >> textLine;
					wordCount++;
					int strLength = textLine.length();
					if (textLine == "\r\n"){
						break;

					}
					else {
						if (wordCount % 2 == 0) {
							key = textLine;
						}
						else {

							value = textLine;
							ApplicationMap[value] = key;
							std::cout << "Key: "<< ApplicationMap[value] << " Value: " << value << " \n";

						}
					}

				} while (!testFile.fail());

			}
			else {
				std::cout << "File could not be opened\n";
			}*/
			}

		};

	}

};
