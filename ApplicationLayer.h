#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "HTTPRequestLine.h"
#include "HTTPHeader.h"
#include "TCP_Message_TopLayer.h"



class ApplicationLayer {

public:

	HTTPRequestLine requestLine;
	HTTPHeader httpHeader;

	void setRequestLine() {
		std::ifstream testingFile("testingInput.txt");
		if (testingFile.is_open()) {
			std::string testingString;
			getline(testingFile, testingString);
			requestLine.assignValues(testingString);
		}
		else {
		std::cout << "File not found";
		}
	}

	void setHeader() {
		httpHeader.readFile();
	}

	std::string getApplicationLayerString() {
		std::string outputString;
		outputString = outputString + requestLine.getRequestString();
		outputString = outputString + httpHeader.getHTTPHeaderString();
		return outputString;
	}

	void displayApplicationLayer() {
		requestLine.displayRequestLine();
		httpHeader.displayHTTPHeader();
		std::cout << "\n";

	}




};
