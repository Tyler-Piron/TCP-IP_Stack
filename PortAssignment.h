#include <string>
#include <ctime>
#include <iostream>

class PortAssignment {
public:
    PortAssignment(const std::string& applicationLayer)
        : m_applicationLayer(applicationLayer), m_sourcePort(0), m_destPort(0)
    {
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

private:
    std::string m_applicationLayer;
    int m_sourcePort;
    int m_destPort;

    bool portsAreValid() const
    {
        return m_sourcePort != m_destPort;
    }
};


