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
		std::queue<ApplicationLayer> bufferApp;
		std::queue<TransportLayer> bufferTrans;
		std::queue<IPAddress> bufferNetwork;
		std::queue<MacAddress> bufferData;
	}
	
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
