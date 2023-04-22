#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "HTTPRequestLine.h"
#include "HTTPHeader.h"
#include "TCP_Message_TopLayer.h"



class ApplicationLayer : public TCP_Message_TopLayer {

public:
	HTTPRequestLine requestLine{};
	HTTPHeader httpHeader{};

	void setRequestLine() {
		std::ifstream testingFile("testingInput.txt");
		if (testingFile.is_open()) {
			std::string testingString;
			getline(testingFile, testingString);
			requestLine.assignValues(testingString);
		}
	}

	void setHeader() {
		httpHeader.readFile();
	}

	void displayApplicationLayer() {
		requestLine.displayRequestLine();
		httpHeader.displayHTTPHeader();
	}




};
