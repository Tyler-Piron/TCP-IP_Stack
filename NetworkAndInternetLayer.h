#pragma once

#include<string>


//Class to generate and return IPV4 Source and Destination IP Adresses
class IPAddress {
private:
	//Source and destinaion addresses to be returned.
	std::string sourceIP;
	std::string destinationIP;

	//General IP address to be used in a function that generates random IP addresses
	std::string IP;

	//used in IP generation
	int randomNum;

public:

	//function that generates a random IPV4 IP and returns it
	std::string setIP() {
		//sets the IP to empty to be generated
		IP = "";
		srand(time(NULL));

		//genertes new IP's until conditions in while loop are met.
		//0.0.0.0 and 999.999.999.999 are not allowed by constraints
		while (IP == "" or IP == "0.0.0.0" or IP == "999.999.999.999") {
			IP = "";
			//loop generates 4 random numbers from 0 to 255 and appends them to the IP variable
			for (int i = 0; i < 4; i++)
			{
				randomNum = (rand() % 255);
				IP.append(std::to_string(randomNum));
				IP.append(".");
			}
		}
		//returns the now randomly generated IP
		return IP;
	}


	//sets the Source and Destination IP adress using previous function
	void setSourceandDestinationIP() {

		//generates adresses for source and destination
		sourceIP = setIP();
		destinationIP = setIP();

		//Checks if Source and Destination addresses are equal.
		//if equal, genereates new destination adresses until not.
		while (destinationIP == sourceIP) {
			destinationIP = "";
			destinationIP = setIP();
		}
	}
	
	//returns Source IP
	std::string getSourceIP() {
		return sourceIP;
	}

	//returns Destination IP
	std::string getDestinationIP() {
		return destinationIP;
	}

	std::string getComboIPs() {
		std::string outputString;
		outputString.append("Source IP: ");
		outputString.append(destinationIP);
		outputString.append("\n");
		outputString.append("Destination IP: ");
		outputString.append(sourceIP);
		outputString.append("\n");
		return outputString;
	}
};

//An Example of how to run this code:

//#include <iostream>
//#include "NetworkAndInternetLayer.h"

//int main()
//{
	//IPAddress IPadresses;

	//IPadresses.setSourceandDestinationIP();

	//std::cout << "Source Adress is " << IPadresses.getSourceIP() << " \n";
	//std::cout << "Destination Adress is " << IPadresses.getDestinationIP() << " \n";
//}
