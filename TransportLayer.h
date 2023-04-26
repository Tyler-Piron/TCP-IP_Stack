#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include "ApplicationLayer.h"
#include "TCP_Message_TopLayer.h"

using namespace std;

class TransportLayer : public TCP_Message_TopLayer {
public:
    TransportLayer()
        : m_sourcePort(0), m_destPort(0), m_sequenceNum(18294), m_ackNum(27432), m_dataOffset(5), m_res(0), m_flags(9), m_windowSize(4096), m_checksum(0), m_urgentPtr(0), m_optionsValue(0) {
        ApplicationLayer m_applicationLayer;

    }
    TransportLayer(ApplicationLayer appLayer)
        : m_sourcePort(0), m_destPort(0), m_sequenceNum(18294), m_ackNum(27432), m_dataOffset(5), m_res(0), m_flags(9), m_windowSize(4096), m_checksum(0), m_urgentPtr(0), m_optionsValue(0) {
        m_applicationLayer = appLayer;

    }


    void assignPorts()
    {
        // Seed the random number generator
        std::srand(std::time(nullptr));

        // Generate random port numbers between 1025 and 65535
        m_sourcePort = std::rand() % 64511 + 1025;
        m_destPort = std::rand() % 64511 + 1025;

        // Check if the generated port numbers are the same
        while (!portsAreValid()) {
            m_sourcePort = std::rand() % 64511 + 1025;
            m_destPort = std::rand() % 64511 + 1025;
        }
    }

    void displayTransLayer() {
        m_applicationLayer.displayApplicationLayer();

        std::cout << "Source Port: " << getSourcePort() << "\n";
        std::cout << "Destination Port: " << getDestPort() << "\n";
    }

    int16_t getSourcePort() const
    {
        return m_sourcePort;
    }

    int16_t getDestPort() const
    {
        return m_destPort;
    }

    int32_t getSequenceNum() const
    {
        return m_sequenceNum;
    }

    int32_t getAckNum() const
    {
        return m_ackNum;
    }

    int4_t getDataOffset() const
    {
        return m_dataOffset;
    }

    int6_t getRes() const
    {
        return m_res;
    }

    int6_t getFlags() const
    {
        return m_flags;
    }

    int16_t getWindowSize() const
    {
        return m_windowSize;
    }

    int16_t getChecksum() const
    {
        return m_checksum;
    }

    int32_t getUrgentPtr() const
    {
        return m_urgentPtr;
    }

    int32_t getOptionsValue() const
    {
        return m_optionsValue;
    }

    ApplicationLayer getAppLayer() {
        return m_applicationLayer;
    }

private:
    ApplicationLayer m_applicationLayer;
    int m_sourcePort;
    int m_destPort;
    int m_sequenceNum;
    int m_ackNum;
    int m_dataOffset;
    int m_res;
    int m_flags;
    int m_windowSize;
    int m_checksum;
    int m_urgentPtr;
    int m_optionsValue;

    bool portsAreValid() const
    {
        return m_sourcePort != m_destPort;
    }
};
