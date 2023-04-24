
#include "ApplicationLayer.h"
#include "DataLinkLayer.h"
#include "NetworkandInternetLayer.h"
#include "TransportLayer.h"
#include <stack>
#include <queue>
#include "TCP_Message_Toplayer.h"
#include "StringToBinary.h"




int main() {
	
	//std::stack<std::string> TCPIPStack;
	
	std::queue<TCP_Message_TopLayer> TCPQueue;

	ApplicationLayer testingLayer{};
	testingLayer.setHeader();
	testingLayer.setRequestLine();
	TCPQueue.push(testingLayer);
	


	TransportLayer testingTransport(testingLayer);
	TCPQueue.pop();
	TCPQueue.push(testingTransport);

	IPAddress networkLayer(testingTransport);
	TCPQueue.pop();
	TCPQueue.push(networkLayer);
	
	MacAddress dataLinkLayer(networkLayer);
	TCPQueue.pop();
	TCPQueue.push(dataLinkLayer);

	dataLinkLayer.displayFrameFormat();

	//IPAddress IPadresses;
	//MacAddress Macadresses;
	//std::string conversionString;

	
	//testingLayer.httpHeader.readFile();
	//TCPIPStack.push(testingLayer.httpHeader.getApplicationLayer());
	//PortAssignment myPortAssignment(testingLayer.httpHeader.getApplicationLayer());
	//myPortAssignment.assignPorts();
	//TCPIPStack.push(myPortAssignment.getComboPorts());
	//IPadresses.setSourceandDestinationIP();
	//TCPIPStack.push(IPadresses.getComboIPs());
	//Macadresses.setSourceandDestinationMacAddress();
	//TCPIPStack.push(Macadresses.getComboMacs());

	//// I could make a function for this
	//// Conversion string is the variable holding all the information in one variable format
	//while (!TCPIPStack.empty()) {
	//	//Original line I used for printing before switching to conversionString
	//	//std::cout << TCPIPStack.top() << " ";
	//	conversionString = conversionString + TCPIPStack.top() + " " + "\n";
	//	TCPIPStack.pop();
	//}
	//// Use to print the conversion string as you need for testing purposes and end result
	//std::cout <<  conversionString;


}
