
#include "ApplicationLayer.cpp"
#include "DataLinkLayer.h"
#include "NetworkandInternetLayer.h"
#include "TransportLayer.h"
#include <stack>

// String implementaion of the stack


int main() {
	
	std::stack<std::string> TCPIPStack;
	ApplicationLayer testingLayer{};
	IPAddress IPadresses;
	MacAddress Macadresses;
	std::string conversionString;

	
	testingLayer.readFile();
	TCPIPStack.push(testingLayer.getApplicationLayer());
	PortAssignment myPortAssignment(testingLayer.getApplicationLayer());
	myPortAssignment.assignPorts();
	TCPIPStack.push(myPortAssignment.getComboPorts());
	IPadresses.setSourceandDestinationIP();
	TCPIPStack.push(IPadresses.getComboIPs());
	Macadresses.setSourceandDestinationMacAddress();
	TCPIPStack.push(Macadresses.getComboMacs());

	// I could make a function for this
	// Conversion string is the variable holding all the information in one variable format
	while (!TCPIPStack.empty()) {
		//Original line I used for printing before switching to conversionString
		//std::cout << TCPIPStack.top() << " ";
		conversionString = conversionString + TCPIPStack.top() + " " + "\n";
		TCPIPStack.pop();
	}
	// Use to print the conversion string as you need for testing purposes and end result
	std::cout <<  conversionString;


}
