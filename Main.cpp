#include "ApplicationLayer.h"
#include "DataLinkLayer.h"
#include "NetworkandInternetLayer.h"
#include "TransportLayer.h"
#include <stack>
#include <queue>
#include "TCP_Message_Toplayer.h"
#include "StringToBinary.h"
#include "Buffer.h"
#include "FileWriter.h"
#include "StringToBinary.h"



int main() {
 
	Buffer masterBuffer;
	std::string conversionString;

	ApplicationLayer testingLayer;
	testingLayer.setHeader();
	testingLayer.setRequestLine();
	masterBuffer.push(testingLayer);
	conversionString += (masterBuffer.frontApp()).getApplicationLayerString();

	TransportLayer testingTransport(masterBuffer.frontApp());
	masterBuffer.popApp();
	testingTransport.assignPorts();
	masterBuffer.push(testingTransport);
	conversionString += (masterBuffer.frontTrans()).getTransLayerString();
	
	IPAddress networkLayer(masterBuffer.frontTrans());
	networkLayer.setSourceandDestinationIP();
	masterBuffer.popTrans();
	masterBuffer.push(networkLayer);
	conversionString += (masterBuffer.frontNetwork()).getComboIPs();
	
	MacAddress dataLinkLayer(masterBuffer.frontNetwork());
	masterBuffer.popNetwork();
	masterBuffer.push(dataLinkLayer);
	dataLinkLayer.setSourceandDestinationMacAddress();
	dataLinkLayer.setFrameFormat();
	conversionString += (masterBuffer.frontData()).getDataLayerString();
	
	(masterBuffer.frontData()).displayFrameFormat();

	StringToBinary BinaryOutput{conversionString};
	FileWriter writer("TCPStringOutput.txt");
	writer.writeToFile(BinaryOutput.Convert());
	return 0;


}
