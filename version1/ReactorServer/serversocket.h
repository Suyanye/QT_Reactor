#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QTcpServer>

#include "connectevent.h"

class ServerSocket : public QObject
{
    Q_OBJECT

public:
    ServerSocket();
    ~ServerSocket();

    //单例模式
    static ServerSocket *Instance()
    {
        if (NULL == m_self)
        {
            m_self = new ServerSocket();
        }

        return m_self;
    }

    QTcpServer *getServerSocket();

public slots:

//    void connectClient();

signals:

    void signalNewConnection();

private:
    static ServerSocket *m_self;

    QTcpServer *m_serverSocket;
};

#endif // SERVERSOCKET_H
