#ifndef CONNECTEVENT_H
#define CONNECTEVENT_H

#include "abstractevent.h"

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class ConnectEvent : public QObject, public AbstractEvent
{
    Q_OBJECT

public:
    ConnectEvent();

public slots:

    void connectEventHandler(QTcpServer *socket);

signals:

    void signalReturnSocket(QTcpSocket *socket);

private:
    QTcpSocket *m_clientSocket;
};

#endif // CONNECTEVENT_H
