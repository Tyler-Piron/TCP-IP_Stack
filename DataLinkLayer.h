#pragma once

// DataLinkLayer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include<string>
#include<time.h>


//Class to generate and return Mac Adresses
class MacAddress {
private:
	//Source and destinaion addresses to be returned.
	std::string sourceMacAddress;
	std::string destinationMacAddress;

	//General Mac address to be used in a function that generates random Mac addresses
	std::string macAddress;

	//array that contains all the possible values found in a Mac Address
	std::string possibleValue[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };

	//used in Mac Address generation by assigning it a value from the array
	int randomItemInArray;

public:

	//function that generates a random Mac Adress using info from the array and returns it
	std::string setMacAddress() {
		//sets the Mac Address to empty to be generated
		macAddress = "";
		srand(time(NULL));

		//genertes new Addresses until conditions in while loop are met.
		while (macAddress == "") {
			//loop adds 12 random values from previously created array to macAddress with a period after every 2 values.
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 2; j++) {

					randomItemInArray = (rand() % 16);
					macAddress.append(possibleValue[randomItemInArray]);
				}
				macAddress.append(":");
			}
		}
		//returns the now randomly generated Mac Address
		return macAddress;
	}


	//sets the Source and Destination Mac adress using previous function
	void setSourceandDestinationMacAddress() {

		//generates adresses for source and destination
		sourceMacAddress = setMacAddress();
		destinationMacAddress = setMacAddress();

		//Checks if Source and Destination addresses are equal.
		//if equal, genereates new destination adresses until not.
		while (destinationMacAddress == sourceMacAddress) {
			destinationMacAddress = "";
			destinationMacAddress = setMacAddress();
		}
	}

	//returns Source Mac Address
	std::string getSourceMacAddress() {
		return sourceMacAddress;
	}

	//returns Destination Mac Address
	std::string getDestinationMacAddress() {
		return destinationMacAddress;
	}

};

//An Example of how to run this code:

//#include <iostream>
//#include "DataLinkLayer.h"

//int main()
//{
	//MacAddress Macadresses;

	//Macadresses.setSourceandDestinationMacAddress();

	//std::cout << "Source Mac Adress is " << Macadresses.getSourceMacAddress() << " \n";
	//std::cout << "Destination Mac Adress is " << Macadresses.getDestinationMacAddress() << " \n";
//}