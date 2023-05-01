#pragma once


#include <queue>
#include "ApplicationLayer.h"
#include "DataLinkLayer.h"
#include "NetworkandInternetLayer.h"
#include "TransportLayer.h"
#include "TCP_Message_Toplayer.h"
#include "StringToBinary.h"



class Buffer {
public:

	
	
	Buffer() {
		
		//creates 4 different queue types, for each type of layer class
		std::queue<ApplicationLayer> bufferApp;
		std::queue<TransportLayer> bufferTrans;
		std::queue<IPAddress> bufferNetwork;
		std::queue<MacAddress> bufferData;
	}
	// function overloaded 4 times for different type of class input
	void push(ApplicationLayer applLayer) {
		bufferApp.push(applLayer);
	}
	void push(TransportLayer transLayer) {
		bufferTrans.push(transLayer);
	}
	void push(IPAddress networkLayer) {
		bufferNetwork.push(networkLayer);
	}
	void push(MacAddress macLayer) {
		bufferData.push(macLayer);
	}

	//4 separate pop functions 
	//// specifically made as separate functions due to the nature of popping not taking any parameters normally
	//// it was possible to create an overloaded function w/parameters taken, but decided against this design
	
	void popApp() {
		bufferApp.pop();
	}
	void popTrans() {
		bufferTrans.pop();
	}
	void popNetwork() {
		bufferNetwork.pop();
	}
	void popMac() {
		bufferData.pop();
	}

	
	// 4 different front functions due to different return data types and a similar reason to the pop function
	ApplicationLayer frontApp() {
		if (bufferApp.empty() == false){
			return bufferApp.front();
		}
		else {
			cout << "Error! Application buffer is empty!! ";
		}
	}
	TransportLayer frontTrans() {
		if (bufferTrans.empty() == false) {
			return bufferTrans.front();
		}
		else {
			cout << "Error! Transport layer is empty!! ";
		}
	}
	IPAddress frontNetwork() {
		if (bufferNetwork.empty() == false) {
			return bufferNetwork.front();
		}
		else {
			cout << "Error! Network layer is empty!! ";
		}
	}
	MacAddress frontData() {
		if (bufferData.empty() == false) {
			return bufferData.front();
		}
		else {
			cout << "Error! Data layer queue is empty!! ";
		}
	}

private:

	std::queue<ApplicationLayer> bufferApp;
	std::queue<TransportLayer> bufferTrans;
	std::queue<IPAddress> bufferNetwork;
	std::queue<MacAddress> bufferData;






};
