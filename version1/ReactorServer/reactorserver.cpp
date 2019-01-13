#include "reactorserver.h"
#include "ui_reactorserver.h"

#include "connectevent.h"

ReactorServer::ReactorServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReactorServer)
{
    ui->setupUi(this);

    m_serverSocket = ServerSocket::Instance()->getServerSocket();

    m_readEvent = new ReadEvent();

    m_writeEvent = new WriteEvent();

    m_connectEvent = new ConnectEvent();

    m_closeEvent = new CloseEvent();

    //有连接请求
    connect(m_serverSocket, &QTcpServer::newConnection,
            this, &ReactorServer::slotNewConnection);
    connect(this, &ReactorServer::signalNewConnection,
            m_connectEvent, &ConnectEvent::connectEventHandler);
    //获取到已连接的Socket
    connect(m_connectEvent, &ConnectEvent::signalReturnSocket,
            this, &ReactorServer::slotGetSocket);

}

ReactorServer::~ReactorServer()
{
    delete ui;
}

void ReactorServer::slotNewConnection()
{
    emit signalNewConnection(m_serverSocket);
}

void ReactorServer::slotReadyRead()
{
    QTcpSocket *socket = NULL;

    foreach (socket, m_clientSocketList) {

        if (socket->isReadable())
        {
            emit signalReadyRead(socket);
        }
    }


}

void ReactorServer::slotSendData()
{

}

void ReactorServer::slotCloseSocket()
{

}

void ReactorServer::slotGetSocket(QTcpSocket *socket)
{
    m_clientSocketList.append(socket);

    connect(socket, &QTcpSocket::readyRead,
            this, &ReactorServer::slotReadyRead);
    connect(this, &ReactorServer::signalReadyRead,
            m_readEvent, &ReadEvent::eventHandler);

    connect(m_readEvent, &ReadEvent::signalSendData,
            m_writeEvent, &WriteEvent::eventHandler);


    connect(socket, &QTcpSocket::disconnected,
            socket, &QTcpSocket::deleteLater);
}
