#include "abstractevent.h"

#include <QDebug>

AbstractEvent::AbstractEvent()
{
    m_eventType = NoneEvent;
}

void AbstractEvent::connectEventHandler(QTcpServer *socket)
{
    qDebug() << "AbstractEvent::connect_Event_Handler(QTcpServer *socket)";
}

void AbstractEvent::eventHandler(QTcpSocket *socket)
{
    qDebug() << "AbstractEvent::Event_Handler(QTcpSocket *socket)";
}
