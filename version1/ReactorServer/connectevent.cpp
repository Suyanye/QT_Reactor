#include "connectevent.h"

#include <QDebug>

ConnectEvent::ConnectEvent()
{

}

void ConnectEvent::connectEventHandler(QTcpServer *socket)
{
    m_clientSocket = socket->nextPendingConnection();

    if (m_clientSocket->isOpen())
    {
        signalReturnSocket(m_clientSocket);
    }
}
