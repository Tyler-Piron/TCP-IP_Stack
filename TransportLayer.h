#pragma once
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class TransportLayer {
public:
    TransportLayer(const std::string& applicationLayer)
        : m_applicationLayer(applicationLayer), m_sourcePort(0), m_destPort(0), m_sequenceNum(18294), m_ackNum(27432), m_dataOffset(5), m_res(0), m_flags(9), m_windowSize(4096), m_checksum(0), m_urgentPtr(0), m_optionsValue(0) {
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

    int getSourcePort() const
    {
        return m_sourcePort;
    }

    int getDestPort() const
    {
        return m_destPort;
    }

    int getSequenceNum() const
    {
        return m_sequenceNum;
    }

    int getAckNum() const
    {
        return m_ackNum;
    }

    int getDataOffset() const
    {
        return m_dataOffset;
    }

    int getRes() const
    {
        return m_res;
    }

    int getFlags() const
    {
        return m_flags;
    }

    int getWindowSize() const
    {
        return m_windowSize;
    }

    int getChecksum() const
    {
        return m_checksum;
    }

    int getUrgentPtr() const
    {
        return m_urgentPtr;
    }

    int getOptionsValue() const
    {
        return m_optionsValue;
    }

private:
    std::string m_applicationLayer;
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

