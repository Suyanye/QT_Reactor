#include "serversocket.h"


#include <QTcpSocket>

ServerSocket *ServerSocket::m_self = NULL;

ServerSocket::ServerSocket()
{
    //创建一个serverSocket监听客户端的连接
    m_serverSocket = new QTcpServer(this);

    //监听的IP和端口号
    if (!m_serverSocket->listen(QHostAddress::LocalHost, 6666))
    {
        qDebug() << m_serverSocket->errorString();
        m_serverSocket->close();
        delete m_self;
        exit(1);
    }
}

ServerSocket::~ServerSocket()
{
    m_serverSocket->close();
    m_serverSocket->deleteLater();
    delete m_self;
}


QTcpServer *ServerSocket::getServerSocket()
{
    return m_serverSocket;
}
