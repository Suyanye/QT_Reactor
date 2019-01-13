#ifndef ABSTRACTEVENT_H
#define ABSTRACTEVENT_H

#include <QList>
#include <QTcpServer>
#include <QTcpSocket>

class AbstractEvent
{
public:

    enum EventType
    {
        NoneEvent = 0,
        ConnectEvent,
        ReadEvent,
        WriteEvent,
        CloseEvent
    };

    AbstractEvent();

    int m_eventType;

public slots:

    virtual void connectEventHandler(QTcpServer *socket);

    virtual void eventHandler(QTcpSocket *socket);



};

typedef QList<AbstractEvent> EventList;

#endif // ABSTRACTEVENT_H
