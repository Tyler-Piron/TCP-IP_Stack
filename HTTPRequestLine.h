#pragma once
#include <string>




class HTTPRequestLine {
protected:
	std::string URL; // URL string variable
	std::string version; // version type
	int holder = 0;
	int holder2 = 0;
	std::string outputString;

	

public:
	HTTPRequestLine() {
		URL = "";
		version = "";
		holder = 0;
		holder2 = 0;
		outputString = "";
	}

	//assigns values based off the first line of the text file passed through to it
	void assignValues(std::string givenString) {
		for (int i = 0; i < givenString.length(); i++) {
			if (isspace(givenString.at(i))) {
				if (holder == 0 && holder2 == 0) {
					holder = i;
					continue;
				}
				if (holder != 0 && holder2 == 0) {
					holder2 = i;
					URL = givenString.substr(holder + 2, holder2 - holder - 1);
					version = givenString.substr(holder2 + 6, 3);
					holder = holder2;
					holder2 = 0;
					break;
				}
				
			}
			
		}
	}
	void displayRequestLine() { //displays request line information
		std::cout << getRequestString();
	}

	std::string getRequestString() { // returns the string equivalent of class used in binary conversion
		outputString.append("URL: ");
		outputString.append(URL);
		outputString.append("\n");
		outputString.append("HTTP Version: ");
		outputString.append(version);
		outputString.append("\n");
		return outputString;
	}

	std::string getUrl() {
		return URL;
	}

	std::string getVersion() {
		return version;
	}
};
