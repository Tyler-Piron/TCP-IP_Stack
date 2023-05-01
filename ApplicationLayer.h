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

	HTTPRequestLine requestLine; // Object created of request line
	HTTPHeader httpHeader; // Object of http header created

	void setRequestLine() { // checks if file is open and then calls the appropriate method to assign values to map
		std::ifstream testingFile("testingInput.txt"); //change this to match .txt file name
		if (testingFile.is_open()) {
			std::string testingString;
			getline(testingFile, testingString);
			requestLine.assignValues(testingString);
		}
		else {
		std::cout << "File not found";
		}
	}

	//calls method to set the header 
	void setHeader() {
		httpHeader.readFile();
	}

	
	//returns a string version of the layer information to convert for binary
	std::string getApplicationLayerString() {
		std::string outputString;
		outputString = outputString + requestLine.getRequestString();
		outputString = outputString + httpHeader.getHTTPHeaderString();
		return outputString;
	}

	//displays the application layer information
	void displayApplicationLayer() {
		requestLine.displayRequestLine();
		httpHeader.displayHTTPHeader();
		std::cout << "\n";

	}




};
