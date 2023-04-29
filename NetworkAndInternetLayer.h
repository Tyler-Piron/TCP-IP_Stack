#pragma once

#include<string>
#include<ctime>
#include "TCP_Message_TopLayer.h"
#include <iostream>
#include "TransportLayer.h"
#include "ApplicationLayer.h"



//Class to generate and return IPV4 Source and Destination IP Adresses
class IPAddress : public TCP_Message_TopLayer {
private:
	//Source and destinaion addresses to be returned.
	std::string sourceIP;
	std::string destinationIP;

	//declares all neccecary header information with specified Byte/Bit sizes.
	unsigned int version : 4, IHL : 4;
	unsigned int DSCP : 6, ECN : 2;
	std::uint16_t totalLength;
	std::uint16_t identification;
	unsigned int flags : 3, fragmentOffset : 13;
	std::uint8_t timeToLive;
	std::uint8_t protocol;
	std::uint16_t headerChecksum;
	TransportLayer movingTransLayer;


	//General IP address to be used in a function that generates random IP addresses
	std::string IP;

	//used in IP generation
	int randomNum;

public:

	//constructor for the Class that Initializes all variables.
	IPAddress() {
		TransportLayer movingTransLayer{};
		setIP();
		setSourceandDestinationIP();
		setHeaderInfo();
	}

	IPAddress(TransportLayer transLayer) {
		movingTransLayer = transLayer;
		setIP();
		setSourceandDestinationIP();
		setHeaderInfo();


	}

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

	void setHeaderInfo() {

		version = 3;
		IHL = 9;
		DSCP = 8;
		ECN = 2;
		totalLength = 32522;
		identification = 15445;
		flags = 6;
		fragmentOffset = 50;
		timeToLive = 132;
		protocol = 250;
		headerChecksum = 10113;

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

	void DisplayHeaderInfo() {
		movingTransLayer.displayTransLayer();

		std::cout << "\nIPv4 Packet Header Information:\n";
		std::cout << "Version: " << version << "\n";
		std::cout << "IHL: " << IHL << "\n";
		std::cout << "DSCP: " << DSCP << "\n";
		std::cout << "ECN: " << ECN << "\n";
		std::cout << "Total Length: " << totalLength << "\n";
		std::cout << "Identification: " << identification << "\n";
		std::cout << "Flags: " << flags << "\n";
		std::cout << "Fragment Offset: " << fragmentOffset << "\n";
		std::cout << "Time To Live: " << int(timeToLive) << "\n";
		std::cout << "Protocol: " << int(protocol) << "\n";
		std::cout << "Header Checksum: " << headerChecksum << "\n";
		std::cout << "Source IP Address: " << getSourceIP() << "\n";
		std::cout << "Destination IP Address: " << getDestinationIP() << "\n";
		std::cout << "\n";


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

	//IPadresses.setHeaderInfo();
	//IPadresses.DisplayHeaderInfo();
//}
