#pragma once
#include <string>




class HTTPRequestLine {
protected:
	std::string URL;
	std::string version;
	int holder = 0;
	int holder2 = 0;
	bool urlFlag = false;

	

public:
	HTTPRequestLine() {
		URL = "";
		version = "";
		holder = 0;
		holder2 = 0;
		urlFlag = false;
	}

	void assignValues(std::string givenString) {
		for (int i = 0; i < givenString.length(); i++) {
			if (isspace(givenString.at(i))) {
				if (holder == 0 && holder2 == 0) {
					holder = i;
				}
				if (holder != 0 && holder2 == 0) {
					holder2 = i;
					if (urlFlag == false){
						URL = givenString.substr(holder + 2, holder2 - holder - 1);
						holder = holder2;
						holder2 = 0;
					}
					else {
						version = givenString.substr(holder + 6, 3);
						break;
					}
				}
				
			}
			
		}
	}
	void displayRequestLine() {
		std::cout << "URL: " << URL << "\n" << "HTTP Version: " << version << "\n";
	}


	std::string getUrl() {
		return URL;
	}

	std::string getVersion() {
		return version;
	}
};
